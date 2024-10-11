#include <stdio.h>
#include "colas.h" // Dependiendo de cómo implementaste la cola
#include "pilas.h" // Dependiendo de cómo implementaste la pila
#include "listas.h" // Dependiendo de cómo implementaste la lista
#include "tipo_elemento.h"
#include "tp4.h"

Lista punto6(Cola c1, Pila p1);

Lista punto6(Cola c1, Pila p1) {
    TipoElemento x, y;
    int pos_cola, pos_pila;
    Lista resultado = l_crear();

    // Copiamos las estructuras originales para no perder sus datos
    Cola caux = c_crear();
    Pila paux = p_crear();  // Solo una pila auxiliar

    // Recorremos la cola
    pos_cola = 1;  // Iniciamos el contador de posición para la cola
    while (!c_es_vacia(c1)) {
        x = c_desencolar(c1);
        c_encolar(caux, x);  // Restauramos la cola original

        pos_pila = 1;
        while (!p_es_vacia(p1)) {
            y = p_desapilar(p1);
            p_apilar(paux, y);  // Apilamos en la pila auxiliar para restaurarla después

            // Comparamos los elementos de la cola y la pila
            if (x->clave == y->clave) {
                l_agregar(resultado, x);  // Agregamos el valor común
                l_agregar(resultado, te_crear(pos_cola));  // Agregamos posición en la cola
                l_agregar(resultado, te_crear(pos_pila));  // Agregamos posición en la pila
            }
            pos_pila++;  // Incrementamos la posición de la pila
        }

        // Restauramos la pila original desde paux
        while (!p_es_vacia(paux)) {
            y = p_desapilar(paux);
            p_apilar(p1, y);  // Apilamos nuevamente en la pila original
        }

        pos_cola++;  // Incrementamos la posición de la cola
    }

    // Restauramos la cola original
    while (!c_es_vacia(caux)) {
        x = c_desencolar(caux);
        c_encolar(c1, x);
    }

    return resultado;
}

void IniciarEjercicio6(){
    Cola c1 = c_crear();
    Pila p1 = p_crear();

    TipoElemento elemento;
    int n;
    bool b;

    printf("\n");
    printf("Cargue una pila y una cola con valores al azar. Finalmente vizualizara una lista con todos los valores comunes a ambas y en que posicion se encontro\n");
    printf("\n");

    // Carga de la cola
    printf("Proceder con la carga de la cola (MAX 10)\n");

    int cant_validos_c1 = 0;
    do {
        b = ingresoEntero(&n);
        if (b){
          c_encolar(c1, te_crear(n));
          cant_validos_c1++;
        }
    } while (b && cant_validos_c1 < 10);


    // Carga de la pila
    printf("Proceder con la carga de la pila (MAX 10)\n");
    int cant_validos_p1 = 0;
    do {
        b = ingresoEntero(&n);
        if (b){
            p_apilar(p1, te_crear(n));
            cant_validos_p1++;
        }
    } while (b && cant_validos_p1 < 10);

    // Mostrar la cola
    printf("Cola ingresada:\n");
    printf("\n");

    Lista resultado = punto6(c1, p1);

    printf("Elementos comunes y sus posiciones (elemento, pos_cola, pos_pila):\n");
    Iterador it = iterador(resultado);

    while (hay_siguiente(it)) {
        TipoElemento elem_comun = siguiente(it);
        int pos_cola = siguiente(it)->clave;
        int pos_pila = siguiente(it)->clave;
        printf("Elemento: %d, Posicion en cola: %d, Posicion en pila: %d\n", elem_comun->clave, pos_cola, pos_pila);
    }

}


