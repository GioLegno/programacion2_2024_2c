#include "tabla_hash.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "tp6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funciones de validación
void es_dia(int *valor) {
    char dia[100];
    printf("Ingrese dia (sin ceros): ");
    fgets(dia, sizeof(dia), stdin);
    if (dia[strlen(dia) - 1] == '\n') {
        dia[strlen(dia) - 1] = '\0';
    }
    while (esflotante(dia) || sscanf(dia, "%d", valor) != 1 || *valor < 1 || *valor > 31) {
        printf("Entrada no valida. Por favor ingrese un dia valido en formato DD: ");
        fgets(dia, sizeof(dia), stdin);
    }
}

void es_mes(int *valor) {
    char mes[100];
    printf("Ingrese mes (sin ceros): ");
    fgets(mes, sizeof(mes), stdin);
    if (mes[strlen(mes) - 1] == '\n') {
        mes[strlen(mes) - 1] = '\0';
    }
    while (esflotante(mes) || sscanf(mes, "%d", valor) != 1 || *valor < 1 || *valor > 12) {
        printf("Entrada no valida. Por favor ingrese un mes valido en formato MM: ");
        fgets(mes, sizeof(mes), stdin);
    }
}

void es_anio(int *valor) {
    char anio[100];
    printf("Ingrese anio: ");
    fgets(anio, sizeof(anio), stdin);
    if (anio[strlen(anio) - 1] == '\n') {
        anio[strlen(anio) - 1] = '\0';
    }
    while (esflotante(anio) || sscanf(anio, "%d", valor) != 1 || *valor < 1900 || *valor > 2024) {
        printf("Entrada no valida. Por favor ingrese un anio valido en formato AAAA ");
        fgets(anio, sizeof(anio), stdin);
    }
}

int validacion_fecha() {
    int fecha, dia, mes, anio;
    es_dia(&dia);
    es_mes(&mes);
    es_anio(&anio);

    char str1[3], str2[3], str3[5], result[10];
    sprintf(str1, "%d", dia);
    sprintf(str2, "%d", mes);
    sprintf(str3, "%d", anio);

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);

    fecha = atoi(result);
    return fecha;
}

void validacion_dni(int *valor) {
    char dni[100];
    printf("Ingrese DNI: ");
    fgets(dni, sizeof(dni), stdin);
    if (dni[strlen(dni) - 1] == '\n') {
        dni[strlen(dni) - 1] = '\0';
    }
    while (esflotante(dni) || sscanf(dni, "%d", valor) != 1 || *valor < 1000000 || *valor > 100000000) {
        printf("Entrada no valida. Por favor ingrese un DNI valido: ");
        fgets(dni, sizeof(dni), stdin);
    }
}

// Estructuras y funciones de vacunados
typedef struct {
    int dni;
    char Nombre[30];
    char Apellido[30];
} T_Vacunados;

T_Vacunados *crearVacunado(int dni, const char* nombre, const char* apellido);
void mostrarVacunado(const T_Vacunados* vacunado);

// Funciones de hash y carga de datos
int FUN_hash(int pp) {
    return (pp % 101);
}

T_Vacunados* crearVacunado(int dni, const char* nombre, const char* apellido)
{
    // Reservar memoria para un nuevo T_Vacunados
    T_Vacunados* nuevoVacunado = (T_Vacunados*)malloc(sizeof(T_Vacunados));
    if (nuevoVacunado == NULL)
    {
        fprintf(stderr, "Error al reservar memoria\n");
        exit(EXIT_FAILURE);
    }

    // Asignar valores a los campos del struct
    nuevoVacunado->dni = dni;
    strncpy(nuevoVacunado->Nombre, nombre, sizeof(nuevoVacunado->Nombre) - 1);
    nuevoVacunado->Nombre[sizeof(nuevoVacunado->Nombre) - 1] = '\0';
    strncpy(nuevoVacunado->Apellido, apellido, sizeof(nuevoVacunado->Apellido) - 1);
    nuevoVacunado->Apellido[sizeof(nuevoVacunado->Apellido) - 1] = '\0';

    return nuevoVacunado;
}

