#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tipo_elemento.h"
#include "listas.h"


Lista funcion_retorno_valores_no_repetidos_l1_l2 (Lista lista1, Lista lista2) {
    TipoElemento x1;
    Lista lista_elementos_no_coincidentes = l_crear();
    Iterador i_l1 = iterador(lista1);
    while(hay_siguiente(i_l1)){
        x1 = siguiente(i_l1);
        if (l_buscar(lista2, x1->clave) == NULL) {
            l_agregar(lista_elementos_no_coincidentes, x1);
        }
    }
    return lista_elementos_no_coincidentes;
}

void Iniciar2A(){
    int n, m;
    bool b;

    Lista L1 = l_crear();
    Lista L2 = l_crear();

    printf("\n");
    printf("Cargue dos listas para luego mostrar una con los valores de L1 que no se encuentran en L2.\n");
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
    printf("Valores de Lista 1 que no se encuentran en Lista 2\n ");
    Lista L3 = funcion_retorno_valores_no_repetidos_l1_l2(L1, L2);
    l_mostrar(L3);
}


