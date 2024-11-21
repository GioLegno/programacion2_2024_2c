//filtrar entrada de datos enteros con "scanf"
#include<stdio.h>
#include "validacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Función mejorada para validar un número entero en un rango específico
int entero_entre(int minimo, int maximo) {
    char entrada[100];  // Buffer para la entrada del usuario
    int numero;
    char *fin;          // Para verificar caracteres no válidos
    while (1) {
        printf("Ingrese un numero entre %d y %d: ", minimo, maximo);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("Error al leer la entrada. Intente de nuevo.\n");
            continue;
        }

        // Eliminar el salto de línea al final de la entrada
        entrada[strcspn(entrada, "\n")] = 0;

        // Validar que toda la cadena sea un número
        numero = strtol(entrada, &fin, 10); // Convierte la cadena a entero

        // Verificar si hay caracteres inválidos en `fin` o si la conversión falló
        if (*fin != '\0' || fin == entrada) {
            printf("Entrada invalida. Asegurese de ingresar un numero entero.\n");
            continue;
        }

        // Validar rango
        if (numero < minimo || numero > maximo) {
            printf("El numero debe estar entre %d y %d.\n", minimo, maximo);
            continue;
        }

        // Entrada válida
        return numero;
    }
}

float flotante_entre(float mayor_a,  float menor_a){
    int convertidos,bandera;
    float datoFloat;
    bandera = 0;
    do{
        if (bandera>1){
            printf("ingerse un entero dentro de (%.5f a %.5f): ",mayor_a,menor_a); //pide el dato  nuevamente
        }
        else{
            printf("ingerse un entero dentro de (%.5f a %.5f): ",mayor_a,menor_a); //pide el dato por primara ves
            bandera ++; //quito bandera
        }
        fflush(stdin);//limpio el bufer
        convertidos=scanf("%f",&datoFloat);//scanf:pide un dato flotante y convertidos devuelse la cantidad de datos que scanf pudo concertir a flotante
    }while((convertidos==0)||(datoFloat<mayor_a || datoFloat>menor_a));
    //mientras nose podo convertir el dato a float (convertidos==0) se repire el ciclo XQ no es numero
                //o el dato int y el dato float son distintos (datoInt!=datoFloat)  se repire el ciclo XQ no es entero
                //o el dato no esta en el intervalo deseado (datoInt<mayor_a || datoInt>menor_a) se repire el ciclo

    return datoFloat;
}
