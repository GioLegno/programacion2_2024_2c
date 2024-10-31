#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "arbol-binario.h"
#include "arbol-avl.h"
#include <stdio.h>
#include <stdbool.h>
#include "tp5.h"

//Ejercicio 9
void cambiar_arbol(ArbolAVL A, NodoArbol N){
    TipoElemento nodo;
    if(!avl_es_lleno(A) && !a_es_rama_nula(N)){
        nodo = n_recuperar(N);
        avl_insertar(A, nodo);
        cambiar_arbol(A, n_hijoizquierdo(N));
        cambiar_arbol(A, n_hijoderecho(N));
    }
}

ArbolAVL a_ej9_construiravl(ArbolBinario A){
    ArbolAVL B = avl_crear();
    NodoArbol N = a_raiz(A);
    cambiar_arbol(B, N);
    return B;
}
void altura_bin_BB_y_avl(NodoArbol N, int *altu,int alt){
    if (!a_es_rama_nula(N)){
        if(alt>*altu ){
            *altu=alt;
        }
        altura_bin_BB_y_avl(n_hijoizquierdo(N),altu,alt+1);
        altura_bin_BB_y_avl(n_hijoderecho(N),altu,alt+1);
    }
}

int altura_bin(ArbolBinario A) {
    int altu =0;
    int alt=1;
    altura_bin_BB_y_avl(a_raiz(A),&altu,alt);
    return altu;
}
int altura_avl(ArbolAVL B) {
    int altu =0;
    int alt=1;
    altura_bin_BB_y_avl(avl_raiz(B),&altu,alt);
    return altu;
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL){
    int altu_bin = altura_bin(A);
    int altu_avl = altura_avl(AVL);
    int resultado = altu_bin - altu_avl;
    return resultado;
}


void pre_orden_ej9(NodoArbol N){
    TipoElemento x;
    if(N==NULL){
        printf(".");
    }
    else{
        x =n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden_ej9(n_hijoizquierdo(N));
        pre_orden_ej9(n_hijoderecho(N));
    }
}

void in_orden_ej9(NodoArbol N){
    TipoElemento x;
    if(a_es_rama_nula(N)){
        printf(".");
    }else{
        in_orden_ej9(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden_ej9(n_hijoderecho(N));
    }
}
void Cargar_SubArbol_ej9(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;

    if(!a_es_lleno(A)) {
        b = ingresoEntero(&n);
        if (b) {
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

            Cargar_SubArbol_ej9(A,N1,-1);
            Cargar_SubArbol_ej9(A,N1,1);
        }
    }
}

void cargar_arbol_binario_ej9(ArbolBinario A){
    Cargar_SubArbol_ej9(A,NULL,0);
}

void validar_pruebas(int *pruebas){
    char input[100];
    printf("Ingrese la cantidad de pruebas que va a hacer: ");
    fgets(input, sizeof(input), stdin);
    while (esflotante3(input)|| sscanf(input, "%d", pruebas) != 1||*pruebas<=0) {
        printf("Entrada no valida. Por favor ingrese un numero entero mayor que 0: ");
        fgets(input, sizeof(input), stdin);
    }
}

void Iniciar9(){
    ArbolBinario A;
    ArbolAVL B;
    NodoArbol nodo;

    int i=0;
    int pruebas;
    validar_pruebas(&pruebas);

    while(i<pruebas){
        A = a_crear();
        B=avl_crear();
        cargar_arbol_binario_ej9(A);
        printf("Arbol binario en pre-orden:\n");
        pre_orden_ej9(a_raiz(A));

        printf("-----------------------------\n");
        B = a_ej9_construiravl(A);
        nodo = avl_raiz(B);
        printf("Arbol AVL in-orden\n");
        in_orden_ej9(nodo);

        printf("----------------------------\n");
        int resu = a_ej9_diferenciaalturas(A, B);
        printf("Diferencia de alturas: %d\n",resu);
        printf("----------------------------\n");
        i++;
    }
}
