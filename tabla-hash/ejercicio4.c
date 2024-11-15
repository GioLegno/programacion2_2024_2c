#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_hash.h"
#include "tp6.h"
#include<math.h>
#include <ctype.h>

typedef struct
{
    bool Estado;
    int Legajo;
    char Nombre [30];
    char Apellido[30];
    int domicilio;
    char Telefono[15];
} Alumnos;


char* int_to_char(int num){
    int i = log10(num) + 1;
    char *s = (char*)calloc(i+1, sizeof(char));

    for(i--; num != 0; i--)
    {
        s[i] = (num % 10) + '0';
        num/=10;
    }

    return s;
}


void ingresoEntero_legajo(int *valor){
    char leg[100];
    fgets(leg, sizeof(leg), stdin);
    if (leg[strlen(leg) - 1] == '\n') {
        leg[strlen(leg) - 1] = '\0';
    }
    while (esflotante(leg)|| sscanf(leg, "%d", valor) != 1||strlen(leg) != 6){
        printf("Entrada no valida. Por favor ingrese un legajo valido: ");
        fgets(leg, sizeof(leg), stdin);
        if (leg[strlen(leg) - 1] == '\n'){
        leg[strlen(leg) - 1] = '\0';
        }
    }
}

int Ultimo_ingreso()
{
    FILE* arch;

    Alumnos Alumnos_arch;

    arch = fopen("Alumnos.dat", "r+b");
    if(arch == NULL){
        Alumnos_arch.domicilio = 0;
    }else{
    fseek(arch, sizeof(Alumnos)* 1, SEEK_SET);

    fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);
    }
    fclose(arch);

    return Alumnos_arch.domicilio;
}

int Devolver_Posi(TablaHash Tabla, int Legajo){
    TipoElemento X = th_recuperar(Tabla, Legajo);;
    int Posicion;

    if (X == NULL){
        printf("El legajo no corresponde a ninguno cargado en el archivo");
        return -1;
    }
    int *posicion_int_ptr = (int *)X->valor;
    Posicion = *posicion_int_ptr;
    return Posicion;
}

int hashFunctionPorPlegamiento(int a) {
    //printf("Clave:  %d ", a);
    if (a < 100) {
        return a;
    }
    else {
        char *S = int_to_char(a);
        //printf("Clave string: %s \n", S);
        char S1[10];
        strncpy(S1,S,1);
        //printf("Clave string: %s \n", S1);

    }
    return (a % 101);
}

TablaHash Inicializar(){
    TablaHash Tabla = th_crear(100, hashFunctionPorPlegamiento);
    FILE* arch;
    Alumnos Alumnos_arch;
    TipoElemento X;
    arch = fopen("Alumnos.dat", "r+b");
    int Posi = 2;
    while (!feof(arch)){
        fseek(arch, sizeof(Alumnos)* Posi, SEEK_SET);
        fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);
        if (!feof(arch)){
            X = te_crear_con_valor(Alumnos_arch.Legajo, te_crear(Posi));
            th_insertar(Tabla, X);
            Posi++;
        }
    }
    fclose(arch);
    return Tabla;
}


void ingresoEntero_tel(char *input){
    fgets(input, 15, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    while(strspn(input,"0123456789")!= strlen(input) || esflotante(input)|| strlen(input)!=10){
        printf("Ingrese el numero de telefono valido(con cod-area): ");
        fgets(input, 15, stdin);
        if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
        }
    }
}


int Crear_Archivo_binario()
{
    FILE* arch;

    Alumnos Alumnos_arch;

    Alumnos_arch.domicilio = 2;
    Alumnos_arch.Legajo = 000000;
    strcpy(Alumnos_arch.Nombre, "Contador del programa");
    strcpy(Alumnos_arch.Apellido, "Valor no modificable");
    Alumnos_arch.Estado = true;

    arch = fopen("Alumnos.dat", "w+b");

    fseek(arch, sizeof(Alumnos)* 1, SEEK_SET);

    fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);

    printf("Se ha creado correctamente el archivo binario Alumnos.dat\n");

    fclose(arch);

    return 2;
}


