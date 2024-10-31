#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdbool.h>
#include "tp5.h"
#include <string.h>

void funcion_recursiva_retorno_hojas (Lista lista, NodoArbol nodo);
void funcion_recursiva_claves_coincidentes(Lista lista, NodoArbol nodo, int clave, int *pos);
void funcion_recursiva_retorno_nodos_interiores (Lista lista, NodoArbol nodo, ArbolBinario arbol);
Lista funcion_retorno_hojas (ArbolBinario a, NodoArbol raiz);
Lista funcion_retorno_nodos_interiores (ArbolBinario a);
Lista funcion_clave_coincidentes (ArbolBinario a, int clave);

void cargar_arbol_binario_ej2(ArbolBinario A);
void Cargar_SubArbol_ej2(ArbolBinario A, NodoArbol N, int sa);


void Cargar_SubArbol_ej2(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if(!a_es_lleno(A)) {
        b= ingresoEntero(&n);
        if (b){
            X = te_crear(n);
            if(sa == -1) {
                N1= a_conectar_hi(A, N, X);
            }
            else if(sa==1){
                N1= a_conectar_hd(A, N, X);
            }
            else{
                N1 = a_establecer_raiz(A, X);
            }
            Cargar_SubArbol_ej2(A,N1,-1);
            Cargar_SubArbol_ej2(A,N1,1);
        }
    }
}

void cargar_arbol_binario_ej2(ArbolBinario A){
    Cargar_SubArbol_ej2(A,NULL,0);
}


/*
    2a. Retornar una lista con todos los nodos terminales u hojas.
*/

Lista funcion_retorno_hojas (ArbolBinario a, NodoArbol raiz){
    Lista lista = l_crear();
    funcion_recursiva_retorno_hojas(lista, a_raiz(a));
    return lista;
}


//funcion aux

void funcion_recursiva_retorno_hojas (Lista lista, NodoArbol nodo){
    if (nodo == NULL) {
        return;
    }

    if (n_hijoderecho(nodo) == NULL && n_hijoizquierdo(nodo) == NULL) {
        l_agregar(lista, nodo->datos);
        return;
    }


    funcion_recursiva_retorno_hojas(lista, n_hijoderecho(nodo));
    funcion_recursiva_retorno_hojas(lista, n_hijoizquierdo(nodo));
}

void Iniciar2A(){

    printf("Cargar un arbol, visualizara una lista con todos los nodos terminales\n");
    printf("\n");

    ArbolBinario A1 = a_crear();

    cargar_arbol_binario_ej2(A1);

    printf("\n");
    Lista L1  = funcion_retorno_hojas(A1, a_raiz(A1));
    l_mostrar(L1);
}




/*
    2b. Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)
*/

Lista funcion_retorno_nodos_interiores (ArbolBinario a){
    Lista lista = l_crear();
    funcion_recursiva_retorno_nodos_interiores(lista, a_raiz(a), a);
    l_mostrar(lista);
    return lista;

}
//funcion aux

void funcion_recursiva_retorno_nodos_interiores (Lista lista, NodoArbol nodo, ArbolBinario arbol){
    if (nodo == a_raiz(arbol)) {
        funcion_recursiva_retorno_nodos_interiores(lista, n_hijoderecho(nodo), arbol);
        funcion_recursiva_retorno_nodos_interiores(lista, n_hijoizquierdo(nodo), arbol);
        return;
    }

    if (nodo == NULL) {
        return;
    }

    if (n_hijoderecho(nodo) != NULL || n_hijoizquierdo(nodo) != NULL) {
        l_agregar(lista, nodo->datos);
    }
    funcion_recursiva_retorno_nodos_interiores(lista, n_hijoderecho(nodo), arbol);
    funcion_recursiva_retorno_nodos_interiores(lista, n_hijoizquierdo(nodo), arbol);
}

//funcion aux
void Iniciar2B(){

    printf("Cargar un arbol, visualizara todas los nodos que no son hojas ni raiz \n");
    printf("\n");

    ArbolBinario A1 = a_crear();

    cargar_arbol_binario_ej2(A1);

    funcion_retorno_nodos_interiores(A1);
    printf("\n");
}


/*
   2.c
        Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la
        posición de cada ocurrencia (puntero al nodo).
*/

Lista funcion_clave_coincidentes(ArbolBinario a, int clave){
    Lista lista = l_crear();
    int pos = 0;  // Inicializamos pos en 0
    funcion_recursiva_claves_coincidentes(lista, a_raiz(a), clave, &pos);
    return lista;
}

// Función auxiliar modificada para utilizar puntero en `pos`
void funcion_recursiva_claves_coincidentes(Lista lista, NodoArbol nodo, int clave, int *pos) {
    if (nodo == NULL) {
        return;
    }

    (*pos)++;  // Incrementa la posición en cada nodo visitado

    if (nodo->datos->clave == clave) {
        printf("Encontrado en la posicion: %d\n", *pos);
        l_agregar(lista, nodo->datos);
    }

    // Llamadas recursivas a los hijos derecho e izquierdo
    funcion_recursiva_claves_coincidentes(lista, n_hijoderecho(nodo), clave, pos);
    funcion_recursiva_claves_coincidentes(lista, n_hijoizquierdo(nodo), clave, pos);
}

void Iniciar2C(){

    printf("Cargar un arbol, y una clave. Visualizara la posicion de cada ocurrencia\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario_ej2(A1);

    int n;

    validar_clave_a_buscar(&n);
    printf("");
    Lista L1 = funcion_clave_coincidentes(A1, n);
    l_mostrar(L1);
    printf("\n");
}















