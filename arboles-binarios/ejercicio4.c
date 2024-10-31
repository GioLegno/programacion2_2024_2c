#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdbool.h>
#include "tp5.h"
#include <string.h>

void cargar_arbol_binario(ArbolBinario A);
void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa);
void anchura(NodoArbol N, Lista lis,Cola c);
void pre_orden(NodoArbol N);
void cant_hojas_n_ario(NodoArbol N, int *cant);

void similar(NodoArbol A, NodoArbol B, bool *booleano);
bool _similares(ArbolBinario A, ArbolBinario B);

TipoElemento buscarPadre(NodoArbol N, NodoArbol P, int clave);
TipoElemento a_ej4_padre(ArbolBinario A, int clave);

void hermano(NodoArbol N, TipoElemento padre, Lista lis, int clave, bool *encontrado);
Lista a_ej4_hermanos(ArbolBinario A, int clave);

// ####################################################### //

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
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
            Cargar_SubArbol(A,N1,-1);
            Cargar_SubArbol(A,N1,1);
        }
    }
}

void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A,NULL,0);
}

/*
    4a.
        Dado un arbol n-ario, devolver en forma de lista el resultado del recorrido en
        anchura del arbol (solo las claves).
*/

void anchura(NodoArbol N, Lista lis, Cola c){

    if(N!= NULL){
        NodoArbol dr = n_hijoderecho(N);
        NodoArbol iz = n_hijoizquierdo(N);

        TipoElemento x = n_recuperar(N);
        l_agregar(lis, x);

        if(iz!=NULL){
            TipoElemento x=te_crear_con_valor(0,iz);
            c_encolar(c,x);
        }
        if(dr==NULL){
             if (!c_es_vacia(c)){
                TipoElemento volver =c_desencolar(c);
                NodoArbol recuperado=volver->valor;
                anchura(recuperado,lis, c);
            }
        }
        else{
            anchura(dr, lis,c);
        }
    }
}

void Iniciar4A(){
    //creacion del arbol
    printf("Cargar arbol n-ario, luego visualizara una lista de sus claves\n");
    printf("\n");

    ArbolBinario A1 = a_crear();

    cargar_arbol_binario(A1);

    Lista l1 = l_crear();
    Cola c1 = c_crear();

    anchura(a_raiz(A1), l1,c1);

    l_mostrar(l1);
}

