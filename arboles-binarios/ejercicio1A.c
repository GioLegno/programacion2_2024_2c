#include "tp5.h"
#include "listas.h"
#include "arbol-binario.h"
#include <stdio.h>

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa, int* contador, int total);

Lista encontrarHojas(){



}

//a. Retornar una lista con todos los nodos terminales u hojas.

void Iniciar1A(){

    //crear arbol
    ArbolBinario A1 = a_crear();
    int total_nodos;

    // Solicitar al usuario la cantidad de nodos que quiere agregar
    printf("Ingrese la cantidad de nodos que desea agregar al arbol: ");
    scanf("%d", &total_nodos);

    int contador = 0;
    Cargar_SubArbol(A1, NULL, 0, &contador, total_nodos);
}

// Funcion que carga el árbol binario de forma recursiva hasta que se alcance el número de nodos
void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa, int* contador, int total) {
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;

    if (*contador >= total) return;
    b = ingresoEntero(&n);
    if (b) {
        X = te_crear(n);
        // Conectar el nuevo nodo como hijo izquierdo, derecho o establecer la raíz
        if (sa == -1) N1 = a_conectar_hi(A, N, X);
        else if (sa == 1) N1 = a_conectar_hd(A, N, X);
        else N1 = a_establecer_raiz(A, X);

        // Incrementar el contador después de agregar un nodo
        (*contador)++;

        // Cargar hijos izquierdo y derecho recursivamente
        Cargar_SubArbol(A, N1, -1, contador, total); // Carga el hijo izquierdo
        Cargar_SubArbol(A, N1, 1, contador, total);  // Carga el hijo derecho
    }
}
