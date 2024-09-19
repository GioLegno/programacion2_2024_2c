#include <stdio.h>
#include <stdbool.h>
#include "tp2.h"
#include "listas.h"
#include "tipo_elemento.h"

//Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1.  Se considera múltiplo si cada
//elemento de L2 se divide en forma exacta por el valor L1 de la misma posición. Usar la
//clave como campo de datos solamente.

//Ejemplo: si L1 = (2, 5, 7, 3) y L2 = (8, 20, 28, 12) entonces L2 es múltiplo por L1 porque
//cada posición de L2 se divide por el valor de L1 de la misma posición en forma exacta
//(sin decimales). Si el resultado de la división retorna el mismo valor para cada posición
//se dice que “L2” es múltiplo de “L1” por un “escalar”.  Para este caso “4” es el escalar
//de L1.  El algoritmo debe contemplar esta situación.


int escalar(Lista L1, Lista L2) {
    // Iteradores para recorrer ambas listas
    Iterador ite_L1 = iterador(L1);
    Iterador ite_L2 = iterador(L2);

    // Variables para almacenar los elementos actuales de L1 y L2
    TipoElemento elemento_L1, elemento_L2;

    // Obtenemos el primer elemento de L1 y L2 para calcular el cociente inicial
    elemento_L1 = siguiente(ite_L1);
    elemento_L2 = siguiente(ite_L2);

    // Verificamos si el primer elemento de L1 es 0
    if (elemento_L1->clave == 0) return 0;

    // Almacenamos el cociente inicial
    int cociente_inicial = elemento_L2->clave / elemento_L1->clave;

    while (hay_siguiente(ite_L1) && hay_siguiente(ite_L2)) {
        elemento_L1 = siguiente(ite_L1);
        elemento_L2 = siguiente(ite_L2);

        // Verificamos que L2 sea divisible por L1
        if (elemento_L1->clave == 0 || elemento_L2->clave % elemento_L1->clave != 0) {
            return 0;  // No se puede dividir por 0
        }

        // comparacion del nuevo cociente con el anterior
        int cociente_actual = elemento_L2->clave / elemento_L1->clave;

        if (cociente_actual != cociente_inicial) {
            return 0;  // Si hay un cociente diferente, entonces no existe el escalar
        }
    }

    return cociente_inicial;
}

void IniciarEjercicio3(){
    int n, m;
    bool b;

    printf("\n");
    printf("Cargar dos listas, para determinar el escalar solo si L2 es multiplo de L1.\n");
    printf("\n");
    //creacion de las listas
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    //cargar las listas
    printf("A continuacion cargue la lista numero 1 \n");
    do{
        b = ingresoEntero(&n); //funcion reutilizable definida en utils
        // Agrega el numero a la lista
        if(b) l_agregar(L1, te_crear(n));

    }while(b);
    l_mostrar(L1);
    printf("\n");
    printf("A continuacion cargue la lista numero 2 \n");


    do{
        b = ingresoEntero(&m);
        if(b) l_agregar(L2, te_crear(m));
    } while(b);

    printf("\n");
    l_mostrar(L2);
    printf("\n");
    //una vez cargados
    printf("Escalar: %d", escalar(L1, L2));
}




