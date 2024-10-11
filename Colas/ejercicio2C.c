#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "tp4.h"
#include <stdbool.h>

Cola eleminar_ocurrencias(Cola c, int elemento){
    Cola aux = c_crear();
    Cola r = c_crear();
    TipoElemento x;
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        if(x->clave == elemento) {
            c_encolar(aux,x);
        } else {
            c_encolar(r,x);
            c_encolar(aux,x);
        }
    }

        //paso los valores de la cola aux a la cola c, dejando aux vacia.
    while (c_es_vacia(aux) == false){
        c_encolar(c,c_desencolar(aux));
    }

    return r;
}

void Iniciar2C(){

    Cola c = c_crear();

    printf("\n");
    printf("Cargar una cola (MAX 10) y un elemento. Visualizara si el elemento dado fue quitado de la cola. Se removera todas las veces que aparecio\n");
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

    printf("\n");
    printf("Ingrese el elemento a quitar (entero)\n");
    int elem_a_quitar = ingresoUnSoloEntero();
    printf("\n");
    Cola resultado = eleminar_ocurrencias(c,elem_a_quitar);
    c_mostrar(resultado);
}
