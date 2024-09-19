#include <stdio.h>
#include <stdbool.h>
#include "tp2.h"
#include "listas.h"
#include "tipo_elemento.h"

//Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1 -> L2. Por lo tanto
//puede suceder que:  L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparación es por
//la clave, posición a posición, donde si L1 tiene mas cantidad de claves mayores que L2 se
//considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 sera igual a L2.
//Determinar la complejidad algoritmica de la solucion empleada.

void CompararListas(Lista L1, Lista L2){

    // Iteradores
    Iterador ite_L1 = iterador(L1);
    Iterador ite_L2 = iterador(L2);

    TipoElemento x1, x2;

    int contador_L1, contador_L2;

    while(hay_siguiente(ite_L1) && hay_siguiente(ite_L2)){

        x1 = siguiente(ite_L1);
        x2 = siguiente(ite_L2);

        if(x1 -> clave > x2->clave){
            contador_L1 ++;
        }
        else if(x1 -> clave < x2 -> clave){
            contador_L2 ++;
        } else {
            contador_L1++;
            contador_L2++;
        }
    }

    if(contador_L1 > contador_L2){
        printf("L1 > L2\n");
    }
    else if(contador_L1 < contador_L2){
         printf("L1 < L2\n");
    }
    else {
        printf("L1 y L2 Son iguales\n");
    }

}


void IniciarEjercicio4(){

    int n, m;
    bool b;

    printf("\n");
    printf("Cargar dos listas, para luego compararlas mediante sus clave en el sentido L1 -> L2.\n");
    printf("\n");
    printf("A continuacion cargue la lista numero 1 \n");

    //creacion de las listas
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    do{
        b = ingresoEntero(&n);
        if(b) l_agregar(L1, te_crear(n));

    }while(b);

    //mostrar lista 1
    printf("\n");
    l_mostrar(L1);
    printf("\n");
    printf("A continuacion cargue la lista numero 2 \n");

    //cargar lista 2
    do{
        b = ingresoEntero(&m);
        if(b) l_agregar(L2, te_crear(m));
    } while(b);

    printf("\n");
    l_mostrar(L2);
    printf("\n");
    //Las listas se pasan como arguemento en ComparacionListas
    CompararListas(L1, L2);
}
