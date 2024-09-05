#include "tp1.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de
// números enteros.  Contemplar los negativos.
// Ejemplos:
// agregarSeparadorMiles (“123456”) => “123.456”
// agregarSeparadorMiles (“12345678”) => “12.345.678”

void agregarSeparadorMiles(char *numero, int tam, int ultima_pos, int contador, char *arr_aux, int tam_arr_aux)
{
    if (tam < 4 || (tam < 5 && numero[0] == '-'))
    {
        printf("numero: %s", numero);
        return;
    }

    if (contador >= 3 && ultima_pos > 0 && numero[ultima_pos-1] != '-')
    {
        arr_aux[tam_arr_aux] = '.';
        tam_arr_aux += 1;
        arr_aux[tam_arr_aux] = numero[ultima_pos - 1];
        contador = 0;
    }
    else
    {
        arr_aux[tam_arr_aux] = numero[ultima_pos - 1];
    }

    if (ultima_pos <= 0)
    {
        for (int i = tam_arr_aux; i >= 0; i--)
        {

            printf("%c", arr_aux[i]);
        }

        return;
    }

    agregarSeparadorMiles(numero, tam, ultima_pos - 1, contador + 1, arr_aux, tam_arr_aux + 1);
}

void iniciarAgregarSeparadorMiles()
{
    char num[50];
    char arr_aux[50];
    int index = 0;

    while(1){
        printf("Ingresar numero: ");
        fgets(num, sizeof(num), stdin);
        for(int i = 0; i < strlen(num)-1; i++){
            if(isdigit(num[i])){
               index+=1;
            } else if(num[i] == '-'){
                index+=1;
            } else {
                printf("el valor: %c no es valido\n", num[i]);
                index = 0;
                fflush(stdin);
            }
        }

        if(index == strlen(num)-1){
            break;
        }
        else {
            printf("valores incorrectos\n");
            index = 0;
            fflush(stdin);
        }
    }
    /*
     * Recibe como parametro
     * 1. Un arreglo de caracteres señalando el numero
     * 2. El tamaño del arreglo
     * 3. Este parametro es utilizado para indicar la ultima posicion, ademas se decrementa
     * 4. Un contador inicializado en 0, para contar cada 3 posiciones a partir del final donde debe ir un punto
     * 5. Un arreglo auxiliar para almacenar el nuevo numero separado con puntos
     * 6. Un contador inicializado en 0 que ayudara a cargar los valores en el arreglo auxiliar
    */

    agregarSeparadorMiles(num, strlen(num) - 1, strlen(num) - 1, 0, arr_aux, 0);
}