void Altas(int* Lugar_de_carga)
{
    FILE* arch;

    int Posi = *Lugar_de_carga;

    Alumnos Alumnos_arch;

    arch = fopen("Alumnos.dat", "r+b");
    int flag = 1;

    if (arch == NULL)
    {
        printf("\nNo existe el archivo\n");
        flag = 0;
        return;
    }
    int cargas;
    printf("\nCuantas personas quiere cargar?: ");
    validacion_cargas(&cargas);
    int i=0;
    while (i<cargas)
    {
        printf("\nCargando alumno\n\n");

        int legajo = 0;
        printf("Ingrese legajo del alumno: ");
        ingresoEntero_legajo(&legajo);
        Alumnos_arch.Legajo = legajo;
        printf("\n");
        int validador = 2;
        while (validador < Posi)
        {
            fseek(arch, sizeof(Alumnos)* validador, SEEK_SET);
            fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

            if (legajo == Alumnos_arch.Legajo)
            {
                printf("Ingrese un legajo no repetido: ");
                ingresoEntero_legajo(&legajo);
                validador = 2;
            }else{
                validador++;
            }
        }
        Alumnos_arch.Legajo = legajo;

        printf("Ingrese domicilio del alumno: ");
        int domicilio;
        validar_domicilio(&domicilio);
        Alumnos_arch.domicilio =domicilio;
        printf("\n");

        printf("Ingrese el nombre del alumno: ");
        char nombre[30];
        ingreso_nombre_y_apellido(nombre);
        strcpy(Alumnos_arch.Nombre,nombre);
        printf("\n");

        printf("Ingrese el apellido del alumno: ");
        char apellido[30];
        ingreso_nombre_y_apellido(apellido);
        strcpy(Alumnos_arch.Apellido,apellido);
        printf("\n");

        printf("Ingrese el telefono del alumno: ");
        char tel[15];
        ingresoEntero_tel(tel);
        strcpy(Alumnos_arch.Telefono,tel);

        Alumnos_arch.Estado = true;

        fseek(arch, sizeof(Alumnos)* Posi, SEEK_SET);

        fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);
        (*Lugar_de_carga)++;
        Posi++;
        i++;
    }

    fseek(arch, sizeof(Alumnos)* 1, SEEK_SET);

    fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

    Alumnos_arch.domicilio = Posi;

    fseek(arch, sizeof(Alumnos)* 1, SEEK_SET);

    fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);

    fclose(arch);

}

void Mostrar(int Lugar_mostrar){
    FILE* arch;

    Alumnos Alumnos_arch;

    arch = fopen("Alumnos.dat", "r+b");
    int flag = 1;

    if (arch == NULL)
    {
        printf("\nNo existe el archivo\n");
    }
    else
    {
        fseek(arch, sizeof(Alumnos)* Lugar_mostrar, SEEK_SET);

        size_t result = fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

        if(result != 1){
            printf("\nNo hay datos en esta posicion\n");
        }
        else if (Alumnos_arch.Estado == false)
        {
            printf("Alumno eliminado");
        }
        else
        {
            printf("\n");
            printf("Legajo = %d", Alumnos_arch.Legajo);
            printf("\n");
            printf("Domicilio = %d", Alumnos_arch.domicilio);
            printf("\n");
            printf("Nombre = %s", Alumnos_arch.Nombre);
            printf("\n");
            printf("Apellido = %s", Alumnos_arch.Apellido);
            printf("\n");
            printf("Telefono =  %s", Alumnos_arch.Telefono);
            printf("\n");
        }
        printf("\n\n");
    }

    fclose(arch);
}


