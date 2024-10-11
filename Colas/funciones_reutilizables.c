#include "tp4.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "pilas.h"

// Funcion para eliminar espacios en blanco
void eliminarEspacios(char* str) {
    char* src = str;
    char* dst = str;
    while (*src != '\0') {
        if (!isspace((unsigned char)*src)) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

bool ingresoEntero(int* n) {
    char buffer[10];  // Tama�o maximo de entrada
    bool res = true;
    int i;

    while (1) {  // Bucle para seguir pidiendo el dato hasta que sea v�lido
        printf("> Ingrese un valor numerico o ( PUNTO ' . '  para terminar ): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Eliminar el salto de l�nea si est� presente
        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Eliminar los espacios en blanco de la entrada
        eliminarEspacios(buffer);
        len = strlen(buffer);  // Actualizar la longitud despu�s de eliminar espacios

        // Verificar si el usuario desea salir
        if (buffer[0] == '.') {
            res = false;
            break;
        }

        // Comprobar si es un n�mero v�lido (incluyendo negativos)
        i = 0;
        if (buffer[0] == '-' && len > 1) {
            i = 1;  // Permitir signo negativo
        }

        int esValido = 1;  // Bandera para verificar si es valido
        for (; i < len; i++) {
            if (!isdigit(buffer[i])) {
                printf("El valor '%c' no es valido. Solo se permiten numeros enteros.\n", buffer[i]);
                esValido = 0;  // Marcar como no valido
                break;
            }
        }

        // Si el valor es v�lido, procesamos el n�mero
        if (esValido) {
            *n = atoi(buffer);
            break;  // Salir del bucle ya que se ingres� correctamente
        }
    }

    return res;
}

int ingresoUnSoloEntero(){
    int valor;
    char buffer[10];  // Tama�o maximo de entrada

    int index = 0;

    while(1){
        printf("Ingresar numero: ");
        fgets(buffer, sizeof(buffer), stdin);

        for(int i = 0; i < strlen(buffer)-1; i++){
            if(isdigit(buffer[i])){
               index+=1;
            } else if(buffer[i] == '-'){
                index+=1;
            } else {
                printf("el valor: %c no es valido\n", buffer[i]);
                index = 0;
                fflush(stdin);
            }
        }

        if(index == strlen(buffer)-1){
            valor = atoi(buffer);
            break;
        }
        else {
            printf("valores incorrectos\n");
            index = 0;
            fflush(stdin);
        }
    }
    return valor;
}




