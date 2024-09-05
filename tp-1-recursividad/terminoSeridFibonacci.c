#include "tp1.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

int terminoSerieFibonacci(int k){
    int resultado;
    if (k==0){
        return 1;
    }
    if (k <= 1){
        resultado = k ;
    }
    else{
        resultado = terminoSerieFibonacci(k - 1) + terminoSerieFibonacci(k - 2);
    }
    return resultado;
}

int validarK() {
    int k;
    //variable temporal
    float temporal;
    int resultado;

    printf("Ingresa el numero K: ");
    resultado = scanf("%f", &temporal);

    while ((resultado != 1) || (temporal < 0) || (temporal > 45) || (temporal != (int)temporal)) {
        printf("Dato incorrecto. Ingresa un numero K entre 0 y 45: ");
        fflush(stdin);
        resultado = scanf("%f", &temporal);
    }

    //si al comparar los tipos temporal == (int)temporal, el bucle finaliza
    k = (int)temporal;
    return k;
}

void iniciarTerminoSerieFibonacci(){
    int k;
    k = validarK();
    printf("El %d k-esimo numero de Fibonacci es: %d\n", k, terminoSerieFibonacci(k));
}