void mostrarVacunado(const T_Vacunados* vacunado)
{
    if (vacunado == NULL)
    {
        printf("El puntero vacunado es NULL\n");
    }
    else
    {
        printf("DNI: %d\n", vacunado->dni);
        printf("Nombre: %s\n", vacunado->Nombre);
        printf("Apellido: %s\n", vacunado->Apellido);
    }
}

void Carga_tabla(TablaHash Tabla) {
    int Fecha_cargar, cargas, i = 0, dni;
    char nombre[100], apellido[100];
    T_Vacunados Vacu;
    TipoElemento X, Elem_list;

    printf("Cuantas personas quiere cargar?: ");
    validacion_cargas(&cargas);

    while (i < cargas) {
        printf("Ingrese la fecha en la que el paciente fue vacunado (DD-MM-AAAA)\n");
        Fecha_cargar = validacion_fecha();

        printf("Ingrese DNI: ");
        validacion_dni(&dni);
        Vacu.dni = dni;

        printf("Ingrese Nombre: ");
        ingreso_nombre_y_apellido(nombre);
        strcpy(Vacu.Nombre, nombre);

        printf("Ingrese Apellido: ");
        ingreso_nombre_y_apellido(apellido);
        strcpy(Vacu.Apellido, apellido);

        X = th_recuperar(Tabla, Fecha_cargar);

        if (X == NULL) {
            Lista LIS_vacunados = l_crear();
            T_Vacunados* vacun = crearVacunado(Vacu.dni, Vacu.Nombre, Vacu.Apellido);
            Elem_list = te_crear_con_valor(0, vacun);
            l_agregar(LIS_vacunados, Elem_list);
            X = te_crear_con_valor(Fecha_cargar, LIS_vacunados);
            th_insertar(Tabla, X);
        } else {
            Lista LIS_vacunados = X->valor;
            T_Vacunados* vacun = crearVacunado(Vacu.dni, Vacu.Nombre, Vacu.Apellido);
            Elem_list = te_crear_con_valor(0, vacun);
            l_agregar(LIS_vacunados, Elem_list);
        }
        i++;
    }
}

void Busqueda_hash(TablaHash Tabla) {
    int Fecha_cargar;
    TipoElemento X;
    Lista Lista_vacunados;
    TipoElemento Elem_List;

    printf("Ingrese la fecha (DD-MM-AA) sin rayas: ");
    Fecha_cargar = validacion_fecha();

    X = th_recuperar(Tabla, Fecha_cargar);

    if (X == NULL) {
        printf("No hay pacientes cargados en esa fecha\n");
    } else {
        Lista_vacunados = X->valor;
        Iterador iter = iterador(Lista_vacunados);
        while (hay_siguiente(iter)) {
            Elem_List = siguiente(iter);
            T_Vacunados* vacun = Elem_List->valor;
            mostrarVacunado(vacun);
        }
    }
}

void validacion_flag(int *valor) {
    char flag[100];
    printf("Ingrese opcion: ");
    fgets(flag, sizeof(flag), stdin);
    if (flag[strlen(flag) - 1] == '\n') {
        flag[strlen(flag) - 1] = '\0';
    }
    while (esflotante(flag) || sscanf(flag, "%d", valor) != 1 || *valor < 0 || *valor > 2) {
        printf("Entrada no valida. Por favor ingrese una opcion valida: ");
        fgets(flag, sizeof(flag), stdin);
    }
}

void IniciarEjercicio6() {
    TablaHash Tabla = th_crear(101, FUN_hash);
    int flag_menu = 1;

    while (flag_menu != 0) {
        printf("\nMenu punto 6 \n\n");
        printf("Opciones:\n");
        printf("1 - Carga de persona vacunada\n");
        printf("2 - Encontrar vacunados por fecha\n");
        printf("0 - Salir\n");
        validacion_flag(&flag_menu);

        switch (flag_menu) {
            case 1:
                Carga_tabla(Tabla);
                break;
            case 2:
                Busqueda_hash(Tabla);
                break;
        }
    }
}




