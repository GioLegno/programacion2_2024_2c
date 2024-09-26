
#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

Pila elementos_comunes(Pila pila1, Pila pila2) {
    Pila pila_aux_1 = p_crear();
    Pila pila_aux_2 = p_crear();
    Pila pila_elementos_comunes = p_crear();
    TipoElemento elemento_pila_1;
    TipoElemento elemento_pila_2;
    bool encontrado;

    while (!p_es_vacia(pila1)) {
        elemento_pila_1 = p_desapilar(pila1);
        p_apilar(pila_aux_1, elemento_pila_1);

        encontrado = false;

        while (!p_es_vacia(pila2)) {
            elemento_pila_2 = p_desapilar(pila2);
            p_apilar(pila_aux_2, elemento_pila_2);

            if (elemento_pila_1->clave == elemento_pila_2->clave && !encontrado) {
                p_apilar(pila_elementos_comunes, elemento_pila_1);
                encontrado = true;
            }
        }

        while (!p_es_vacia(pila_aux_2)) {
            elemento_pila_2 = p_desapilar(pila_aux_2);
            p_apilar(pila2, elemento_pila_2);
        }
    }

    while (!p_es_vacia(pila_aux_1)) {
        elemento_pila_1 = p_desapilar(pila_aux_1);
        p_apilar(pila1, elemento_pila_1);
    }

    return pila_elementos_comunes;
}
Pila llenar() {
    Pila p1 = p_crear();
    int cantidad_num;
    int numero;
    int result;

    // Validar la cantidad de numeros a apilar
    do {
        printf("Ingrese cantidad de numeros a apilar (n>0): ");
        result = scanf("%d", &cantidad_num);

        // Verificar que sea un numero entero valido y positivo
        if (result != 1 || cantidad_num <= 0) {
            printf("Error: Por favor, ingrese un numero entero positivo.\n");

            // Limpiar el buffer de entrada
            while (getchar() != '\n');
        }
    } while (result != 1 || cantidad_num <= 0);

    for (int i = 1; i <= cantidad_num; i++) {
        do {
            printf("Ingrese el numero %d: ", i);
            result = scanf("%d", &numero);

            // Verificamos que sea un numero entero valido
            if (result != 1) {
                printf("Error: Entrada no valida. Por favor, ingrese un numero entero.\n");

                // Limpiar el buffer de entrada.
                while (getchar() != '\n');
            }
        } while (result != 1);  // Repetir mientras no se ingrese un numero valido

        p_apilar(p1, te_crear(numero));
    }

    return p1;
}

int main(){
printf("Ingrese los datos de la pila 1: \n");
Pila p1 = llenar();
printf("Ingrese los datos de la pila 2: \n");
Pila p2 = llenar();
printf("Pila 1: \n");
p_mostrar(p1);
printf("Pila 2: \n");
p_mostrar(p2);
Pila elem_comunes = elementos_comunes(p1,p2);
printf("ELEMENTOS COMUNES: \n");
p_mostrar(elem_comunes);


}
