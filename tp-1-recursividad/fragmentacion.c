#include "tp1.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void agregarValor(int valor, int lista[], int *pos) {
    if (*pos < 100) {
        lista[(*pos)++] = valor;
    }
}

int *explosionR(int n, int b, int lista[], int *pos) {
    if (n <= b) {
        agregarValor(n, lista, pos);
    } else {
        int n1 = n / b;
        int n2 = n - (n / b);
        explosionR(n1, b, lista, pos);
        explosionR(n2, b, lista, pos);
    }
    return lista;
}

int *explosion(int n, int b) {
    int *lista = calloc(100, sizeof(int));
    int pos = 0;
    return explosionR(n, b, lista, &pos);
}

void imprimirLista(int indice, int lista[], int pos) {
    if (indice < pos) {
        if (lista[indice] > 0) {
            printf("%d ", lista[indice]);
        }
        imprimirLista(indice + 1, lista, pos);
    }
}

int es_numero(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isdigit(cadena[i])) {
            return 0;
        }
    }
    return 1;
}

int validarEntrada() {
    char resultado[100];

    do {
        fgets(resultado, sizeof(resultado), stdin);

        if (resultado[strlen(resultado) - 1] == '\n') {
            resultado[strlen(resultado) - 1] = '\0';
        }

        if (!es_numero(resultado)) {
            if (resultado[0] == '-'){
                printf("El valor negativo no es un valor valido, por favor ingresa un valor positivo: ");
            }
            else{
                printf("El valor ingresado no es un numero, por favor ingresa un valor valido: ");
            }
        }
        else {
            break;
        }

    } while (1);

    int numero = atoi(resultado);

    return numero;
}


void iniciarFragmentacion()
{
    printf("Ingresa el numero para N: ");
    int n = validarEntrada();

    printf("Ingresa el numero de la bomba (B): ");
    int b = validarEntrada();

    int *resultados = explosion(n, b);

    printf("Estos son los fragmentos de la bomba: [ ");
    imprimirLista(0, resultados, 100);
    printf("]\n");

    free(resultados);
}
