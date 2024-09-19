#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "tp2.h"
#include "tipo_elemento.h"
#include "listas.h"
/*========================================================================== INCLUDES =====================================================================================*/

/*========================================================================== PUNTO 1 =====================================================================================*/

void condiciones(Lista lista){
    if (l_es_vacia(lista))
    {
        printf("La lista esta vacia...\n");
    }

    if (l_es_llena(lista))
    {
        printf("La lista esta llena...\n");
    }

    if (!l_es_llena(lista) && !l_es_vacia(lista)){
        printf("La lista todavia no esta llena...\n");
    }
}

void IniciarEjercicio1(){
    TipoElemento elemento, elemento_insertar, buscar, recuperar_posicion;
    Lista lista;

    int i = 1;  // El valor del que va a iniciar la lista
    lista = l_crear();  // Crea la lista
    elemento = te_crear(15); // Asigna una clave a los valores
    bool borrar_elemento, insertar_elemento, eliminar_elemento;

    printf("\n----------------------------------------------------------------------------------------------------\n");
    printf("Se creo la lista correctamente!\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    while (i <= 100){   // Crea los valores de la lista
        elemento = te_crear(i); // Se encarga de asignar el valor a clave (i + 1, n veces)
        l_agregar(lista, elemento); // Agrega el elemento a la lista creada
        i++;    // Incrementa el numero
    }

    l_mostrar(lista);   // Muestra la lista

    int longitud = l_longitud(lista);   // Calcula la longitud de la lista
    printf("La lista tiene una longitud de: %i elementos.\n", longitud);

    condiciones(lista); // Condiciones
    printf("----------------------------------------------------------------------------------------------------\n");
    buscar = l_buscar(lista, 30);   // Busca el elemento 30 en la lista. Si existe, printea que existe. Si no, printea que no.

    if (buscar == NULL){
        printf("El elemento no se encuentra en la lista.");
    }
    else{
        printf("El elemento (%d) se encuentra en la lista.\n", buscar->clave);
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    elemento_insertar = te_crear(1050);

    insertar_elemento = l_insertar(lista, elemento_insertar, 13);    // Inserta el elemento 1050 en la posicion 13 de la lista. Si puede, printea que si. Si no, que no.

    if (insertar_elemento == false){
        printf("No se pudo insertar el elemento, ya que la lista esta llena.\n");
    }
    else{
        printf("El elemento (%d) se agrego correctamente.\n", elemento_insertar->clave);
        l_mostrar(lista);   // Muestra la lista
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    eliminar_elemento = l_eliminar(lista, 13);  // Asignamos a eliminar_elemento el resultado de la funcion l_eliminar

    if (eliminar_elemento == false){
        printf("No se pudo eliminar el elemento de la lista\n");
    }
    else{
        printf("Se elimino el elemento en la posicion indicada.\n");    // Se va a borrar el elemento que pongamos como pos. En este caso, pos = 13
        l_mostrar(lista);   // Muestra la lista
        int longitud = l_longitud(lista);   // Calcula la longitud de la lista
        printf("La lista tiene una longitud de: %i elementos.\n", longitud);
    }
    condiciones(lista); // Condiciones

    printf("----------------------------------------------------------------------------------------------------\n");

    borrar_elemento = l_borrar(lista, 15);  // Asignamos a borrar_elemento el resultado de la funcion l_borrar

    if (borrar_elemento){
        printf("El elemento se borro correctamente.\n");  // Se va a borrar el elemento que pongamos como clave. En este caso, clave = 15
        l_mostrar(lista);   // Muestra la lista
        int longitud = l_longitud(lista);   // Calcula la longitud de la lista
        printf("La lista tiene una longitud de: %i elementos.\n", longitud);
    }

    condiciones(lista); //Condiciones

    printf("----------------------------------------------------------------------------------------------------\n");

    recuperar_posicion = l_recuperar(lista, 13);    // Muestra el elemento que esta en la posicion indicada

    if (recuperar_posicion == NULL){
        printf("No se pudo recuperar el elemento.\n");
    }
    else{
        printf("El elemento recuperado es el numero: %d.\n", recuperar_posicion->clave);
    }

    printf("----------------------------------------------------------------------------------------------------\n\n");
}

