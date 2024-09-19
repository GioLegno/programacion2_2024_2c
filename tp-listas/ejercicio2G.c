
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "listas.h"
#include "tipo_elemento.h"
#include "tp2.h"



void LMultiplosAux(Iterador i, Lista l2, int n ){
    if(hay_siguiente(i)){
        TipoElemento x = siguiente(i);
        l_agregar(l2, te_crear(n * x->clave));
        LMultiplosAux(i, l2, n);
    }
}

Lista ListaMultiplos(Lista l, int n ){
    Lista l2 = l_crear();
    Iterador i = iterador(l);
    LMultiplosAux(i, l2,n);
    return l2;
}


void Iniciar2G(){

    int n, m;
    bool b;

    Lista L = l_crear();
    printf("\n");
    printf("Cargue una lista y un numero x, para luego mostrar una lista con los multiplos de x .\n");
    printf("\n");
    printf("Proceder con la carga de la lista \n");
    do{
        b = ingresoEntero(&n);
        // Agrega el numero a la lista
        if(b) l_agregar(L, te_crear(n));

    }while(b);
    l_mostrar(L);
    printf("\n");
    printf("Cargue un numero entero\n");
    printf("\n");
    m = ingresoUnSoloEntero();
    printf("\n");
    Lista L2 = ListaMultiplos(L, m);
    l_mostrar(L2);
}

