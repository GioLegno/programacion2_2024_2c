#include <stdio.h>
#include <stdbool.h>
#include "tp2.h"
#include "listas.h"
#include "tipo_elemento.h"

bool sublista(Lista L1, Lista L2){

    int longitud = l_longitud(L1);
    int longitud2 = l_longitud(L2);

    if (longitud < longitud2){
        printf("l2 es mayor a l1\n");
        return 0;
    }
    TipoElemento x1, x2;
    Iterador j = iterador(L2);
    bool encontrado;

    while(hay_siguiente(j)){
        x2 = siguiente(j);
        x1 = l_buscar(L1, x2->clave);

        if(x1 == NULL){
            encontrado = false;
            break;
        }
        else{
             encontrado = true;
        }
    }
    return encontrado;
}

void IniciarEjercicio6(){
    int n, m;
    bool b;

    printf("\n");
    printf("Determine si una lista es sublista de otra.\n");
    printf("\n");
    printf("A continuacion cargue la lista numero 1 \n");
    //creacion de las listas
    Lista l1 = l_crear();
    Lista l2 = l_crear();

    do{
        b = ingresoEntero(&n);
        if(b) l_agregar(l1, te_crear(n));

    }while(b);
    //mostrar lista 1
    printf("\n");
    l_mostrar(l1);
    printf("\n");
    printf("A continuacion cargue la lista numero 2 \n");
    //cargar lista 2
    do{
        b = ingresoEntero(&m);
        if(b) l_agregar(l2, te_crear(m));
    } while(b);

    printf("\n");
    l_mostrar(l2);
    printf("\n");
    //Las listas se pasan como arguemento en ComparacionListas
    if(sublista(l1, l2)){
        printf("-> La lista L2, es una sublista de L1.");
        printf("\n");
    }
    else{
        printf ("-> La lista L2, NO es una lista de L1");
        printf("\n");
    }
}
