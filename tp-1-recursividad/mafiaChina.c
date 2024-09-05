#include "tp1.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Se conoce que la mafia china es muy organizada y protege mucho a sus miembros,
// cuando deciden asistir a una reunión se dispone de una cantidad de chinos que
// asisten, y ellos se ubican de forma que al mirarlos frontalmente generan cierto respeto
// y temor. A continuación, se tiene una serie de posibles reuniones y su nivel y la
// apariencia que se tiene del grupo que va a la reunión vistos frontalmente:


// Nivel reunión     Vista frontal de la delegación

// 1                 (-.-)
// 2              (-.(-.-).-)
// 3            (-.(-.(-.-).-).-)
// 4        (-.(-.(-.(-.-).-).-).-)

// Considerando esta descripción, diseñar los procesos recursivos que permitan mostrar
// la apariencia del grupo de chinos que asisten a una reunión de nivel n. Acotar el “n” a
// un valor máximo de 50.

void mostrarMaficaChina(int n, int izquierda, int derecha){

    //caso base
    if(n == 1){
        printf("(-.-)");
        return;
    }

    // si izquierda es igual a 1, mostramos la cara principal, y luego avanzamos con los miembros a la derecha
    if(izquierda == 1){
        printf("(-.-)");
        mostrarMaficaChina(n, 0 , derecha);

    } else if(izquierda > 1){
        printf("(-.");
        mostrarMaficaChina(n, izquierda-1, derecha);
    }

    if(izquierda == 0 && derecha < n-1){
        printf(".-)");
        mostrarMaficaChina(n, izquierda, derecha+1);
    }

    //fin de ejecucion
    if(izquierda == 0 && derecha == n-1){
        return;
    }
}

void iniciarMafiaChina(){
    char input_buffer[60];
    int n;

    while (1)
        {
        printf("cuantos miembros tiene la mafia: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        // permite cargar n mientras su longitud no sea menor o igual a 50,
        // y el dato almacenado en input_buffer no sea un caracter
        if (isdigit(input_buffer[0]) && atoi(input_buffer) <= 50)
        {
            // si todo fue bien se asigna a N lo almacenado en input_buffer
            n = atoi(input_buffer);
            break;
        }
        else
        {
            printf("[ERROR] dato incorrecto, los caracteres no son valido\n");
        }
    }

    /**
     * Parametros de la funcion mostrarMafiaChina
     * 1. la cantidad total de miembros
     * 2. Los miembros a izquierda, esta variable se decrementa hasta que sea 1
     * 3. Los miembros a derecha. Inicializa en 0. Cuando decrementar a la izquierda es == 0, esta variable empieza a incrementar
     *    su valor hasta n-1, mostrando los miembos a la derecha.
     */
    mostrarMaficaChina(n, n, 0);
}
