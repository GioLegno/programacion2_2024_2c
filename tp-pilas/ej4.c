
#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

Pila conversion_decimal(int decimal, int base) {
    Pila pila = p_crear();  // Crear una pila nueva para almacenar los dígitos

    // Convertir el numero a la base deseada
    while (decimal >= base) {
        p_apilar(pila, te_crear(decimal % base));  // Apilar el resto de la división
        decimal = decimal / base;
    }
    p_apilar(pila, te_crear(decimal));  // Apilar el ultimo dígito (o el único si decimal < base)

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
int main() {
    int numero_decimal,base,result;
    do{
        printf("Ingrese un numero decimal positivo a convertir: ");
        result = scanf("%d", &numero_decimal);
        if (result != 1){
            printf("Error: Ingrese un dato decimal entero positivo. \n");
            while (getchar() != '\n'); //limpiamos el buffer de entrada.
        }
    } while(result != 1);

    do{
        printf("Ingrese la base (b=int;b>=2): ");
        result = scanf("%d", &base);
        if (result != 1 || base < 2){
            printf("Error: Ingrese un dato entero positivo >= 2. \n");
            while (getchar() != '\n'); //limpiamos el buffer de entrada.
        }
    } while(result != 1 || base < 2);


    Pila pila = conversion_decimal(numero_decimal, base);
    if (base == 16){
        printf("Numero en hexadecimal: ");
        mostrar_pila_hexadecimal(pila);  // Imprimir los digitos del numero hexadecimal
        printf("\n");
    }else{
    printf("Numero convertido a base %d: \n",base);
    p_mostrar(pila);
    }

    return 0;
}
