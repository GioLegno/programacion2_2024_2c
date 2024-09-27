#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"

bool EliminarElemento(Pila pila, int clave){
    Pila aux = p_crear();
    bool encontrado = false;
    TipoElemento x;


    while(!p_es_vacia(pila)){
        x = p_desapilar(pila);
        if (x->clave != clave || encontrado) {
            p_apilar(aux, x);
        } else {
            encontrado = true;
        }

    }
    while (!p_es_vacia(aux)) {
        x = p_desapilar(aux);
        p_apilar(pila, x);
    }

    return encontrado;
}


void Iniciar2C(){

    int n, m;
    bool b;

    Pila p1 = p_crear();

    printf("\n");
    printf("Cargue una Pila y un elemento , una vez dado el elementos, se eliminara de la Pila la primer ocurrencia encontrada\n");
    printf("\n");

    do {
        b = ingresoEntero(&n);
        if (b) p_apilar(p1 ,te_crear(n));
    } while (b);

    printf("\n");
    p_mostrar(p1);
    printf("\n");
    printf("Cargue el elemento deseado a eliminar dentro de la pila\n");
    printf("\n");
    m = ingresoUnSoloEntero();

    EliminarElemento(p1, m);
    printf("\n");
    p_mostrar(p1);
}
