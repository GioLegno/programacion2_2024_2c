#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "listas.h"


void funcion_carga_aleatoria_no_repetida(Lista lista, int cant_elementos) {
    int min = -10000;
    int max = 10000;

    while (cant_elementos > 0) {
        int numero_aleatorio = min + (rand() % (max - min + 1));
        if (l_buscar(lista, numero_aleatorio) == NULL) {
            l_agregar(lista, te_crear(numero_aleatorio));
            cant_elementos -= 1;
        }
    }
}


void Iniciar2H(){

    int m;

    Lista L = l_crear();

    printf("\n");
    printf("Cargue una lista y un numero x, para luego generar una lista de x elementos aleatorios.\n");
    printf("\n");

    printf("Cargue un numero entero\n");
    m = ingresoUnSoloEntero();
    printf("\n");

    funcion_carga_aleatoria_no_repetida(L, m);

    l_mostrar(L);
}
