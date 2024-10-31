#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "listas.h"
#include "tp5.h"

bool existeEnLista2(Lista lista, int clave);

// Función para eliminar espacios en blanco
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

bool ingresoEntero(int *valor){
    bool ingre = true;
    char input[100];
    printf("Ingrese clave para el arbol: ");
    fgets(input, sizeof(input), stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    while(strspn(input,".0123456789")!= strlen(input) ||esflotante(input)||strcmp(input,"\0")==0||!un_solo_punto(input)){
        printf("Ingrese un numero entero positivo no repetido o un solo punto: ");
        fgets(input, sizeof(input), stdin);
        if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
        }
    }
    *valor = atoi(input);
    if(strcmp(input, ".") != 0){
        return ingre;
    }else{
        ingre=false;
    }
    return ingre;
}

// Funciones auxiliares

bool esflotante(char val[]) {
    bool flotante = false;
    int longitud = strlen(val);
    for (int i = 0; i < longitud; i++) {
        if (val[i] == ',' || val[i] == ' ') {
            flotante = true;
        }
    }
    return flotante;
}

bool un_solo_punto(char val[]) {
    bool flotante = true;
    int longitud = strlen(val);
    int contadorpuntos = 0;
    int contadordemas = 0;
    for (int i = 0; i < longitud; i++) {
        if (val[i] == '.') {
            contadorpuntos++;
        } else {
            contadordemas++;
        }
    }
    if (contadorpuntos > 1 || (contadorpuntos == 1 && contadordemas >= contadorpuntos)) {
        flotante = false;
    }
    return flotante;
}

bool existeEnLista2(Lista lista, int clave) {
    Iterador it = iterador(lista);
    while (hay_siguiente(it)) {
        TipoElemento x = siguiente(it);
        if (x->clave == clave) {
            return true;
        }
    }
    return false;
}


void validar_clave_a_buscar(int *clave){
    char input[100];
    printf("Ingrese la clave a buscar: ");
     fgets(input, sizeof(input), stdin);
    while (esflotante3(input)|| sscanf(input, "%d", clave) != 1||*clave<0) {
        printf("Entrada no valida. Por favor ingrese un numero entero mayor o igual que 0: ");
        fgets(input, sizeof(input), stdin);
    }
}

void validar_clave(int *clave){
    char input[100];
    printf("Ingrese la clave: ");
     fgets(input, sizeof(input), stdin);
    while (esflotante3(input)|| sscanf(input, "%d", clave) != 1||*clave<0) {
        printf("Entrada no valida. Por favor ingrese un numero entero mayor o igual que 0: ");
        fgets(input, sizeof(input), stdin);
    }
}


bool esflotante3(char val[]){
    bool flotante = false;
    int longitud = strlen(val);
    for (int i = 0; i < longitud; i++) {
        if ( val[i] == ',' ||val[i]=='.'|| val[i] == ' ') {
            flotante = true;
        }
    }
    return flotante;
}


