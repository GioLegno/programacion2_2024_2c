/*.Desarrollar  un  algoritmo  que  dada  una colección  de  conjuntos  de  
elementos  tipo numérico (clave) realice las operaciones de Unión e Intersección.*/
#include"conjuntos.h"
#include<stdio.h>
#include "validacion.h"
/**
 * Devuelve la unión de una colección  de  conjuntos.
 *
 * @param conjunto_a conjunto de todos los conjuntos.
 * @param Cant cantidad de conjuntos en el conjunto a.
 * @return una nueva instancia de tipo conjunto que es la unión de una colección  de  conjuntos pasados por parámetro.
 */
Conjunto cto_ctos_union(Conjunto conjunto_a, int Cant){
    Conjunto resu=cto_crear();
    int i=1;
    TipoElemento x;
    while(Cant >= i){
        x=cto_recuperar(conjunto_a,i);
        Conjunto a=(Conjunto)x->valor;
        resu=cto_union(a,resu);
        i++;
    }
    return resu;
}

/**
 * Devuelve la intersección de una colección  de  conjuntos.
 *
 * @param conjunto_a conjunto de todos los conjuntos.
 * @param Cant cantidad de conjuntos en el conjunto a.
 * @return una nueva instancia de tipo conjunto que es la intersección de una colección  de  conjuntos pasados por parámetro.
 */
Conjunto cto_ctos_interseccion(Conjunto conjunto_a, int Cant){
    Conjunto resu=cto_ctos_union(conjunto_a,Cant);
    int i=1;
    TipoElemento x;
    while(Cant > i){
        x=cto_recuperar(conjunto_a,i);
        Conjunto a=(Conjunto)x->valor;
        resu=cto_interseccion(a,resu);
        i++;
    }
    return resu;
}

Conjunto cto_carga(){
    printf("ingrese la cantidad de elementos a cargar:\n");
    int cant=entero_entre(0,100);
    Conjunto resu=cto_crear();
    TipoElemento x;
    int i=-1;
    while(cant>0){
        printf("elemento:\n");
        i=entero_entre(0,10000);
        x=te_crear(i);
        cto_agregar(resu,x);
        cant--;
    }
    return resu;
}

/**
 * Devuelve la carga de una colección  de  conjuntos.
 * 
 * @return una nueva instancia de tipo conjunto que es una colección  de  conjuntos.
 */
Conjunto ctos_carga(int cant){
    int i=1;
    Conjunto resu=cto_crear();
    TipoElemento x;
    while(cant>0){
        printf("Conjunto %i:\n",i);
        x=te_crear_con_valor(i,cto_carga());
        cto_agregar(resu,x);
        i++;
        cant--;
    }
    return resu;
}

int main(){
    printf("ingrese la cantidad de conjuntos a cargar:\n");
    int cant=entero_entre(0,10);
    Conjunto a=ctos_carga(cant);
    printf("El conjunto union de los conjuntos es:\n");
    cto_mostrar(cto_ctos_union(a,cant));
    printf("El conjunto interseccion de los conjuntos es:\n");
    cto_mostrar(cto_ctos_interseccion(a,cant));
}