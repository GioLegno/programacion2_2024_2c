#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tp4.h"

Cola OrdenarCola(Cola c1);
Cola BuscarNoRepetidos(Cola c1);

Cola OrdenarCola(Cola c1){

    Cola colaOrdenada = c_crear();
    Cola aux = c_crear();

    int arr[100];
    int i = 0;

    TipoElemento x1;
    while(!c_es_vacia(c1)){
        x1 = c_desencolar(c1);
        arr[i++] = x1 ->clave;
        c_encolar(aux, x1);
    }

    //
    while(!c_es_vacia(aux)){
        c_encolar(c1, c_desencolar(aux));
    }

    int temp;
    for(int k = 0; k < i - 1; k++){
        for (int j = k +1; j < i; j++){
            if(arr[k] > arr[j]){
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //volver a encolar
    for(int z = 0; z < i; z++){
        c_encolar(colaOrdenada, te_crear(arr[z]));
    }

    return colaOrdenada;
}

Cola BuscarNoRepetidos(Cola c1){
    Cola x = OrdenarCola(c1);
    Cola no_repetidos = c_crear();

    TipoElemento actual, anterior;
    int contador = 1;

    if (!c_es_vacia(x)) {
        anterior = c_desencolar(x);
    }

    while (!c_es_vacia(x)) {
        actual = c_desencolar(x);

        if (actual->clave == anterior->clave) {
            contador++;
        } else {
            // Si el contador es 1, el elemento anterior no estaba repetido
            if (contador == 1) {
                c_encolar(no_repetidos, te_crear(anterior->clave));
            }
            contador = 1;
        }
        anterior = actual;
    }

    // se verifica el ultimo elemento
    if (contador == 1) {
        c_encolar(no_repetidos, te_crear(anterior->clave));
    }

    return no_repetidos;
}


void IniciarEjercicio4(){

    Cola c1 = c_crear();

    printf("\n");
    printf("Dada una cola de numeros enteros (MAX 10), no ordenada, se desea obtener otra con todos los elementos que no se repiten\n");

    printf("\n");
    printf("Proceder con la carga de la cola\n");

    bool b;
    int n;

    int cant_validos_c1 = 0;
    do {
        b = ingresoEntero(&n);
        if (b){
          c_encolar(c1, te_crear(n));
          cant_validos_c1++;
        }
    } while (b && cant_validos_c1 < 10);


    c_mostrar(c1);

    Cola no_repetidos = BuscarNoRepetidos(c1);
    printf("resultado");
    c_mostrar(no_repetidos);
}