void Modificaciones(int Lugar_de_carga)
{
    FILE* arch;

    Alumnos Alumnos_arch;

    arch = fopen("Alumnos.dat", "r+b");
    int flag = 1;
    int legajo;

    if (arch == NULL)
    {
        printf("\nNo existe el archivo\n");
        flag = 0;
    }

    while (flag != 0)
    {
        fseek(arch, sizeof(Alumnos)* Lugar_de_carga, SEEK_SET);

        size_t r= fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

        if(r != 1){
            printf("\nNo hay datos en esta posicion\n");
            return;
        }
        else if(Alumnos_arch.Estado){
        printf("\nQue desea modificar?\n");
        printf("1 = legajo\n");
        printf("2 = Nombre\n");
        printf("3 = Apellido\n");
        printf("4 = domicilio\n");
        printf("5 = Telefono\n");
        printf("0 = salir\n");
        printf("Ingrese la opcion (0 - 5): ");
        validacion_flag_2(&flag);
        }else{
            flag = 0;
            printf("ERROR: Alumno no existente!!!\n");
        }
        switch (flag)
        {
            case 1:
                printf("\n");
                int legajo;
                ingresoEntero_legajo(&legajo);
                Alumnos_arch.Legajo = legajo;
                int validador = 2;
                int Posi = Ultimo_ingreso();
                while (validador < Posi)
                {
                    fseek(arch, sizeof(Alumnos)* validador, SEEK_SET);
                    fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

                    if (legajo == Alumnos_arch.Legajo)
                    {
                        printf("Ingrese un legajo no repetido: ");
                        ingresoEntero_legajo(&legajo);
                        validador = 2;
                    }else{
                        validador++;
                    }
                }
                Alumnos_arch.Legajo = legajo;
                fseek(arch, sizeof(Alumnos)* Lugar_de_carga, SEEK_SET);
                fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);

            break;
            case 2:
                printf("\n");
                printf("Ingrese el nuevo Nombre: ");
                char nombre[30];
                ingreso_nombre_y_apellido(nombre);
                strcpy(Alumnos_arch.Nombre,nombre);
                fseek(arch, sizeof(Alumnos)* Lugar_de_carga, SEEK_SET);
                fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);
            case 3:
                printf("\n");
                printf("Ingrese el nuevo Apellido: ");
                fgets(Alumnos_arch.Apellido, 30, stdin);
                char apellido[30];
                ingreso_nombre_y_apellido(apellido);
                strcpy(Alumnos_arch.Apellido,apellido);
                fseek(arch, sizeof(Alumnos)* Lugar_de_carga, SEEK_SET);
                fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);
            break;
            case 4:
                printf("\n");
                printf("Ingrese el nuevo domicilio\n");
                int domicilio;
                validar_domicilio(&domicilio);
                Alumnos_arch.domicilio =domicilio;
                fseek(arch, sizeof(Alumnos)* Lugar_de_carga, SEEK_SET);
                fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);
            break;
            case 5:
                printf("\n");
                printf("Ingrese el nuevo Telefono\n");
                char tel[15];
                ingresoEntero_tel(tel);
                strcpy(Alumnos_arch.Telefono,tel);
                fseek(arch, sizeof(Alumnos)* Lugar_de_carga, SEEK_SET);
                fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);
            break;

            default:
            break;
        }

        printf("Modificacion realizada con exito, desea continuar con los cambios en este usuario?\n");
        printf("ingrese 0 para finalizar la carga: ");
        validacion_flag_2(&flag);
    }
    fclose(arch);
}

void Bajas(int Lugar_mostrar)
{
    FILE* arch;

    Alumnos Alumnos_arch;

    arch = fopen("Alumnos.dat", "r+b");
    if (arch == NULL)
    {
        printf("\nNo existe el archivo\n");
    }
    else
    {
        fseek(arch, sizeof(Alumnos)* Lugar_mostrar, SEEK_SET);

        size_t result = fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

        if(result != 1){
            printf("\nNo hay datos en esta posicion\n");
        }else{

        fseek(arch, sizeof(Alumnos)* Lugar_mostrar, SEEK_SET);

        Alumnos_arch.Estado = false;

        fwrite(&Alumnos_arch, sizeof(Alumnos), 1, arch);

        printf("\nAlumno dado de baja con exito\n");
        }
    }

    fclose(arch);
}


