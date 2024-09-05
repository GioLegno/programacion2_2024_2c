#include "tp1.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

bool espalindromoaux(char *cadena, int inicio, int fin){

    if (inicio >= fin)
    {
        return true;

    }
    if (cadena[inicio] != cadena[fin])
    {

        return false;
    }
    return espalindromoaux(cadena, inicio+1, fin-1);
}

bool palindromo(char *cadena) {
    int longitud = strlen(cadena);
    return espalindromoaux(cadena, 0 , longitud-1);
}

void eliminarEspacios(char *cadena) {
    char *destino = cadena;
    while (*cadena)
    {
        if (!isspace(*cadena))
        {
            *destino++ = *cadena;
        }
        cadena++;
    }
    *destino = '\0';
}

void pasarminusculas(char *palabra){
    for (int i = 0; i < strlen(palabra); i++)
    {
        palabra[i]=tolower(palabra[i]);
    }
}

void iniciarPalidromo(){
    char palabra[50];

    char cadena[50];

    printf("Ingrese una palabra o frase para ver si es un palindromo: ");
    scanf("%s", palabra);

    fgets(cadena, sizeof(cadena), stdin);
    eliminarEspacios(cadena);

    char *palabraentera = strcat(palabra,cadena);
    pasarminusculas(palabraentera);

    if (palindromo(palabraentera))
    {
        printf("Palindromo => Verdadero...\n");
    }
    else
    {
        printf("Palindromo => Falso...\n");
    }
}






