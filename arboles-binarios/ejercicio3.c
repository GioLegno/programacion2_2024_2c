#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdbool.h>
#include "tp5.h"
#include <string.h>

// Declaración de funciones
int padre(NodoArbol raiz, int clave);
int clavepadre(ArbolBinario arbol, int clave);
void cargar_arbol_binario_ej3(ArbolBinario A);
void validar_clave_a_buscar(int *clave);

Lista funcion_nodo_hermano (NodoArbol nodo_h, ArbolBinario a);
void funcion_recursiva_nodo_hermano (NodoArbol nodo, NodoArbol nodo_h, Lista lista_hermano);

int funcion_nivel_del_nodo(NodoArbol raiz, NodoArbol nodo_buscado);
int funcion_recursiva_nivel_del_nodo(NodoArbol nodo_actual, NodoArbol nodo_buscado, int nivel);

// Cargar subarbol de ejemplo
void Cargar_SubArbol_ej3(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;

    int n;
    bool b;
    if(!a_es_lleno(A)) {
        b = ingresoEntero(&n);
        if (b){
            X = te_crear(n);
            if(sa == -1) {
                N1= a_conectar_hi(A, N, X);
            }
            else if(sa == 1){
                N1= a_conectar_hd(A, N, X);
            }
            else{
                N1 = a_establecer_raiz(A, X);
            }
            Cargar_SubArbol_ej3(A, N1, -1);
            Cargar_SubArbol_ej3(A, N1, 1);
        }
    }
}

void cargar_arbol_binario_ej3(ArbolBinario A){
    Cargar_SubArbol_ej3(A, NULL, 0);
}

/*
    3a. Indicar el nombre del nodo padre (clave).
*/

int padre(NodoArbol raiz, int clave) {
    TipoElemento x;
    int papa;
    if (raiz != NULL) {
        NodoArbol nod = n_hijoderecho(raiz);
        NodoArbol nod2 = n_hijoizquierdo(raiz);

        if (nod != NULL && n_recuperar(nod)->clave == clave) {
            x = n_recuperar(raiz);
            papa = x->clave;
            return papa;
        }
        else if (nod2 != NULL && n_recuperar(nod2)->clave == clave) {
            x = n_recuperar(raiz);
            papa = x->clave;
            return papa;
        }

        int result = padre(n_hijoizquierdo(raiz), clave);
        if (result != -1) return result;
        return padre(n_hijoderecho(raiz), clave);
    }
    return -1;
}

int clavepadre(ArbolBinario arbol, int clave){
    NodoArbol nodo = a_raiz(arbol);
    int resul = padre(nodo, clave);
    return resul;
}