/*
    4b.
        Escribir una funcion que, dado un arbol n-ario, devuelva el numero (cantidad)
        de hojas de dicho arbol.
*/
void pre_orden(NodoArbol N){
    TipoElemento x;
    if(N==NULL){
        printf(".");
    }
    else{
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

void cant_hojas_n_ario(NodoArbol N, int *cant){
    if (N != NULL){
        NodoArbol iz = n_hijoizquierdo(N);
        NodoArbol dr = n_hijoderecho(N);
        if(iz == NULL){
            (*cant)++;
        }
        cant_hojas_n_ario(iz, cant);
        cant_hojas_n_ario(dr,cant);
    }
}

void Iniciar4B() {

    int cant = 0;
    printf("Cargar arbol n-ario, visualizara la cantidad de hojas que tiene el mismo\n");
    printf("\n");

    ArbolBinario A1 = a_crear();

    cargar_arbol_binario(A1);

    cant_hojas_n_ario(a_raiz(A1), &cant);

    printf("cantidad de hojas: %d\n",cant);

    printf("Arbol en pre orden: ");
    pre_orden(a_raiz(A1));
}

/*
    4c.
        Escribir una funcion booleana que dados dos árboles generales determine si
        tienen la misma estructura, sin importar los datos del mismo (arbol similar).
*/
void similar(NodoArbol A, NodoArbol B, bool *booleano) {
    if (*booleano == false) return;

    if (A == NULL && B == NULL) return;
    if (A == NULL || B == NULL) {
        *booleano = false;
        return;
    }

    similar(n_hijoizquierdo(A), n_hijoizquierdo(B), booleano);
    similar(n_hijoderecho(A), n_hijoderecho(B), booleano);
}

bool _similares(ArbolBinario A, ArbolBinario B) {
    bool resu = true;
    similar(a_raiz(A), a_raiz(B), &resu);
    return resu;
}

void Iniciar4C() {
    printf("Cargar dos arboles, visualizara si sus estructuras son iguales\n");
    printf("\n");

    ArbolBinario A1 = a_crear(), A2 = a_crear();
    printf("Arbol 1\n");
    cargar_arbol_binario(A1);

    printf("Arbol 2\n");
    cargar_arbol_binario(A2);

    // Realizamos un recorrido en preorden para ambos árboles
    printf("\n");
    pre_orden(a_raiz(A1));
    pre_orden(a_raiz(A2));

    bool sim = _similares(A1, A2);
    printf("\n");
    printf("Los arboles %s similares\n", sim ? "son" : "no son");
    printf("----------------------------\n");
}

/*
    d.
        Retornar el padre de un nodo del arbol (tipo_elemento).
*/
TipoElemento buscarPadre(NodoArbol N, NodoArbol P, int clave) {
    if (N == NULL) return NULL;

    if (n_recuperar(N)->clave == clave) {
        return n_recuperar(P);
    }

    // Búsqueda recursiva en el subarbol izquierdo
    TipoElemento x = buscarPadre(n_hijoizquierdo(N), N, clave);
    if (x == NULL) {
        // Si no se encuentra en el izquierdo, buscar en el derecho
        x = buscarPadre(n_hijoderecho(N), N, clave);
    }
    return x;
}

TipoElemento a_ej4_padre(ArbolBinario A, int clave) {
    return buscarPadre(a_raiz(A), NULL, clave);  // P inicializa como null
}



void Iniciar4D() {

    printf("Cargar un arbol, luego dada una clave visualizara quien es el padre del nodo indicado\n");
    printf("\n");

    ArbolBinario A1 = a_crear();
    cargar_arbol_binario(A1);
    printf("----------------------------\n");
    printf("Arbol en pre orden:");
    pre_orden(a_raiz(A1));

    printf("\n");

    int n;

    validar_clave_a_buscar(&n);

    TipoElemento padre = a_ej4_padre(A1, n);


    if (padre != NULL) {
        printf("El padre de la clave %d es: %d\n", n, padre->clave);
    } else {
        printf("No se encontro el padre de la clave %d\n", n);
    }
    printf("----------------------------\n");
}


/*
    e.
        Retornar los hermanos de un nodo del arbol (lista de hermanos).
*/

void hermano(NodoArbol N,TipoElemento padre, Lista lis, int clave,bool *encontrado){
    if(!a_es_rama_nula(N)&& padre != NULL){
        TipoElemento recu = n_recuperar(N);
        NodoArbol hijo;
        if(recu == padre||*encontrado){
            if(!*encontrado){
            hijo = n_hijoizquierdo(N);
            }
            else{
                hijo = n_hijoderecho(N);
            }
            *encontrado=true;
            if(hijo != NULL){
                TipoElemento nuevo = n_recuperar(hijo);
                if(nuevo->clave != clave){
                    l_agregar(lis, nuevo);
                }
                hermano(hijo, padre, lis, clave,encontrado);
            }
        }
        else{
        hermano(n_hijoizquierdo(N), padre, lis, clave,encontrado);
        hermano(n_hijoderecho(N), padre, lis, clave,encontrado);
        }
    }
}

Lista a_ej4_hermanos(ArbolBinario A,int clave){
    Lista lis = l_crear();
    bool encontrado=false;
    TipoElemento padre = a_ej4_padre(A, clave);
    hermano(a_raiz(A), padre,lis,clave,&encontrado);
    return lis;
}

void Iniciar4E() {
    printf("Cargar un arbol, luego dada una clave visualizara quienes son los hermanos del nodo indicado\n");
    printf("\n");

    ArbolBinario A1 = a_crear();

    cargar_arbol_binario(A1);

    printf("----------------------------\n");
    printf("Arbol en pre orden:");
    pre_orden(a_raiz(A1));

    printf("\n");
    int num;
    validar_clave_a_buscar(&num);

    Lista lis = a_ej4_hermanos(A1, num);

    printf("Hermanos del nodo con clave %d\n", num);

    l_mostrar(lis);
    printf("----------------------------\n");
}



