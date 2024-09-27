#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"

bool buscarClave(Pila pila) {
    Pila pilaAuxiliar = p_crear();
    bool encontrado = false;
    TipoElemento elemento;
    int clave;

    while (!p_es_vacia(pila)) {
        elemento = p_desapilar(pila);
        if (elemento->clave == clave) {
            encontrado = true;
        }
        p_apilar(pilaAuxiliar, elemento);
    }

    while (!p_es_vacia(pilaAuxiliar)) {
        elemento = p_desapilar(pilaAuxiliar);
        p_apilar(pila, elemento);
    }

    return encontrado;
}

void Iniciar2A() {
    int n;
    bool b;
    Pila pila1 = p_crear();

    printf("Proceder con la carga de la pila\n");
    do {
        b = ingresoEntero(&n);
        if (b) {

            TipoElemento elemento = te_crear(n);
            if (p_apilar(pila1, elemento)) {
                printf("Numero %d apilado correctamente.\n", n);
            } else {
                printf("Error al apilar el numero.\n");
            }
        }
    } while (b);

    printf("\n");

    int clave = ingresoUnSoloEntero();

    if (buscarClave(pila1)) {
        printf("El valor se encontro en la pila.\n");
    } else {
        printf("El valor no esta en la pila.\n");
    }

    p_mostrar(pila1);
}




