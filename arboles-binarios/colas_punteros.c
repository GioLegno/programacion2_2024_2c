#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 10;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ColaRep {
    struct Nodo *frente;
    struct Nodo *final;
};


Cola c_crear(void) {
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    // TODO hacer flexible y que la lista crezca sola
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;
    return nueva_cola;
}


bool c_encolar(Cola cola, TipoElemento elemento) {
    if (c_es_llena(cola)) {
        return false;
    }

    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    if (c_es_vacia(cola)) {
        cola->frente = nuevo_nodo;
    } else {
        cola->final->siguiente = nuevo_nodo;
    }
    cola->final = nuevo_nodo;
    return true;
}


TipoElemento c_desencolar(Cola cola) {
    if (c_es_vacia(cola)) {
        return NULL;
    }
    struct Nodo *inicio = cola->frente;
    TipoElemento elemento = inicio->datos;
    cola->frente = inicio->siguiente;
    free(inicio);

    return elemento;
}


bool c_es_vacia(Cola cola) {
    return (cola->frente == NULL);
}


//-----------------------------------------------------------
// Rutina interna que calcula los elementos de la cola
//-----------------------------------------------------------
int longitud(Cola cola) {
    int i = 0;
    struct Nodo *N = cola->frente;
    while (N != NULL) {
        i++;
        N = N->siguiente;
    }
    return i;
}

bool c_es_llena(Cola cola) {
    return (longitud(cola) == TAMANIO_MAXIMO);
}


void c_mostrar(Cola cola) {
    if (c_es_vacia(cola)){
        printf("COLA VACIA !!! \n");
        return;
    }

    Cola Caux = c_crear();
    TipoElemento X = te_crear(0);

    printf("-------------------------------------\n");
    printf("Imprimiendo las Claves de la Cola \n");
    printf("-------------------------------------\n");

    // La cola se debe desencolar y guardar en una auxiliar
    while (c_es_vacia(cola) != true) {
        X = c_desencolar(cola);
        printf("Clave:  %d \n", X->clave);
        c_encolar(Caux, X);
    }

    // ahora paso la auxiliar a la cola de nuevo para dejarla como estaba
    while (c_es_vacia(Caux) != true) {
        X = c_desencolar(Caux);
        c_encolar(cola, X);
    }

    printf("\n");
}


TipoElemento c_recuperar(Cola cola) {
    TipoElemento X;
    if (c_es_vacia(cola)) {
        X = NULL;
    }
    else {
        X = cola->frente->datos;
    }
    return X;
}
