#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 10;

struct ColaRep {
    TipoElemento *valores;
    unsigned int frente;
    unsigned int final;
};


Cola c_crear() {
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    // TODO hacer flexible y que la lista crezca sola
    nueva_cola->valores = calloc((TAMANIO_MAXIMO+1), sizeof(TipoElemento));
    nueva_cola->frente = 0;
    nueva_cola->final = 0;
    return nueva_cola;
}


bool c_es_llena(Cola cola) {
    return (cola->final == (TAMANIO_MAXIMO));
}


bool c_encolar(Cola cola, TipoElemento elemento) {
    if (c_es_llena(cola)) {
        return false;
    }
    cola->final++;
    cola->valores[cola->final] = elemento;
    if (c_es_vacia(cola)) {
        cola->frente = cola->final;
    }
    return true;
}


TipoElemento c_desencolar(Cola cola) {
    int i;

    if (c_es_vacia(cola)) {
        return NULL;
    }

    TipoElemento elemento = cola->valores[cola->frente];

    for (i=cola->frente; i<=(cola->final-1); ++i) {
        cola->valores[i] = cola->valores[i + 1];
    }
    cola->final--;
    // Controlo la condicion de cola vacia
    if (cola->final < cola->frente) {
        cola->frente = 0;
        cola->final = 0;
    }
    return elemento;
}


bool c_es_vacia(Cola cola) {
    return (cola->frente <= 0); 
}


void c_mostrar(Cola cola) {
    if (c_es_vacia(cola)) {
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
        X = cola->valores[cola->frente];
    }
    return X;
}


