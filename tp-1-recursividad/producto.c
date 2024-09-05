#include "tp1.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void eliminarEspaciosProducto(char* string) {
    int inicio = 0, fin = strlen(string) - 1;

    while (isspace(string[inicio])) {
        inicio++;
    }

    while (fin >= inicio && isspace(string[fin])) {
        fin--;
    }

    int i = 0;
    while (inicio <= fin) {
        string[i++] = string[inicio++];
    }
    string[i] = '\0';
}

int esNumeroValido(char* string) {
    int i = 0;

    if (string[0] == '-') {
        i = 1;
    }
    for (; i < strlen(string); i++) {
        if (!isdigit(string[i])) {
            return 0;
        }
    }

    return 1;
}

int validarNumero(char* cadena2) {
    char entrada2[50];
    int numero2;

    while (1) {
        printf("%s", cadena2);
        scanf(" %[^\n]s", entrada2);

        eliminarEspacios(entrada2);

        if (esNumeroValido(entrada2)) {
            numero2 = atoi(entrada2);
            break;
        } else {
            printf("Dato incorrecto. Ingresa de nuevo.\n");
        }
    }

    return numero2;
}

int producto(int m, int n) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (n < 0) {
        m = -m;
        n = -n;
    }

    return m + producto(m, n - 1);
}

void iniciarProducto(){
    int m = validarNumero("Ingresa el numero M: ");
    int n = validarNumero("Ingresa el numero N: ");
    printf("producto(%d, %d) = %d\n", m, n, producto(m, n));
    return;
}
