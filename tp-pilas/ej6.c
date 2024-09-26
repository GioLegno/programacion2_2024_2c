#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void recursion(Pila p, int e,Pila aux,Pila r,TipoElemento elem);
void recuperar_p(Pila p,Pila aux,TipoElemento elem);
Pila eliminar_ocurrencias(Pila p, int e) {
    Pila aux = p_crear();
    Pila r = p_crear();
    TipoElemento elem;

    // Recorreremos y desapilamos p, guardamos en aux todos lo elementos
    // y en r los diferentes a e.
    while (p_es_vacia(p) == false) {
        elem = p_desapilar(p);
        if (elem != NULL) {
            p_apilar(aux, elem);
            if (elem->clave != e) {
                p_apilar(r, elem);
            }
        }
    }

    // Restaurar la pila original
    while (p_es_vacia(aux) == false) {
        elem = p_desapilar(aux);
        if (elem != NULL) {
            p_apilar(p, elem);
        }
    }

    /* Invertimos la pila r. (opcionl)
    while (p_es_vacia(r)== false) {
        elem = p_desapilar(r);
        if (elem != NULL) {
            p_apilar(aux, elem);
        }
    }*/

    return r;
    /*return aux(si la quiero invertida)(oppcional).*/
}

Pila eliminar_ocurrencias_recursivo(Pila p, int e){
    Pila aux = p_crear();
    Pila r = p_crear();
    TipoElemento elem;
    recursion(p,e,aux,r,elem); //funcion que realiza la recursion para encontrar r.
    recuperar_p(p,aux,elem); //funcion para restaurar el valor inicial de la pila p usando recursividad.
    return r;

}

void recursion(Pila p, int e,Pila aux,Pila r,TipoElemento elem){
    if (p_es_vacia(p) == true){ //condicion de corte.
        return;
    }
    elem = p_desapilar(p);
    p_apilar(aux, elem);
    if(elem->clave != e){
        p_apilar(r,elem);
    }
    recursion(p,e,aux,r,elem);

}
void recuperar_p(Pila p,Pila aux,TipoElemento elem){
    if(p_es_vacia(aux) == true){ //condicion de corte.
        return;
    }

    elem = p_desapilar(aux);
    p_apilar(p,elem);
    recuperar_p(p,aux,elem);

}
Pila llenar() {
    Pila p1 = p_crear();
    int cantidad_num;
    int numero;
    int result;

    // Validar la cantidad de numeros a apilar
    do {
        printf("Ingrese cantidad de numeros a apilar (n>0): ");
        result = scanf("%d", &cantidad_num);

        // Verificar que sea un numero entero valido y positivo
        if (result != 1 || cantidad_num <= 0) {
            printf("Error: Por favor, ingrese un numero entero positivo.\n");

            // Limpiar el buffer de entrada
            while (getchar() != '\n');
        }
    } while (result != 1 || cantidad_num <= 0);

    for (int i = 1; i <= cantidad_num; i++) {
        do {
            printf("Ingrese el numero %d: ", i);
            result = scanf("%d", &numero);

            // Verificamos que sea un numero entero valido
            if (result != 1) {
                printf("Error: Entrada no valida. Por favor, ingrese un numero entero.\n");

                // Limpiar el buffer de entrada.
                while (getchar() != '\n');
            }
        } while (result != 1);  // Repetir mientras no se ingrese un numero valido

        p_apilar(p1, te_crear(numero));
    }

    return p1;
}




int main() {
    Pila p = llenar();
    p_mostrar(p);

    int numero;
    int result;

    // Validamos la entrada de numero.
    do {
        printf("Ingrese el numero a eliminar de la lista: ");
        result = scanf("%d", &numero);


        if (result != 1) {
            printf("Error: Entrada no valida. Por favor, ingrese un numero entero.\n");


            while (getchar() != '\n'); //limpiamos el buffer de entrada.
        }
    } while (result != 1); // Repetir mientras la entrada no sea valida

    Pila r = eliminar_ocurrencias_recursivo(p, numero);
    //Pila r = eliminar_ocurrencias(p, numero); //descomentar para usar.
    printf("La pila sin las ocurrencias es: \n");
    p_mostrar(r);
    printf("La pila original es: \n");
    p_mostrar(p);

    return 0;
}
