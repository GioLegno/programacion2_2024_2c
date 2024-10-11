#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tp4.h"

void funcion_divisores_totales_parciales(Cola cola);
Cola funcion_copia (Cola cola);

Cola funcion_copia (Cola cola) {
    Cola cola_aux = c_crear();
    Cola copia_cola = c_crear();
    while (!c_es_vacia(cola)) {
        TipoElemento elemento = c_desencolar(cola);
        c_encolar(cola_aux, elemento);
        c_encolar(copia_cola, elemento);
    }
    while (!c_es_vacia(cola_aux)) {
        TipoElemento elemento = c_desencolar(cola_aux);
        c_encolar(cola, elemento);
    }
    return copia_cola;
}

void funcion_divisores_totales_parciales(Cola cola) {
    int contador_de_divisiones = 0;
    float cant_elementos = 0;

    Cola cola_totales = c_crear();
    Cola cola_parciales = c_crear();
    Cola copia_cola = funcion_copia(cola);
    Cola cola_aux = c_crear();

    while (!c_es_vacia(copia_cola)) {
        TipoElemento elemento_divisor = c_desencolar(copia_cola);

        while (!c_es_vacia(cola)){

            TipoElemento elemento_a_dividir = c_desencolar(cola);
            if (elemento_a_dividir->clave % elemento_divisor->clave == 0) {
                contador_de_divisiones += 1;
            }
            cant_elementos += 1;
            c_encolar(cola_aux, elemento_a_dividir);
        }

        if (contador_de_divisiones == cant_elementos) {
            c_encolar(cola_totales, elemento_divisor);

        } else if (contador_de_divisiones >= cant_elementos / 2) {
            c_encolar(cola_parciales, elemento_divisor);
        }

        cant_elementos = 0;
        contador_de_divisiones = 0;

        while (!c_es_vacia(cola_aux)) {
            TipoElemento elemento = c_desencolar(cola_aux);
            c_encolar(cola, elemento);
        }
    }

    printf("Numeros que dividen al menos el 50 de la cola\n");
    c_mostrar(cola_parciales);
    printf("\n");
    printf("Numeros que dividen a todos los numeros de la cola\n");
    c_mostrar(cola_totales);
}

void IniciarEjercicio5(){

    Cola c1 = c_crear();

    printf("\n");
    printf("Dada una cola de valores enteros no repetidos, mayores o iguales a 2 (MAX 10). Visualizara todos los valores que son divisores totales o parciales\n");

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

    funcion_divisores_totales_parciales(c1);
}




