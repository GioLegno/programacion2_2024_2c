#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "tp4.h"
#include <stdbool.h>

Cola CrearCopia(Cola c){

    Cola aux = c_crear();
    Cola copia = c_crear();
    TipoElemento x;

    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(aux,x);
        c_encolar(copia,x);
    }
     while (c_es_vacia(aux) == false){

        c_encolar(c,c_desencolar(aux));
    }

    return copia;
}


void Iniciar2E(){
    Cola c = c_crear();

    printf("\n");
    printf("Cargar una cola (MAX 10). Visualizara una copia de la misma \n");
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

    printf("\n");
    Cola resultado = CrearCopia(c);
    printf("La cola original es: \n");
    c_mostrar(c);

    printf("La cola copia es: \n");
    c_mostrar(resultado);

}
