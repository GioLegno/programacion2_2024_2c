#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilas.h"
#include "tp3.h"


Pila conversion_decimal(int decimal, int base) {
    Pila pila = p_crear();

    // Convertir el numero a la base deseada
    while (decimal >= base) {
        p_apilar(pila, te_crear(decimal % base));  // Apilar el resto de la division
        decimal = decimal / base;
    }
    p_apilar(pila, te_crear(decimal));  // Apilar el ultimo digito (o el unico si decimal < base)

    return pila;  // Retornar la pila con los dígitos
}
void mostrar_pila_hexadecimal(Pila pila) {
    while (!p_es_vacia(pila)) {
        TipoElemento digito = p_desapilar(pila);
        if (digito->clave >= 10) {
            printf("%c", ((char)digito->clave + 55));  // Convertir a letras A-F si es >= 10
        } else if (digito->clave == '-') {
            printf("-");
        } else {
            printf("%d", digito->clave);  // Imprimir los numeros 0-9
        }
    }
}
void IniciarEjercicio4() {
    int numero_decimal,base;

    printf("\n");
    printf("Ingrese un numero decimal y una base para visualizar su correspondiente valor expresado en una base de 2 a 16 (hexadecimal)\n");
    printf("\n");

    printf("Ingrese el numero a convertir (entero postivo): \n");
    numero_decimal = ingresoUnSoloEntero();

    do{
        printf("\n");
        printf("Ingrese la base (entero positivo): \n");
        base = ingresoUnSoloEntero();

        if(base < 2){
           printf("Error: Ingrese un dato entero positivo >= 2. \n");
        }

    } while(base < 2);

    Pila pila = conversion_decimal(numero_decimal, base);
    printf("\n");
    if (base == 16){
        printf("Numero en hexadecimal: ");
        mostrar_pila_hexadecimal(pila);  // Imprimir los digitos del numero hexadecimal
        printf("\n");
    } else{
        printf("Numero convertido a base %d: \n",base);
        p_mostrar(pila);
    }
}
