#include "tp1.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Definir una función recursiva que dado un conjunto devuelva una lista con los
// subconjuntos del mismo tales que la suma de los elementos de cada subconjunto
// sumen una cantidad dada.  Por ejemplo:   Dado el conjunto A = {10, 3, 1, 7, 4, 2}. La
// lista de los conjuntos que sumen 7 sería: R = [{3, 4}, {1, 4, 2}, {7}]
// Ejemplos:
// subconjuntosQueSumanN ({10, 3, 1, 7, 4, 2}, 7) => {{3, 4}, {1, 4, 2}, {7}}
// subconjuntosQueSumanN ({10, 3, 1, 7, 4, 2}, 10) => {{10}, {3,7}, {3, 1, 4, 2}, {1, 7, 2}}

void subconjuntosQueSumanN(int vec[], int n, int tam, int val_inicial, int sumatoria, int arr_aux[], int aux_tam)
{

    // Si la sumatoria es igual a n, se muestra el subconjunto iterando sobre el arr_aux
    if (sumatoria == n)
    {
        printf("suman %d: ", n);
        for (int i = 0; i < aux_tam; i++)
        {
            printf("%d ", arr_aux[i]);
        }
        printf("\n");
        return;
    }

    // Si valor inicial es mayor o igual a tamaño, o la sumatoria supera n, se retorna
    if (val_inicial >= tam || sumatoria > n)
    {
        return;
    }

    // Incluir el valor actual en el arreglo auxiliar y actualizar la sumatoria
    arr_aux[aux_tam] = vec[val_inicial];

    subconjuntosQueSumanN(vec, n, tam, val_inicial + 1, sumatoria + vec[val_inicial], arr_aux, aux_tam + 1);

    // Se excluye el elemento actual del subconjunto y continua con el siguiente
    subconjuntosQueSumanN(vec, n, tam, val_inicial + 1, sumatoria, arr_aux, aux_tam);
}

void iniciarSubconjuntosQueSumanN(){
    int corte;                      // cantidad de elementos que componen el conjunto
    int conjunto[100];              // vector que almacena los valores que componen el conjunto
    char input_buffer[10];          // arreglo para cargar la variable corte
    char conjunto_input_buffer[10]; // arreglo para cargar los valores que componen el conjunto ( conjunto[] )
    int count = 0;

    char valor_conjunto_buffer[50];
    int valor_conjunto;
    //pregunta el valor deseado a alcanzar
     while (1)
    {
        printf("ingrese un conjunto: ");
        fgets(valor_conjunto_buffer, sizeof(valor_conjunto_buffer), stdin);

        // permite cargar corte mientras su longitud no sea igual a la del conjunto,
        // y corte no sea un caracter
        if (isdigit(valor_conjunto_buffer[0]))
        {
            // si todo fue bien se asigna input_buffer convertido a entero a corte
            valor_conjunto = atoi(valor_conjunto_buffer);
            break;
        }
        else
        {
            printf("[ERROR] dato incorrecto\n");
        }
    }


    while (1)
    {
        printf("cuantos numeros componen tu conjunto: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        // permite cargar corte mientras su longitud no sea igual a la del conjunto,
        // y corte no sea un caracter
        if (isdigit(input_buffer[0]))
        {
            // si todo fue bien se asigna input_buffer convertido a entero a corte
            corte = atoi(input_buffer);
            break;
        }
        else
        {
            printf("[ERROR] dato incorrecto\n");
        }
    }

    // carga los valores del conjunto mientras contador sea menor que el valor de corte
    while (count < corte)
    {
        printf("Ingrese valor: ");
        fgets(conjunto_input_buffer, sizeof(conjunto_input_buffer), stdin);

        // si conjunto_input_buffer es un digito es cargado al array, caso contrario muestra un error
        if (isdigit(conjunto_input_buffer[0]))
        {
            // el array conjunto recibe y converte a entero en la posicion count(contador) lo que recibe de conjunto_input_buffer
            conjunto[count] = atoi(conjunto_input_buffer);
            count += 1;
            printf("numeros ingresados:  %d\n", count);
        }
        else
        {
            printf("[ERROR] dato incorrecto\n");
        }
    }
    // Array auxiliar para construir los subconjuntos
    int arr_aux[corte];

    /*
    *subconjuntosQueSumanN recibe como parametro:
    * 1. el conjunto
    * 2. el numero que se desea alcanzar
    * 3. el tamaño del conjunto
    * 4. un valor inicial que se incrementa por cada iteracion recursiva inicializado en 0
    * 5. un valor inicial en 0 para la sumatoria
    * 6. un tamaño inicial inicializado en 0 para arr_aux. Cada vez que se agregue un valor a arr_aux,
        este se incrementa. En caso de que la sumatoria sea igual a N, se iteraran los elementos dentro de arr_aux
        hasta que sea <= a tamaño inicial
    */
    subconjuntosQueSumanN(conjunto, valor_conjunto, corte, 0, 0, arr_aux, 0);
}



