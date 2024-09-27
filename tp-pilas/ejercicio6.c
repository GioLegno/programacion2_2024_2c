#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"
#include <stdlib.h>

/**
Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado
ítem sin perder la pila original.  Debera retornar una nueva pila sin el ítem en
consideración.  Resolver iterativamente y recursivamente.  Determinar la complejidad
algorítmica de ambas soluciones. */

Pila EliminarElementoIterativamente(Pila pila, int clave) {
    Pila temporal = p_crear();  // Pila temporal para reconstruir la original
    Pila nueva_pila = p_crear(); // Pila para almacenar el resultado sin la clave

    // Desapilar todos los elementos de la pila original
    while (!p_es_vacia(pila)) {
        TipoElemento aux = p_desapilar(pila);  // Desapila el elemento actual

        if (aux->clave != clave) {
            p_apilar(nueva_pila, aux);  // Apila en la nueva pila si no es la clave a eliminar
        }
        p_apilar(temporal, aux);  // Guarda en la pila temporal para reconstruir la original
    }

    // Reconstruir la pila original, ya que fue vaciada en el proceso
    while (!p_es_vacia(temporal)) {
        p_apilar(pila, p_desapilar(temporal));
    }

    return nueva_pila;
}


Pila EliminarElementoRecursivo(Pila pila, int clave) {
    if (p_es_vacia(pila)) {
        return p_crear();  // Caso base: pila vacia, retorna una nueva pila vacia
    }

    // Desapilar el elemento actual
    TipoElemento aux = p_desapilar(pila);

    // Llamada recursiva para procesar el resto de la pila
    Pila nueva_pila = EliminarElementoRecursivo(pila, clave);

    // En el retorno de la recursion, decide si apilar el elemento en la nueva pila o no
    if (aux->clave != clave) {
        p_apilar(nueva_pila, aux);  // Si no es el elemento a eliminar, lo apilas en la nueva pila
    }

    // Apilar de nuevo el elemento actual en la pila original para restaurarla
    p_apilar(pila, aux);

    return nueva_pila;  // Devuelve la nueva pila sin las ocurrencias de la clave
}

void carga_aleatoria_no_repetida(Pila pila, int cant_elementos) {
    int min = -10000;
    int max = 10000;
    int bucle = 0;
    while (cant_elementos > 0) {
        int numero_aleatorio = min + (rand() % (max - min + 1));

        p_apilar(pila, te_crear(numero_aleatorio));
        cant_elementos -= 1;
    }
}


void IniciarEjercicio6() {
    int elementos_aleatorios;

    // Crear una pila vacia
    Pila pila_original = p_crear();

    printf("\nCargue una pila de forma aleatoria, luego elija un elemento a eliminar. Se eliminaran todas las ocurrencias del elemento en la pila.\n\n");

    // Pedir cantidad de elementos, con validacion
    do {
        printf("¿Cuantos elementos contendra la pila? (Max 10)\n");
        elementos_aleatorios = ingresoUnSoloEntero();
        if (elementos_aleatorios <= 0 || elementos_aleatorios > 10) {
            printf("Por favor, ingrese un numero entre 1 y 10.\n");
        }
    } while (elementos_aleatorios <= 0 || elementos_aleatorios > 10);

    // Cargar elementos aleatorios en la pila original
    carga_aleatoria_no_repetida(pila_original, elementos_aleatorios);
    printf("\nPila original:\n");
    p_mostrar(pila_original);
    printf("\n");

    // Pedir la clave a eliminar, se usara para ambos metodos
    printf("Ingrese el elemento a eliminar de la pila:\n");
    int clave = ingresoUnSoloEntero();

    // Llamada al metodo iterativo
    Pila pila_iterativa_resultado = EliminarElementoIterativamente(pila_original, clave);
    printf("\nPila despues de eliminar el elemento iterativamente:\n");
    p_mostrar(pila_iterativa_resultado);

    printf("\n");

    // Llamada al metodo recursivo
    Pila pila_recursiva_resultado = EliminarElementoRecursivo(pila_original, clave);
    printf("\nPila despues de eliminar el elemento recursivamente:\n");
    p_mostrar(pila_recursiva_resultado);

    // Mostrar la pila original para confirmar que sigue intacta
    printf("\nPila original despues de ambas eliminaciones (deberia estar intacta):\n");
    p_mostrar(pila_original);
}



