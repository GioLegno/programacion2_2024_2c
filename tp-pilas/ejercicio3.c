#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"


bool sonIguales(Pila pila1, Pila pila2){
    Pila auxiliar = p_crear();
    TipoElemento x, y;
    bool iguales = false;

    while (!p_es_vacia(pila1)&& (!p_es_vacia(pila2))){
        x= p_desapilar(pila1);
        y =p_desapilar(pila2);
        if (x->clave == y->clave){
            iguales = true ;
        }

        p_apilar(auxiliar, x);
        p_apilar(auxiliar, y);

    }

    while(!p_es_vacia(auxiliar)){
        y = p_desapilar(auxiliar);
        p_apilar(pila2, y);
        x= p_desapilar(auxiliar);
        p_apilar(pila1,x);
    }
    return iguales;
}

void IniciarEjercicio3(){

    Pila pila1 = p_crear();
    Pila pila2 = p_crear();
    int n, m;
    bool b;

    printf("\n");
    printf("Dadas dos pilas, determinar si sus contenidos son exactamente iguales\n");
    printf("\n");

    printf("Proceder con la carga de la pila 1 \n");
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

    printf("Proceder con la carga de la pila2 \n");
    do {
        b = ingresoEntero(&n);
        if (b) {

            TipoElemento elemento = te_crear(n);
            if (p_apilar(pila2, elemento)) {
                printf("Numero %d apilado correctamente.\n", n);
            } else {
                printf("Error al apilar el numero.\n");
            }
        }
    } while (b);

    printf("\n");

    if(sonIguales(pila1,pila2)){
        printf("Las pilas son iguales\n ");
    }
    else{
        printf("Las pilas NO son iguales\n ");
    }
    printf("Pila 1: ");
    p_mostrar(pila1);
    printf("\n");
    printf("Pila 2: ");
    p_mostrar(pila2);
}
