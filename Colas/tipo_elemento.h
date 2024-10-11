#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H


//clase abstracta
struct TipoElementoRep {
    int clave;
    void* valor;
};

// -> se define TipoElemento como un punto que usa el struct TipoElementoRep (el espacio de memoria)
typedef struct TipoElementoRep *TipoElemento;

// Se utilza TipoElementoRep (TipoElementoRep *TipoElemento)


// las funciones emplean TipoElemento que es un puntero a TipoElementoRep
TipoElemento te_crear(int clave);
TipoElemento te_crear_con_valor(int clave, void* valor);

#endif // TIPO_ELEMENTO_H

