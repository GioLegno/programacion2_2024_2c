#ifndef ARBOL_BINARIO_BUSQUEDA_H_INCLUDED
#define ARBOL_BINARIO_BUSQUEDA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "tipo_elemento.h"

struct ArbolBinarioBusquedaRep;
typedef struct ArbolBinarioBusquedaRep *ArbolBinarioBusqueda;

ArbolBinarioBusqueda abb_crear();

bool abb_es_vacio(ArbolBinarioBusqueda a);

bool abb_es_lleno(ArbolBinarioBusqueda a);

NodoArbol abb_raiz(ArbolBinarioBusqueda a);

int abb_cantidad_elementos(ArbolBinarioBusqueda a);

bool abb_insertar(ArbolBinarioBusqueda a, TipoElemento te);

bool abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar);

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave);

bool abb_es_rama_nula(NodoArbol pa);

#endif // ARBOL_BINARIO_BUSQUEDA_H_INCLUDED
