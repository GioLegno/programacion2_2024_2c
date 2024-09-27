#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"


//Invertir el contenido de una pila sin destruir la pila original. Se debe retornar la nueva
//pila invertida y la original no se debe perder. Determinar la complejidad algorítmica
//de la solución.


Pila invertida (Pila pila){

    Pila pilainv = p_crear();
    Pila aux = p_crear();
    TipoElemento x1, x2;

    while(!p_es_vacia(pila)){
        x1= p_desapilar(pila);
        p_apilar(aux, x1);
        p_apilar(pilainv,x1);
    }

    while(!p_es_vacia(aux)){
        x2= p_desapilar(aux);
        p_apilar(pila,x2);
    }
    return pilainv;
}


void IniciarEjercicio5(){

    Pila pila = p_crear();

    int n, m;
    bool b;

    printf("Proceder con la carga de la pila 1 \n");
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

    Pila a  = invertida(pila);
    printf("Pila original: \n");
    p_mostrar(pila);
    printf("Pila invertida: \n");
    p_mostrar(a);
}
