#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "tp3.h"

Pila elementos_comunes(Pila pila1, Pila pila2) {
    Pila pila_aux_1 = p_crear();
    Pila pila_aux_2 = p_crear();
    Pila pila_elementos_comunes = p_crear();
    TipoElemento elemento_pila_1;
    TipoElemento elemento_pila_2;
    bool encontrado;

    // Funcion auxiliar para verificar si un elemento ya esta en la pila de elementos comunes.
    bool esta_en_pila(Pila pila, TipoElemento elemento) {
        Pila pila_aux = p_crear();
        TipoElemento elemento_aux;
        bool esta = false;

        while (!p_es_vacia(pila)) {
            elemento_aux = p_desapilar(pila);
            if (elemento_aux->clave == elemento->clave) {
                esta = true;
            }
            p_apilar(pila_aux, elemento_aux);
        }

        // Restaurar la pila original
        while (!p_es_vacia(pila_aux)) {
            p_apilar(pila, p_desapilar(pila_aux));
        }

        return esta;
    }

    while (!p_es_vacia(pila1)) {
        elemento_pila_1 = p_desapilar(pila1);
        p_apilar(pila_aux_1, elemento_pila_1);  // Guardar elemento en auxiliar para restaurar pila1 despues.

        encontrado = false;

        while (!p_es_vacia(pila2)) {
            elemento_pila_2 = p_desapilar(pila2);
            p_apilar(pila_aux_2, elemento_pila_2);  // Guardar elemento en auxiliar para restaurar pila2 despues.

            // Si el elemento es comun y aun no se ha encontrado en esta iteracion
            if (elemento_pila_1->clave == elemento_pila_2->clave && !encontrado) {
                // Solo apilar si el elemento no esta ya en la pila de elementos comunes
                if (!esta_en_pila(pila_elementos_comunes, elemento_pila_1)) {
                    p_apilar(pila_elementos_comunes, elemento_pila_1);
                }
                encontrado = true;
            }
        }

        // Restaurar pila2 desde pila_aux_2
        while (!p_es_vacia(pila_aux_2)) {
            elemento_pila_2 = p_desapilar(pila_aux_2);
            p_apilar(pila2, elemento_pila_2);
        }
    }

    // Restaurar pila1 desde pila_aux_1
    while (!p_es_vacia(pila_aux_1)) {
        elemento_pila_1 = p_desapilar(pila_aux_1);
        p_apilar(pila1, elemento_pila_1);
    }

    return pila_elementos_comunes;
}

Pila llenar() {
    Pila p1 = p_crear();
    int cantidad_num;
    int numero;

    // Validar la cantidad de numeros a apilar
    do {
        printf("Ingrese cantidad de numeros a apilar (n > 0): \n");
        cantidad_num = ingresoUnSoloEntero();

        // Verificar que sea un numero entero valido y positivo
        if (cantidad_num <= 0) {
            printf("Por favor, ingrese un numero entero positivo.\n");
        }

    } while (cantidad_num <= 0);
    printf("\n");
    int i = 1;

    do {
        printf("Numero %d: \n", i);
        numero = ingresoUnSoloEntero();

        if(numero >= 1){
            p_apilar(p1, te_crear(numero));
            i++;
        }

    }while(i <= cantidad_num);

    return p1;
}

void IniciarEjercicio7(){
    printf("\n");
    printf("Cargar dos pilas, finalmente se visualizaran los elementos que ambas tienen en comun.\n");
    printf("\n");

    Pila p1 = llenar();
    printf("\n");
    Pila p2 = llenar();
    printf("\n");
    printf("Pila 1: \n");
    p_mostrar(p1);

    printf("Pila 2: \n");
    p_mostrar(p2);

    Pila elem_comunes = elementos_comunes(p1,p2);
    printf("\n");
    printf("ELEMENTOS COMUNES: \n");
    p_mostrar(elem_comunes);
}
