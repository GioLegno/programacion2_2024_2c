#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "listas.h"
#include "tp2.h"
//int valor_polinomio(Lista coeficientes, int x);
//Lista llenar(Lista L1);

int valor_polinomio(Lista coeficientes,int x){
    int longitud = l_longitud(coeficientes);
    int i;
    int contador = 1;
    int resultado = 0;
    TipoElemento coef;
    for (i=longitud-1;i>=0;i--){
        coef = l_recuperar(coeficientes,contador);
        contador++;
        resultado += coef->clave * pow(x,i);

    }

    return resultado;

}

Lista llenar(){
    Lista L1;
    L1 = l_crear();
    int nro_grado;
    int coeficiente;

    printf("Ingrese el grado del polinomio\n");
    nro_grado = ingresoUnSoloEntero();

    for (int i=nro_grado;i>=0;i--){
        printf("Ingrese el coeficiente de grado %d\n",i);
        coeficiente = ingresoUnSoloEntero();
        l_agregar(L1,te_crear(coeficiente));
    }
    return L1;
}

void IniciarEjercicio5(){
    printf("\n");
    printf("Guarde en una lista enlazada los coeficientes de un polinomio.\n");
    printf("Ademas debera ingresar un 'X' para devolver el valor del polinomio para ese punto\n");
    printf("\n");

    Lista coeficientes = llenar();
    l_mostrar(coeficientes);
    int x;

    printf("\n");
    printf("Ingrese el valor de x\n");
    x = ingresoUnSoloEntero();

    int resultado = valor_polinomio(coeficientes,x);
    printf("El resultado del polinomio es: %d\n",resultado);
}