void Iniciar3A(){
    printf("Cargar un arbol, visualizara el nombre (CLAVE) del nodo padre\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario_ej3(A1);

    int clave;
    validar_clave_a_buscar(&clave);

    printf("Clave: %d", clavepadre(A1, clave));
    printf("\n");
}

/*
    3b. Listar los hijos (solo las clave/s).
*/
void hijos(NodoArbol N, int clave,Lista lis){
    TipoElemento x,y;
    NodoArbol nodo,nodo2;
    if(N!=NULL){
        x =n_recuperar(N);
        if(x->clave==clave&&(nodo=n_hijoderecho(N))!=NULL){
            y=n_recuperar(nodo);
            l_agregar(lis,y);
        }
        if(x->clave==clave&&(nodo2=n_hijoizquierdo(N))!=NULL){
            y=n_recuperar(nodo2);
            l_agregar(lis,y);
        }
        hijos(n_hijoizquierdo(N),clave,lis);
        hijos(n_hijoderecho(N),clave,lis);
    }
}

Lista funcion_nodo_hijos(ArbolBinario arbol, int clave) {
    Lista lis = l_crear();
    NodoArbol nodo = a_raiz(arbol);
    hijos(nodo,clave,lis);
    return lis;
}

void Iniciar3B() {
    printf("Cargar un arbol, visualizara una lista de sus hijos\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario_ej3(A1);

    int n;
    validar_clave_a_buscar(&n);

    Lista l1 = funcion_nodo_hijos(A1, n);
    l_mostrar(l1);
    printf("\n");
}

/*
    3c. Listar el hermano (solo la clave).
*/

Lista funcion_nodo_hermano (NodoArbol nodo_h, ArbolBinario a) {
    Lista hermano = l_crear();
    funcion_recursiva_nodo_hermano(a_raiz(a), nodo_h, hermano);
    return hermano;
}

// Función auxiliar
void funcion_recursiva_nodo_hermano (NodoArbol nodo, NodoArbol nodo_h, Lista hermano) {
    if (nodo == NULL) {
        return;
    }

    if (n_hijoderecho(nodo) == nodo_h) {
        if (n_hijoizquierdo(nodo) != NULL) {
            l_agregar(hermano, n_hijoizquierdo(nodo)->datos);
        } else {
            printf("El nodo no tiene hermano\n");
        }
        return;
    } else if (n_hijoizquierdo(nodo) == nodo_h) {
        if (n_hijoderecho(nodo) != NULL) {
            l_agregar(hermano, n_hijoderecho(nodo)->datos);
        } else {
            printf("El nodo no tiene hermano\n");
        }
        return;
    }

    funcion_recursiva_nodo_hermano(n_hijoizquierdo(nodo), nodo_h, hermano);
    funcion_recursiva_nodo_hermano(n_hijoderecho(nodo), nodo_h, hermano);
}

void Iniciar3C() {
    printf("Cargar un arbol, visualizara la clave del nodo hermano\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario_ej3(A1);


    NodoArbol nodo_hijos = n_hijoizquierdo(a_raiz(A1));
    Lista L1 = funcion_nodo_hermano(nodo_hijos, A1);

    l_mostrar(L1);
    printf("\n");
}


/*
    3d. Calcular el nivel del nodo.
*/
int funcion_nivel_del_nodo(NodoArbol raiz, NodoArbol nodo_buscado) {
    return funcion_recursiva_nivel_del_nodo(raiz, nodo_buscado, 0);
}

int funcion_recursiva_nivel_del_nodo(NodoArbol nodo_actual, NodoArbol nodo_buscado, int nivel) {
    if (nodo_actual == NULL) {
        return -1;
    }

    if (nodo_actual == nodo_buscado) {
        return nivel;
    }

    int nivel_izquierdo = funcion_recursiva_nivel_del_nodo(n_hijoizquierdo(nodo_actual), nodo_buscado, nivel + 1);

    if (nivel_izquierdo != -1) {
        return nivel_izquierdo;
    }

    return funcion_recursiva_nivel_del_nodo(n_hijoderecho(nodo_actual), nodo_buscado, nivel + 1);
}

void Iniciar3D() {
    printf("Cargar un arbol, se visualizara el nivel de un nodo especificado\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario_ej3(A1);

    printf("\n");

    int n;
    validar_clave_a_buscar(&n);

    int nivel = funcion_nivel_del_nodo(a_raiz(A1), n_crear(te_crear(n)));
    printf("nivel: %d\n", nivel);

    if (nivel != -1) {
        printf("Nivel del nodo buscado: %d\n", nivel);
    } else {
        printf("El nodo especificado no se encuentra en el arbol.\n");
    }

    printf("\n");
}

/*
    3e. Calcular la altura de su rama (Altura del Subárbol)
*/
int altura_subarbol(NodoArbol nodo) {
    if (nodo == NULL) {
        return 0;
    }

    int altura_izquierda = altura_subarbol(n_hijoizquierdo(nodo));
    int altura_derecha = altura_subarbol(n_hijoderecho(nodo));

    return 1 + (altura_izquierda > altura_derecha ? altura_izquierda : altura_derecha);
}

void Iniciar3E(){
    printf("Cargar un arbol, visualizara la altura de su rama\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario_ej3(A1);

    printf("Altura: %d\n", altura_subarbol(a_raiz(A1)));
    printf("\n");
}




