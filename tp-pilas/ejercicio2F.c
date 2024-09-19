#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tipo_elemento.h"
#include "listas.h"
#include "tp2.h"


void funcion_retorno_min(Lista lista, int * posicion_ord_lista, int * valor_min_lista){
    Iterador iter_lista = iterador(lista);

    TipoElemento x;

    TipoElemento aux = siguiente(iter_lista);
    *valor_min_lista = aux->clave;
    *posicion_ord_lista = 1;

    int pos_actual = 1;

    while (hay_siguiente(iter_lista)) {
        x = siguiente(iter_lista);
        pos_actual++;
        if(aux -> clave > x->clave) {
            * valor_min_lista = x->clave;
            aux = x;
            * posicion_ord_lista = pos_actual;
        }
    }
}

void Iniciar2F(){
    int n, m;

    bool b;

    Lista L1 = l_crear();
    Lista L2 = l_crear();

    printf("\n");
    printf("Cargue dos listas para luego retornar el valor minimo de ambas y su posicion ordinal\n");
    printf("\n");

    printf("Proceder con la carga de la lista 1\n");

    do{
        b = ingresoEntero(&n);
        // Agrega el numero a la lista
        if(b) l_agregar(L1, te_crear(n));

    }while(b);

    l_mostrar(L1);

    printf("\n");
    printf("Proceder con la carga de la lista 2\n");

    do{
        b = ingresoEntero(&m);
        if(b) l_agregar(L2, te_crear(m));
    } while(b);

    l_mostrar(L2);
    printf("\n");

    //l1
    int valor_maximo_lista_l1;
    int posicion_ord_l1;

    funcion_retorno_min(L1, &posicion_ord_l1, &valor_maximo_lista_l1);
    printf("Valor minimo lista 1: %d, en la posicion ordinal %d", valor_maximo_lista_l1, posicion_ord_l1);
    printf("\n");

    //l2
    int valor_maximo_lista_l2;
    int posicion_ord_l2;
    funcion_retorno_min(L2, &posicion_ord_l2, &valor_maximo_lista_l2);
    printf("Valor minimo lista 2: %d, en la posicion ordinal %d", valor_maximo_lista_l2, posicion_ord_l2);
}

