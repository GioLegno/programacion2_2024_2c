#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "tp4.h"

bool estaEnCola(Cola cola, int elemento) {
    TipoElemento x;
    bool encontrado = false;
    Cola colaux = c_crear();


    while (!c_es_vacia(cola)) {
        x = c_desencolar(cola);
        if (x->clave == elemento) {
            encontrado = true;
        }
        c_encolar(colaux, x);
    }

    while (!c_es_vacia(colaux)) {
        c_encolar(cola, c_desencolar(colaux));
    }

    return encontrado;
}


void Iniciar2A(){

    Cola c = c_crear();

    printf("\n");
    printf("Cargar una cola (MAX 10) y un elemento a buscar. Visualizara si el elemento se encuentra o no\n");
    printf("\n");

    bool b;
    int n;
    int cant_validos = 0;
    do{
        b = ingresoEntero(&n);

        if (b){
            c_encolar(c, te_crear(n));
            cant_validos++;
        }

    } while (b && cant_validos < 10);

    printf("Cargar el elemento a buscar\n");
    int num_buscar = ingresoUnSoloEntero();


    bool resultado = estaEnCola(c, num_buscar);

    if(resultado){
        printf("El elemento esta en la cola!");
    } else printf("No esta en la cola!");
}