void Mostrar_carga()
{
    FILE* arch;

    Alumnos Alumnos_arch;

    arch = fopen("Alumnos.dat", "r+b");
    int posicion = 2;

    if (arch == NULL)
    {
        printf("\nNo existe el archivo\n");
    }
    else
    {
        while (!feof(arch))
        {
            fseek(arch, sizeof(Alumnos)* posicion, SEEK_SET);

            fread(&Alumnos_arch, sizeof(Alumnos), 1, arch);

            if (feof(arch))
            {
                printf("posicion %d - ", posicion);
                printf("fin de cargas");
            }
            else if (Alumnos_arch.Estado == false)
            {
                printf("posicion %d - ", posicion);
                printf("Alumno eliminado");
            }
            else
            {
                printf("posicion %d - ", posicion);
                printf("Legajo = %d", Alumnos_arch.Legajo);
            }
            printf("\n");
            posicion++;
        }
    }
    fclose(arch);
}


void IniciarEjercicio4(){

    int Opcion_ingresada = 1;
    int Lugar;
    int Lugar_elegido =0;
    TablaHash tabla;
    int legajo;

    while (Opcion_ingresada != 0)
    {
        printf("\nMenu principal\n\n");
        printf("1 - Crear archivo binario 'Alumnos.dat'\n");
        printf("2 - Hacer Alta \n");
        printf("3 - Hacer Modificaciones (Pasar posicion) \n");
        printf("4 - Hacer Bajas (Pasar posicion) \n");
        printf("5 - Mostrar listado de posiciones y sus legajos \n");
        printf("6 - Mostrar Alumno (Pasar posicion) \n");
        printf("7 - Buscar legajo (Tabla Hash) \n");
        printf("0 - Salir del menu \n\n");

        validacion_opcion(&Opcion_ingresada);

        switch (Opcion_ingresada)
        {
            case 1:
                Lugar = Crear_Archivo_binario();
                printf("\n");
            break;
            case 2:
                Lugar = Ultimo_ingreso();
                if(Lugar != 0){
                printf("Ultimo ingreso: %d", Lugar);
                printf("\n");
                }
                Altas(&Lugar);
            break;
            case 3:
                Lugar = Ultimo_ingreso();
                if(Lugar != 0 ){
                    printf("\nQue posicion quiere modificar?\n");
                    validar_domicilio(&Lugar_elegido);
                    while(Lugar_elegido == 1){
                        printf("Ingrese numero distinto de uno: ");
                        validar_domicilio(&Lugar_elegido);
                    }
                }
                Modificaciones(Lugar_elegido);
                printf("\n");
            break;
            case 4:
                Lugar = Ultimo_ingreso();
                if(Lugar != 0){
                    printf("\nQue posicion quiere dar de Baja?\n");
                    validar_domicilio(&Lugar_elegido);
                    while(Lugar_elegido == 1){
                            printf("Ingrese numero distinto de uno: ");
                            validar_domicilio(&Lugar_elegido);
                        }
                }
                Bajas(Lugar_elegido);
                printf("\n");
            break;
            case 5:
                printf("\n LISTA \n");
                Mostrar_carga();
                printf("\n");
                break;
            case 6:
                Lugar = Ultimo_ingreso();
                if(Lugar != 0){
                printf("\nElija la posicion del alumno que quiere mostrar\n");
                validar_domicilio(&Lugar_elegido);
                }
                Mostrar(Lugar_elegido);
                printf("\n");
            break;
            case 7:
                Lugar = Ultimo_ingreso();
                if(Lugar != 0){
                    tabla = Inicializar();
                    th_mostrar(tabla);
                    printf("Ingrese el legajo a buscar: ");
                    ingresoEntero_legajo(&legajo);
                    int posicion = Devolver_Posi(tabla, legajo);
                    if (posicion != -1){
                        printf("La posicion del legajo %d es %d\n", legajo, posicion);
                    }
                }else{
                    printf("ERROR: No hay archivo");
                }
            break;

            default:
            break;
        }
    }
}

