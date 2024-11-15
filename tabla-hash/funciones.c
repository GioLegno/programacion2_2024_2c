#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "tp6.h"

bool esflotante(char val[]){
    int longitud = strlen(val);
    for (int i = 0; i < longitud; i++) {
        if (val[i] == ',' || val[i] == ' ' || val[i] == '.') {
            return true;
        }
    }
    return false;
}

void validar_domicilio(int *valor) {
    char input2[100];
    bool valido = false;

    while (!valido) {
        printf("Ingrese un domicilio que contenga solo numeros o letras: ");
        fgets(input2, sizeof(input2), stdin);

        valido = true;
        for (int i = 0; input2[i] != '\0' && input2[i] != '\n'; i++) {
            if (!isalnum(input2[i])) {
                valido = false;
                printf("Entrada no valida. Solo se permiten numeros y letras.\n");
                break;
        }
      }
    }
}

void validacion_cargas(int *valor){
    char flag[100];
    fgets(flag, sizeof(flag), stdin);
    if (flag[strlen(flag) - 1] == '\n') {
        flag[strlen(flag) - 1] = '\0';
    }
    while (esflotante(flag)|| sscanf(flag, "%d", valor) != 1||*valor<0){
        printf("Entrada no valida. Por favor ingrese una opcion valida: ");
        fgets(flag, sizeof(flag), stdin);
    }
}

void validacion_opcion(int *valor)
{
    char flag[100];
    printf("Ingrese opcion: ");
    fgets(flag, sizeof(flag), stdin);
    if (flag[strlen(flag) - 1] == '\n') {
        flag[strlen(flag) - 1] = '\0';
    }
    while (esflotante(flag)|| sscanf(flag, "%d", valor) != 1||*valor<0||*valor>7){
        printf("Entrada no valida. Por favor ingrese una opcion valida: ");
        fgets(flag, sizeof(flag), stdin);
    }
}

void validacion_flag_2(int *valor)
{
    char flag[100];
    printf("Ingrese opcion: ");
    fgets(flag, sizeof(flag), stdin);
    if (flag[strlen(flag) - 1] == '\n') {
        flag[strlen(flag) - 1] = '\0';
    }
    while (esflotante(flag)|| sscanf(flag, "%d", valor) != 1||*valor<0||*valor>5){
        printf("Entrada no valida. Por favor ingrese una opcion valida: ");
        fgets(flag, sizeof(flag), stdin);
    }
}

void ingreso_nombre_y_apellido(char *palabra) {
    fgets(palabra, 30, stdin);
    if (palabra[strlen(palabra) - 1] == '\n') {
        palabra[strlen(palabra) - 1] = '\0';
    }
    while ((strlen(palabra) == 0 && !isspace(*palabra)) || !isalpha(*palabra)) {
        printf("Ingresar la palabra nuevamente: ");
        fgets(palabra, 30, stdin);
        if (palabra[strlen(palabra) - 1] == '\n') {
            palabra[strlen(palabra) - 1] = '\0';
        }
    }

}



