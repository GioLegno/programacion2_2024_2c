#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tipo_elemento.h"
#include "listas.h"

Lista funcion_retorno_valores_no_repetidos_l2_l1 (Lista lista1, Lista lista2) {
    TipoElemento x1;
    Lista lista_elementos_no_coincidentes = l_crear();
    Iterador i_l1 = iterador(lista1);
    while(hay_siguiente(i_l1)){
        x1 = siguiente(i_l1);
        if (l_buscar(lista1, x1->clave) == NULL) {
            l_agregar(lista_elementos_no_coincidentes, x1);
        }
    }
    free(i_l1);
    return lista_elementos_no_coincidentes;
}

//Que retorne una lista con los valores de L2 que no están en L1.
void Iniciar2B(){

    int n, m;
    bool b;

    Lista L1 = l_crear();
    Lista L2 = l_crear();

    printf("\n");
    printf("Cargue dos listas para mostrar una con los valores de L2 que no se encuentran en L1.\n");
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
    printf("Valores de Lista 2 que no se encuentran en Lista 1\n");
    Lista L3 = funcion_retorno_valores_no_repetidos_l2_l1(L1, L2);
    l_mostrar(L3);
}
