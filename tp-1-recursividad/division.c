#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

float division(int m, int n) {
    float decimal=0;
    float resto = (float)m;
    float maux = 0;

    if (n == 0)
    {
        return 0;
    }

    if (m < n  || n != 0){
        decimal = resto/n;
        maux += decimal;
        resto = maux;
        return resto;
    }
    resto = m-n;
    return 1 + division(resto, n);
}

int validarM(){
    int m;
    float temporal;
    int resultado;

    printf("Ingresa el numero M: ");
    resultado = scanf("%f", &temporal);

    while ((resultado != 1)|| (temporal != (int)temporal)){
        printf("Dato incorrecto. Ingresa denuevo: ");
        fflush(stdin);
        resultado = scanf("%f", &temporal);
    }
    m = (int)temporal;
    return m;
}

int validarN(){
    int n, resultado;
    float temporal_1;

    printf("Ingresa el numero N: ");
    resultado = scanf("%f", &temporal_1);
    while ((resultado != 1)|| (temporal_1 != (int)temporal_1)){
        printf("Dato incorrecto. Ingresa denuevo: ");
        fflush(stdin);
        resultado = scanf("%f", &temporal_1);
    }
    n = (int)temporal_1;
    return n;
}

void iniciarDivision(){
    int m, n;

    m = validarM();
    n = validarN();

    if(n == 0){
        printf("No es posible dividir por 0\n");
        return;
    }

    float resultado = (division(m,n));
    printf("resultado despues de division: %f ", resultado);
    if (resultado == (int)resultado) {
        printf("division(%d, %d) => %d\n", m, n, (int)resultado);  // Si el resultado es un número entero, lo imprimimos sin decimales
    }

    else {
        printf("division(%d, %d) => %.6f\n", m, n, resultado);     // Si no es un número entero, lo imprimimos con decimales
    }
}
