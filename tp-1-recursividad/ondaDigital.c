#include "tp1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se
//pide obtener recursivamente la onda que representa utilizando “_” y “|”.  La “L” o la
//“H” se pueden ingresar tanto en mayúsculas como en minúsculas.
//Ejemplos:
//ondaDigital (“LHLHL”)  => “_ |¯ |_|¯ |_”
//ondaDigital (“HHHHLLLLHHHHHLLHH”)  => “¯ ¯ ¯ ¯ | _ _ _ _ |¯ ¯ ¯ ¯ ¯ | _ _ | ¯ ¯ ”

void ondaDigital(char onda[], int inicio, int fin){

    if(strlen(onda) <= 1){

        if(onda[0] == 'H'){
            printf("- ");
        } else if(onda[0] == 'L'){
            printf("_ ");
        }
    }

    if(inicio >= fin){
      return;
    }
    else {
        //la posicion es L || H?
        if(onda[inicio] == 'H'){
            printf("- ");

        } else if(onda[inicio] == 'L'){
            printf("_ ");
        }

        // si existe un cambio de L a H, o de H a L, se agrega una barra
        // de cambio de frecuencia

        if(onda[inicio] != onda[inicio+1]){
            printf("| ");
        }

        //como el corte de ejecucion es: inicio >= fin, antes de que corte debemos preguntar
        //cual es el valor del ultimo digito dentro del array onda[]

        if(inicio == fin-1){
            if(onda[fin] == 'H'){
                printf("- ");
            }
            else{
                printf("_ ");
            }
        }
        ondaDigital(onda, inicio+1,fin);
    }
}

void iniciarOndaDigital(){
    char cadena[255];    // un array para almacenar los caracteres
    int index = 0;       // indice para rastrear la posicion en el array

    while (1) {
        printf("Ingresar caracteres H (High) / L (Low): ");
        fgets(cadena, sizeof(cadena), stdin);

        //itera los valores ingresados en busqueda de que sean correctos
        for(int i = 0; i < strlen(cadena)-1; i++){
            cadena[i] = toupper(cadena[i]);

            if(cadena[i] == 'H' || cadena[i] == 'L'){
                index ++;
            }
            else {
                printf("el valor: %c no es valido\n", cadena[i]);
                index = 0;
                fflush(stdin);
            }
        }

        if(index == strlen(cadena)-1){
            break;
        }
        else {
            printf("valores incorrectos\n");
            index = 0;
            fflush(stdin);
        }

    }

    //agregar final a la cadena en la ultima posicion registrada por index
    cadena[index] = '\0';

    // Llama a la funcion ondaDigital con la cadena capturada
    ondaDigital(cadena, 0, strlen(cadena) - 1);
}


