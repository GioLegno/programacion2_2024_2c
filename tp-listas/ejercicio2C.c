#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tipo_elemento.h"
#include "listas.h"


Lista funcion_retorno_valores_repetidos(Lista lista1, Lista lista2) {
    TipoElemento valor_repetido;
    Lista lista_elementos_coincidentes = l_crear ();
    Iterador i_l1 = iterador(lista1);
    while(hay_siguiente(i_l1)) {
        valor_repetido = siguiente(i_l1);
        if (l_buscar(lista2, valor_repetido->clave) != NULL) {
            l_agregar(lista_elementos_coincidentes, valor_repetido);
        }
    }
    free(i_l1);
    return lista_elementos_coincidentes;
}

// Retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
void Iniciar2C(){

    int n, m;
    bool b;

    Lista L1 = l_crear();
    Lista L2 = l_crear();
    printf("\n");
    printf("Cargue dos listas para retornar una lista con todos los valores comunes entre ambas\n");
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
    printf("Valores de comunes entre Lista 2 y Lista 1\n");
    Lista L3 = funcion_retorno_valores_repetidos(L1, L2);
    l_mostrar(L3);
}
