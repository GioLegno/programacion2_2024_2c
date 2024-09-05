#include "tp1.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool divisiblePor7(int entero) {
    if (entero < 0) {
        entero = -entero;
        return divisiblePor7(entero);
    }
    int ultima_cifra, numero_sin_utlima;
    if (entero < 70) {
        return (entero % 7 == 0);
    }
    ultima_cifra = entero % 10;
    numero_sin_utlima = entero / 10;
    return divisiblePor7((numero_sin_utlima - (ultima_cifra * 2)));
}

int validarM7() {
    char input[100];
    int numero;
    bool esNumeroValido;
    int longitud, i;

    while (true) {
        printf("Ingresa el numero M: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {

            input[strcspn(input, "\n")] = '\0';

            longitud = strlen(input);
            esNumeroValido = true;


            if (longitud == 0) {
                esNumeroValido = false;
            }

            // Verifica por caract.
            for (i = 0; i < longitud; i++) {
                if (!isdigit(input[i])) {
                    if (i == 0 && input[i] == '-') {
                        continue;
                    }
                    esNumeroValido = false;
                    break;
                }
            }


            if (esNumeroValido) {
                numero = atoi(input);
                return numero;
            } else {
                printf("Dato incorrecto.\n");
            }
        }
    }
}

void iniciarDivisiblePor7(){
    int numero = validarM7();

    if (divisiblePor7(numero)) {
        printf("divisiblePor7 (%d) => verdadero\n", numero);
    } else {
        printf("divisiblePor7 (%d) => falso\n", numero);
    }
    return;
}


