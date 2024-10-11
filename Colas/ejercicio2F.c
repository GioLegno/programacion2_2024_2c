#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "pilas.h"
#include "tp4.h"
#include <stdbool.h>

Cola invertir(Cola c){

    TipoElemento x;

    Cola aux = c_crear();
    Pila p = p_crear();

    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        p_apilar(p, x);
        c_encolar(aux, x);
    }

    while (c_es_vacia(aux) == false){
        c_encolar(c,c_desencolar(aux));
    }

    while (!p_es_vacia(p)){
        c_encolar(aux, p_desapilar(p));
    }

    return aux;
}

void Iniciar2F(){

    Cola c = c_crear();

    printf("\n");
    printf("Cargar una cola (MAX 10). Visualizara el contenido de la cola pero invertido\n");
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
    printf("Cola invertida\n");
    Cola resultado = invertir(c);
    c_mostrar(resultado);
}
