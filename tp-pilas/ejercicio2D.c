#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"

// Función para intercambiar los valores en dos posiciones ordinales de una pila.
bool IntercambiarValores(Pila pila, int pos_ord_1, int pos_ord_2) {
    if (pos_ord_1 == pos_ord_2 || p_es_vacia(pila)) {
        return false;
    }

    Pila pilaAuxiliar = p_crear();
    TipoElemento elemento1 = NULL, elemento2 = NULL;
    int pos_actual = 1;

    while (!p_es_vacia(pila)) {
        TipoElemento elemento = p_desapilar(pila);
        if (pos_actual == pos_ord_1) {
            elemento1 = elemento;
        } else if (pos_actual == pos_ord_2) {
            elemento2 = elemento;
        }
        p_apilar(pilaAuxiliar, elemento);
        pos_actual++;
    }

    if (elemento1 == NULL || elemento2 == NULL) {
        return false;
    }

    pos_actual = pos_actual - 1;
    while (!p_es_vacia(pilaAuxiliar)) {
        TipoElemento elemento = p_desapilar(pilaAuxiliar);
        if (pos_actual == pos_ord_1) {
            p_apilar(pila, elemento2);
        } else if (pos_actual == pos_ord_2) {
            p_apilar(pila, elemento1);
        } else {
            p_apilar(pila, elemento);
        }
        pos_actual--;
    }

    return true;
}

// Función para inicializar la pila e intercambiar valores en dos posiciones.
void Iniciar2D() {
    int n;
    bool b;
    Pila pila = p_crear();

    printf("\n");
    printf("Cargue una pila y 2 posiciones ordinales para intercambiar dentro de la pila");
    printf("\n");
    printf("Proceder con la carga de la pila\n");
    do {
        b = ingresoEntero(&n);  // Asumo que esta función obtiene un entero.
        if (b) {
            TipoElemento elemento = te_crear(n);
            if (p_apilar(pila, elemento)) {
                printf("Numero %d apilado correctamente.\n", n);
            } else {
                printf("Error al apilar el numero.\n");
            }
        }
    } while (b);

    printf("\n");

    // Leer las dos posiciones ordinales.
    printf("Posicion ordinal 1: ");
    int pos_ord_1 = ingresoUnSoloEntero();
    printf("Posicion ordinal 2: ");
    int pos_ord_2 = ingresoUnSoloEntero();

    // Intercambiar los valores en las posiciones especificadas.
    if (IntercambiarValores(pila, pos_ord_1, pos_ord_2)) {
        printf("Intercambio realizado correctamente.\n");
    } else {
        printf("Error al intercambiar valores (posiciones invalidas o pila vacia).\n");
    }

    // Mostrar el contenido de la pila después del intercambio.
    printf("\nPila despues de la insercion:\n");
    p_mostrar(pila);  // Asumo que esta función imprime el contenido de la pila.
}





