#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "tp4.h"
#include <stdbool.h>

int cuenta(Cola c1){
    TipoElemento x;
    Cola aux= c_crear();
    int contador = 0;
    while(!c_es_vacia(c1)){
        x = c_desencolar(c1);
        contador ++;
        c_encolar(aux,x);

    }
    while (c_es_vacia(aux) == false){
        c_encolar(c1,c_desencolar(aux));
    }
    return contador;
}


void Iniciar2D(){

    Cola c = c_crear();

    printf("\n");
    printf("Cargar una cola (MAX 10). Visualizara la cantidad de elementos que esta tiene\n");
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

    int resultado = cuenta(c);
    printf("La cola tiene %d elementos.",resultado);

}
