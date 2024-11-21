#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

static const int TAMANIO_MAXIMO = 100;

struct ListaRep {
    TipoElemento *valores;
    int cantidad;
};typedef struct ListaRep *Lista;

struct IteradorRep {
    Lista lista;
    int posicionActual;
};typedef struct IteradorRep *Iterador;


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    // TODO hacer flexible y que la lista crezca sola
    nueva_lista->valores = calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    nueva_lista->cantidad = 0;
    return nueva_lista;
}


bool l_es_vacia(Lista lista) {
    return (lista->cantidad == 0);
}


bool l_es_llena(Lista lista) {
    return (lista->cantidad == TAMANIO_MAXIMO);
}


int l_longitud(Lista lista) {
    return lista->cantidad;
}


bool l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) {
        return false;
    }
    lista->valores[lista->cantidad] = elemento;
    lista->cantidad++;
    return true;
}


bool l_borrar(Lista lista, int clave) {
    if (l_es_vacia(lista)) {
        return false;
    }

    int pos = 0;
    bool borre = false;

    while (pos < lista->cantidad) {
        if (lista->valores[pos]->clave == clave) {
            borre = true;
            for (int i = pos; i < lista->cantidad - 1; i++) {
                lista->valores[i] = lista->valores[i + 1];
            }
            lista->cantidad--;
        } else {
            pos++;
        }
    }
    return borre;
}


TipoElemento l_buscar(Lista lista, int clave) {
    int pos = 0;
    while (pos < lista->cantidad) {
        if (lista->valores[pos]->clave == clave) {
            return lista->valores[pos];
        }
        pos++;
    }
    return NULL;
}


bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista)) {
        return false;
    }
    // Controlo que si pos > cantidad de elementos lo agrega al final
    if (pos > l_longitud(lista)) {
        l_agregar(lista, elemento);
        return false;
    }
    // Ahora si lo puede insertar
    for (int i = lista->cantidad; i >= pos && i > 0; i--) {
        lista->valores[i] = lista->valores[i - 1];
    }
    lista->valores[pos - 1] = elemento;
    lista->cantidad++;
    return true;
}


bool l_eliminar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return false;
    }
    // Ahora intento eliminar
    if (1 <= pos && pos <= l_longitud(lista)) {
        for (int i = pos - 1; i < lista->cantidad; i++) {
            lista->valores[i] = lista->valores[i + 1];
        }
        lista->cantidad--;
        return true;
    }
    else {
	return false;
    }
}


TipoElemento l_recuperar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return NULL;
    }
    return lista->valores[pos - 1];
}


void l_mostrar(Lista lista) {
    printf("Contenido de la lista: ");
    for (int i = 0; i < lista->cantidad; i++) {
        printf("%d ", lista->valores[i]->clave);
    }
    printf("\n");
}


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = 0;
    return iter;
}


bool hay_siguiente(Iterador iterador) {
    return iterador->posicionActual < iterador->lista->cantidad;
}


TipoElemento siguiente(Iterador iterador) {
    return iterador->lista->valores[iterador->posicionActual++];
}
