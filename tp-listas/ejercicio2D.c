#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tipo_elemento.h"
#include "listas.h"

float funcion_promedio(Lista lista) {
    float promedio = 0.0;
    Iterador iter = iterador(lista);
    TipoElemento x;
    int suma_total = 0;
    int contador = 0;

    while (hay_siguiente(iter)) {
        x = siguiente(iter);
        suma_total += x->clave;
        contador++;
    }

    if (contador > 0) {
        promedio = (float)suma_total / contador;
    }

    return promedio;
}

void Iniciar2D() {
    int n, m;
    bool b;

    printf("\n");
    printf("Calcule el promedio dadas dos listas.\n");
    printf("\n");
    printf("A continuacion cargue la lista numero 1 \n");

    // Creación de las listas
    Lista l1 = l_crear();
    Lista l2 = l_crear();

    // Cargar lista 1
    do {
        b = ingresoEntero(&n);
        if (b) l_agregar(l1, te_crear(n));
    } while (b);

    // Mostrar lista 1
    printf("\n");
    l_mostrar(l1);
    printf("\n");

    printf("A continuacion cargue la lista numero 2 \n");

    // Cargar lista 2
    do {
        b = ingresoEntero(&m);
        if (b) l_agregar(l2, te_crear(m));
    } while (b);

    // Mostrar lista 2
    printf("\n");
    l_mostrar(l2);
    printf("\n");

    // Mostrar promedios
    printf("Promedio de la lista 1: %.2f\n", funcion_promedio(l1));
    printf("Promedio de la lista 2: %.2f\n", funcion_promedio(l2));
}





