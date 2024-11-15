#include "tipo_elemento.h"
#include <stdlib.h>


//Se crean las estructuras en memoria

//asigna al nodos uno atras del otro
TipoElemento te_crear(int clave) {

    //se crea una nueva estructura en memoria,

    //allojar un espacio en memoria de tipo TipoElemento, de tamaño TipoElementoRep
    //retorna un tipo elemento
    TipoElemento te = (TipoElemento) malloc(sizeof (struct TipoElementoRep));
    te->clave = clave;
    te->valor = NULL;
    return te;
}

TipoElemento te_crear_con_valor(int clave, void* valor) {
    TipoElemento te = (TipoElemento) malloc(sizeof (struct TipoElementoRep));
    te->clave = clave;
    te->valor = valor;
    return te;
}
