#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbol-binario-busqueda.h"
#include "arbol-avl.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "tp5.h"

int calcularAltura(NodoArbol node) {
    if (node == NULL) return 0;
    int alturaIzquierda = calcularAltura(n_hijoizquierdo(node));
    int alturaDerecha = calcularAltura(n_hijoderecho(node));
    return (alturaIzquierda > alturaDerecha ? alturaIzquierda : alturaDerecha) + 1;
}

bool existeEnLista(Lista lista, int clave) {
    Iterador it = iterador(lista);
    while (hay_siguiente(it)) {
        TipoElemento x = siguiente(it);
        if(x->clave == clave) {
            return true;
        }
    }
    return false;
}

Lista generarListaClaves(int cantidad, int minimo, int maximo) {
    Lista lista = l_crear();
    int i = 0;
    while (i < cantidad) {
        int claveAleatoria = minimo + rand() % (maximo - minimo + 1);
        if (!existeEnLista(lista, claveAleatoria)) {
            TipoElemento elem = te_crear(claveAleatoria);
            l_agregar(lista, elem);
            i++;
        }
    }
    return lista;
}

void cargarAVL(ArbolAVL AVL, Iterador it) {
    while (hay_siguiente(it)) {
        TipoElemento x = siguiente(it);
        if (!avl_es_lleno(AVL)) {
            avl_insertar(AVL, x);
        }
    }
}

ArbolAVL crearAVLDesdeLista(Lista lista) {
    ArbolAVL AVL = avl_crear();
    Iterador it = iterador(lista);
    cargarAVL(AVL, it);
    return AVL;
}

void cargarABB(ArbolBinarioBusqueda ABB, Iterador it) {
    while (hay_siguiente(it)) {
        TipoElemento x = siguiente(it);
        if (!abb_es_lleno(ABB)) {
            abb_insertar(ABB, x);
        }
    }
}

ArbolBinarioBusqueda crearABBDesdeLista(Lista lista) {
    ArbolBinarioBusqueda ABB = abb_crear();
    Iterador it = iterador(lista);
    cargarABB(ABB, it);
    return ABB;
}

int diferenciaAlturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL) {
    int alturaABB = calcularAltura(abb_raiz(ABB));
    int alturaAVL = calcularAltura(avl_raiz(AVL));
    return alturaABB - alturaAVL;
}


Lista comparacionArboles(int repeticiones, int minimo, int maximo, int cantidadClaves) {
    Lista resultados = l_crear();

    for (int i = 0; i < repeticiones; i++) {

        Lista listaClaves = generarListaClaves(cantidadClaves, minimo, maximo);

        ArbolBinarioBusqueda ABB = crearABBDesdeLista(listaClaves);
        ArbolAVL AVL = crearAVLDesdeLista(listaClaves);

        int diferencia = diferenciaAlturas(ABB, AVL);
        TipoElemento resultado = te_crear(diferencia);
        l_agregar(resultados, resultado);


    }
    return resultados;
}

void IniciarEjercicio10() {
    printf("Dada una serie de numeros generados al azar. Visualizara una comparacion de la altura de ambos arboles (ABB y AVL).\n");
    printf("\n");

    srand((unsigned int)time(NULL));

    int repeticiones, cantidadClaves, minimo, maximo;

    printf("Ingrese el numero de repeticiones para comparar alturas\n");
    validar_clave(&repeticiones);
    printf("\n");
    printf("Ingrese el numero de claves a generar en cada repeticion\n");
    validar_clave(&cantidadClaves);
    printf("\n");
    printf("Ingrese el valor minimo de la clave\n ");
    validar_clave(&minimo);
    printf("\n");
    printf("Ingrese el valor maximo de la clave\n");
    validar_clave(&maximo);

    if (cantidadClaves > (maximo - minimo + 1)) {
        printf("Error: El rango de valores es insuficiente para generar claves unicas.\n");
    }

    Lista resultados = comparacionArboles(repeticiones, minimo, maximo, cantidadClaves);
    printf("Diferencia de alturas en cada repeticion:\n");
    l_mostrar(resultados);

    printf("\nConclusion: La diferencia de alturas muestra que el arbol AVL, al ser balanceado, mantiene una menor altura comparada con el ABB. El ABB no implementa balanceo en este codigo para simplificar el algoritmo.\n");
}
