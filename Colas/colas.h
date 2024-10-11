#ifndef COLAS_H
#define COLAS_H

#include <stdbool.h>
#include "tipo_elemento.h"

struct ColaRep;
typedef struct ColaRep *Cola;

Cola c_crear();

bool c_encolar(Cola cola, TipoElemento elemento);

TipoElemento c_desencolar(Cola cola);

bool c_es_vacia(Cola cola);

bool c_es_llena(Cola cola);

void c_mostrar(Cola cola);

TipoElemento c_recuperar(Cola cola);

#endif // COLAS_H
