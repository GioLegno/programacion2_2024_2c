#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"

//Entendimos por duplicar el contenido de la pila, el realizar una segunda pila con el mismo contenido de la pila original.

Pila duplica_pilas (Pila pila) {
    Pila pila_aux = p_crear();
    Pila pila_duplicada = p_crear();
    TipoElemento elemento_pila;
    while (p_es_vacia(pila) != true) {
        elemento_pila = p_desapilar(pila);
        p_apilar(pila_duplicada, elemento_pila);
        p_apilar(pila_aux, elemento_pila);
    }
    while (p_es_vacia(pila_aux) != true) {
        elemento_pila = p_desapilar(pila_aux);
        p_apilar (pila, elemento_pila);
    }

    return pila_duplicada;
}

void Iniciar2E(){
    int n;
    bool b;

    Pila p1 = p_crear();

    printf("\n");
    printf("Cargue una Pila, una vez hecho, podra ver su contenido duplicado\n");
    printf("\n");

    do {
        b = ingresoEntero(&n);
        if (b) p_apilar(p1 ,te_crear(n));
    } while (b);

    printf("\n");
    printf("Pila inicial\n");
    p_mostrar(p1);
    printf("\n");
    printf("Pila duplicada");
    Pila p2 = duplica_pilas(p1);
    printf("\n");
    p_mostrar(p2);
}

