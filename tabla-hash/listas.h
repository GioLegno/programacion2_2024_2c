#ifndef LISTAS_H
#define LISTAS_H

#include <stdbool.h>
#include "tipo_elemento.h"

struct ListaRep;
typedef struct ListaRep *Lista;

struct IteradorRep;
typedef struct IteradorRep *Iterador;

Lista l_crear();

bool l_es_vacia(Lista lista);

bool l_es_llena(Lista lista);

int l_longitud(Lista lista);

bool l_agregar(Lista lista, TipoElemento elemento);

bool l_borrar(Lista lista, int clave);

TipoElemento l_buscar(Lista lista, int clave);

bool l_insertar(Lista lista, TipoElemento elemento, int pos);

bool l_eliminar(Lista lista, int pos);

TipoElemento l_recuperar(Lista lista, int pos);

void l_mostrar(Lista lista);

// Funciones de iterador de la lista
Iterador iterador(Lista lista);

bool hay_siguiente(Iterador iterador);

TipoElemento siguiente(Iterador iterador);

#endif // LISTAS_H
