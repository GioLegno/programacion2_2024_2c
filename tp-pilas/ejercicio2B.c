#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"
#include <stdbool.h>
#include <stdio.h>

bool insertarEnPosicion(Pila pila, TipoElemento nuevoElemento, int posicion) {
    Pila pilaAuxiliar = p_crear();
    int contador = 0;
    TipoElemento elemento;

    while (!p_es_vacia(pila) && contador < posicion) {
        elemento = p_desapilar(pila);
        p_apilar(pilaAuxiliar, elemento);  // Mover el elemento a la pila auxiliar
        contador++;
    }
    if (contador < posicion) {
        printf("La posicion es mayor que el tamanio de la pila.\n");
        // Volver a apilar los elementos desapilados
        while (!p_es_vacia(pilaAuxiliar)) {
            elemento = p_desapilar(pilaAuxiliar);
            p_apilar(pila, elemento);
        }
        return false;
    }

    // Insertar el nuevo elemento en la posición deseada
    p_apilar(pila, nuevoElemento);

    // Volver a apilar los elementos restantes
    while (!p_es_vacia(pilaAuxiliar)) {
        elemento = p_desapilar(pilaAuxiliar);
        p_apilar(pila, elemento);
    }

    return true;
}

void Iniciar2B() {
    Pila pila = p_crear();
    int n;
    bool b;

    printf("Proceder con la carga de la pila\n");
    do {
        b = ingresoEntero(&n);
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

    printf("Ingrese una posicion para insertar en la pila : \n");
    int posicion= ingresoUnSoloEntero();

    printf("Ingrese un valor para insertar : \n");
    int valorNuevo = ingresoUnSoloEntero();

    if (insertarEnPosicion(pila, te_crear(valorNuevo), posicion)) {
        printf("\nElemento insertado correctamente en la posicion %d.\n", posicion);
    } else {
        printf("\nNo se pudo insertar el elemento en la posicion %d.\n", posicion);
    }

    printf("\nPila despues de la insercion:\n");
    p_mostrar(pila);
}
