#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"


int ContarElementosPila(Pila p1){

    int contador = 0;
    Pila temporal = p_crear();

    while(!p_es_vacia(p1)){
        TipoElemento aux = p_desapilar(p1);
        contador++;
        p_apilar(temporal, aux);
    }

    //devolver los elementos a la pila original
    while(!p_es_vacia(temporal)){
        p_apilar(p1, p_desapilar(temporal));
    }

    return contador;
}


void Iniciar2F(){

    int n;
    bool b;

    Pila Pila_1 = p_crear();

    printf("\n");
    printf("Cargue una Pila para luego ver en pantalla la cantidad de elementos cargados (max 10 elementos).\n");
    printf("\n");

    do{
        b = ingresoEntero(&n);
        if(b) p_apilar(Pila_1, te_crear(n));
    } while(b);

    //una vez sea crea la pila,se pasa como argumento a

    // -> mostrar la pila, y la cantidad de elementos
    printf("\n");
    p_mostrar(Pila_1);
    printf("\n");
    printf("Cantidad elementos: %d",ContarElementosPila(Pila_1));
    printf("\n");
}


