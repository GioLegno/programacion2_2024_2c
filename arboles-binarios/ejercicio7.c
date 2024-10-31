#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdbool.h>
#include "tp5.h"
#include <string.h>

bool funcion_determina_equivalencia (ArbolBinario arbol1, ArbolBinario arbol2);
void funcion_aux_punto7 (NodoArbol nodo_arbol1, NodoArbol nodo_arbol2, bool *son_equivalentes);
void cargar_arbol_binario_ej7(ArbolBinario A);
void Cargar_Ej7_SubArbol(ArbolBinario A, NodoArbol N, int sa);

void Cargar_Ej7_SubArbol(ArbolBinario A, NodoArbol N, int sa){
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
            Cargar_Ej7_SubArbol(A,N1,-1);
            Cargar_Ej7_SubArbol(A,N1,1);
        }
    }
}

void cargar_arbol_binario_ej7(ArbolBinario A){
    Cargar_Ej7_SubArbol(A,NULL,0);
}

void funcion_aux_punto7 (NodoArbol nodo_arbol1, NodoArbol nodo_arbol2, bool *son_equivalentes){
    if (nodo_arbol1 == NULL && nodo_arbol2 == NULL || son_equivalentes == false) {
        return;
    }

    if ((nodo_arbol1 == NULL && nodo_arbol2 !=NULL) ||(nodo_arbol2 == NULL && nodo_arbol1 !=NULL) || (nodo_arbol1->datos->clave != nodo_arbol2->datos->clave)) {
        *son_equivalentes = false;
        return;
    }
    funcion_aux_punto7 (n_hijoderecho(nodo_arbol1), n_hijoderecho(nodo_arbol2), son_equivalentes);
    funcion_aux_punto7 (n_hijoizquierdo(nodo_arbol1), n_hijoizquierdo(nodo_arbol2), son_equivalentes);
}

bool funcion_determina_equivalencia(ArbolBinario arbol1, ArbolBinario arbol2) {
    if(a_raiz(arbol1) != NULL && a_raiz(arbol2) != NULL){
        bool son_equivalentes = true;
        funcion_aux_punto7 (a_raiz(arbol1), a_raiz(arbol2), &son_equivalentes);
        return son_equivalentes;
    }
    else {
        printf("No pueden compararse arboles nulos \n");
        return false;
    }
}

void IniciarEjercicio7(){

    printf("Cargue dos arboles, visualizara ambos árboles binarios son equivalentes\n");
    printf("\n");

    ArbolBinario A1 = a_crear(), A2 = a_crear();
    printf("Arbol 1\n");
    cargar_arbol_binario_ej7(A1);

    printf("Arbol 2\n");
    cargar_arbol_binario_ej7(A2);

    // Realizamos un recorrido en preorden para ambos árboles
    printf("\n");

    if(funcion_determina_equivalencia(A1, A2)){
        printf("Son equivalentes \n");
    } else {
        printf("No son equivalentes \n");
    }
}
