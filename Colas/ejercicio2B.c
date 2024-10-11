#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "tp4.h"

Cola colarse(Cola c, int elemento, int posicion){
    int contador = 0;
    Cola aux = c_crear();
    Cola resultado = c_crear();
    TipoElemento x;
    while (c_es_vacia(c) == false){
         x = c_desencolar(c);
        if (posicion == contador) c_encolar(resultado,te_crear(elemento));
        c_encolar(resultado,x);
        c_encolar(aux,x);
        contador++;
    }
    if(posicion > contador+1) printf("La posicion esta fuera de rango!!\n");
    if(posicion == contador) c_encolar(resultado,te_crear(elemento));

    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }

    return resultado;
}

void Iniciar2B(){
    Cola c = c_crear();
    int elem_a_colar,posicion;

    printf("\n");
    printf("Cargar una cola (MAX 10) y un elemento en una posicion dada (colarse)\n");
    printf("\n");

    bool b;
    int n;
    int cant_validos = 0;
    do{
        b = ingresoEntero(&n);

        if (b){
            c_encolar(c, te_crear(n));
            cant_validos++;
        }

    } while (b && cant_validos < 10);

    printf("Cargar el elemento a colar(entero)\n");
    elem_a_colar = ingresoUnSoloEntero();

    printf("Ingrese la posicion (entero positivo)\n");
    posicion = ingresoUnSoloEntero();

    Cola resultado = colarse(c,elem_a_colar,posicion);
    c_mostrar(resultado);
}
