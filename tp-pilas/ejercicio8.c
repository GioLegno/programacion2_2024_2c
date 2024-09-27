#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tp3.h"

/*
    Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los
    valores (sin repetición) y la cantidad de veces que aparecen.  No debe perderse la pila
    original. El proceso recibe la pila con las repeticiones y retorna una nueva pila.
    Determinar la complejidad algorítmica de la solución.

    Ejemplo: si “P” contiene (1, 2, 1, 3, 4, 5, 2, 1, 3, 5, 5), la pila resultado del proceso será
    “PR” = (1:3, 2:2, 3:2, 4:1, 5:3).
*/

Pila OrdenarPila(Pila pila) {
    Pila pilaAux = p_crear();
    TipoElemento temporal;

    // Pasar todos los elementos de la pila original a la pila auxiliar
    while (!p_es_vacia(pila)) {
        temporal = p_desapilar(pila);

        // Mientras la pila auxiliar no este vacía y el tope sea mayor que la clave de temporal
        while (!p_es_vacia(pilaAux) && p_tope(pilaAux)->clave > temporal->clave) {
            p_apilar(pila, p_desapilar(pilaAux));
        }

        // Coloca el elemento en la pila auxiliar
        p_apilar(pilaAux, temporal);
    }

    // Mueve todos los elementos de la pila auxiliar de vuelta a la pila original
    while (!p_es_vacia(pilaAux)) {
        p_apilar(pila, p_desapilar(pilaAux));
    }

    return pila;
}

void EncontrarValoresRepetidos(Pila pila) {
    // Llama a OrdenarPila para devolver una pila ordenada
    Pila pilaOrdenada = OrdenarPila(pila);

    // Pila para almacenar los resultados
    Pila pilaResultado = p_crear();
    int contador = 1;
    TipoElemento actual, anterior;

    if (p_es_vacia(pilaOrdenada)) {
        return;
    }

    // Desapilar el primer elemento para guardarlo como anterior
    anterior = p_desapilar(pilaOrdenada);

    while (!p_es_vacia(pilaOrdenada)) {
        actual = p_desapilar(pilaOrdenada);

        // Comparar el actual con el anterior
        if (actual->clave == anterior->clave) {
            // Si es igual, incrementar el contador
            contador++;
        } else {
            // Caso contrario, apilar anterior y el resultado de contador en la pila resultado
            printf("%d: %d\n", anterior->clave, contador);
            int* contadorPtr = (int*)malloc(sizeof(int)); // Asigna memoria para el contador
            *contadorPtr = contador;
            p_apilar(pilaResultado, te_crear_con_valor(anterior->clave, contadorPtr));
            // una vez se crea un elemento con una clave y valor, se resetea el contador a 1 (valor inicial)
            contador = 1;
        }
        // Actualizar el valor de anterior
        anterior = actual;
    }

    printf("%d: %d\n", anterior->clave, contador);
}

void IniciarEjercicio8() {
    int n;
    bool b;

    Pila pila = p_crear();

    // Carga de la pila
    printf("\nCargar una pila con valores repetidos para obtener una nueva con los valores y la cantidad de veces que se repiten\n\n");
    printf("Cargar pila: \n");
    do {
        b = ingresoEntero(&n);
        if (b) p_apilar(pila, te_crear(n));
    } while (b);

    // Una vez se carga, se muestra al usuario la pila cargada
    printf("\n");
    p_mostrar(pila);

    // Se le pasa la pila como argumento
    EncontrarValoresRepetidos(pila);
}



