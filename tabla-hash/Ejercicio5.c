#include "stdio.h"
#include "stdlib.h"
#include "nodo.h"
#include "arbol-avl.h"
#include "tipo_elemento.h"
#include "tabla_hash.h"
#include "listas.h"
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "tp6.h"

#define MAX_CANTIDAD_CLAVES 2000


// Funcion para validar una entrada numérica
void validar_ingreso_numerico(int *valor, const char *mensaje, bool (*condicion)(int)) {
    char input[100];
    printf("%s", mensaje);
    fgets(input, sizeof(input), stdin);
    while (esflotante(input) || sscanf(input, "%d", valor) != 1 || !condicion(*valor)) {
        printf("Entrada no válida. %s", mensaje);
        fgets(input, sizeof(input), stdin);
    }
}

// Funcion para validar si un numero es mayor que cero
bool es_mayor_que_cero(int valor) {
    return valor > 0;
}

// Funcion para validar si un valor esta dentro del rango de claves posibles
bool es_rango_valido(int valor) {
    return valor >= 1 && valor <= MAX_CANTIDAD_CLAVES;
}

// Función para validar si un valor esta dentro del rango de busqueda
bool es_rango_valido_buscar(int valor) {
    return valor >= 1 && valor <= 1000;
}

// Funcion para generar una lista de claves aleatorias dentro de un rango
Lista generar_lista_claves(int cantidad_claves, int valor_minimo, int valor_maximo) {
    Lista lista = l_crear();
    for (int i = 0; i < cantidad_claves; i++) {
        TipoElemento clave = te_crear(valor_minimo + rand() % (valor_maximo - valor_minimo + 1));
        l_agregar(lista, clave);
    }
    return lista;
}

// Funcion para verificar si un numero es primo
bool es_primo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Funcion para encontrar el siguiente primo mayor
int encontrar_primo_mayor(int clave) {
    int num = clave + 1;
    while (!es_primo(num)) {
        num++;
    }
    return num;
}

int cant_claves;

// Funcion de hash usando el próximo primo mayor
int hash_function_nro_primo(int a) {
    return a % encontrar_primo_mayor(cant_claves);
}

// Funcion para crear la tabla hash
TablaHash crear_tabla_hash(Lista lista, int cantidad) {
    TablaHash tabla = th_crear(cantidad, &hash_function_nro_primo);
    Iterador it = iterador(lista);
    while (hay_siguiente(it)) {
        TipoElemento elemento = siguiente(it);
        th_insertar(tabla, elemento);
    }
    return tabla;
}

// Funcion para cargar el arbol AVL
void cargar_arbol_AVL(ArbolAVL arbol, Iterador it_lista) {
    if (!avl_es_lleno(arbol) && hay_siguiente(it_lista)) {
        TipoElemento elemento = siguiente(it_lista);
        avl_insertar(arbol, elemento);
        cargar_arbol_AVL(arbol, it_lista);
    }
}

// Funcion para crear el arbol AVL
ArbolAVL crear_arbol_AVL(Lista lista) {
    ArbolAVL arbol = avl_crear();
    Iterador it_lista = iterador(lista);
    cargar_arbol_AVL(arbol, it_lista);
    return arbol;
}

// Funcion para medir el tiempo de busqueda en AVL
double tiempo_AVL(Iterador it, ArbolAVL arbol) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (hay_siguiente(it)) {
        int clave = siguiente(it)->clave;
        avl_buscar(arbol, clave);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Funcion para medir el tiempo de busqueda en Tabla Hash
double tiempo_hash(Iterador it, TablaHash tabla) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (hay_siguiente(it)) {
        int clave = siguiente(it)->clave;
        th_recuperar(tabla, clave);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Funcion principal para iniciar el ejercicio
void IniciarEjercicio5() {

    int veces;
    validar_ingreso_numerico(&veces, "Ingrese la cantidad de pruebas: ", es_mayor_que_cero);

    for (int i = 0; i < veces; i++) {
        printf("Prueba: %d\n", i + 1);
        int minimo, maximo;
        validar_ingreso_numerico(&minimo, "Ingrese el valor minimo para el rango: ", es_mayor_que_cero);
        validar_ingreso_numerico(&maximo, "Ingrese el valor maximo para el rango: ", es_rango_valido);

        int cantidad_claves;
        validar_ingreso_numerico(&cantidad_claves, "Ingrese la cantidad de claves: ", es_rango_valido);

        Lista lista_claves = generar_lista_claves(cantidad_claves, minimo, maximo);
        l_mostrar(lista_claves);

        ArbolAVL arbol = crear_arbol_AVL(lista_claves);
        TablaHash tabla = crear_tabla_hash(lista_claves, encontrar_primo_mayor(cantidad_claves));
        th_mostrar_solo_ocupados(tabla);

        int cantidad_buscar;
        validar_ingreso_numerico(&cantidad_buscar, "Ingrese la clave a buscar: ", es_mayor_que_cero);

        int rango_min, rango_max;
        validar_ingreso_numerico(&rango_min, "Ingrese el valor minimo para el rango de claves a buscar: ", es_rango_valido);
        validar_ingreso_numerico(&rango_max, "Ingrese el valor maximo para el rango de claves a buscar: ", es_rango_valido_buscar);

        Lista buscar = generar_lista_claves(cantidad_buscar, rango_min, rango_max);
        Iterador it_buscar = iterador(buscar);

        double tiempo_arbol = tiempo_AVL(it_buscar, arbol);
        double tiempo_tabla_hash = tiempo_hash(it_buscar, tabla);
        printf("Tiempo AVL: s%2f, Tiempo Hash: s%2f\n", tiempo_arbol, tiempo_tabla_hash);
    }

    printf("Conclusion: al buscar una clave, a comparacion de un arbol AVL, la tabla hash resulta mucho mas rapida por su busqueda de orden O(N).\n");

}
