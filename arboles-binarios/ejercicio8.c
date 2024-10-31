#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "colas.h"
#include "listas.h"
//#include "pilas.h"
#include "nodo.h"
#include "arbol-binario.h"
//#include "arbol-avl.h"
//#include "arbol-binario-busqueda.h"
#include "tipo_elemento.h"
#include "tp5.h"

void cargar_arbol_binario_ej8(ArbolBinario A);
void Cargar_SubArbol_ej8(ArbolBinario A, NodoArbol N, int sa);
int calcular_altura(ArbolBinario a);
int calcular_altura_r(NodoArbol n);
int encontrar_nivel_r(NodoArbol n, NodoArbol clave_buscada, int nivel_actual);
int nivel(ArbolBinario a,NodoArbol clave_buscada);
Lista n_internos(ArbolBinario a);
void n_interos_r(NodoArbol n, Lista l, ArbolBinario a);
bool hojas_nivel(ArbolBinario a);
void hojas_nivel_r(NodoArbol n, Lista l, ArbolBinario a);

//Funciones para cargar datos en el arbol.
void Cargar_SubArbol_ej8(ArbolBinario a, NodoArbol N, int sa){
      /*ENTRADA:  N -> nodo padre con el cual se conesta el nuevo nodo
                pos -> entero que toma valores -1,0 y 1 para indicar la posicion den la que se coloca el nuevo nodo
                a -> arbol en el que se cargan los datos*/
    int val;//entero que resive los datos por pantalla
    int p;

    if (a_es_vacio(a)) printf("RAIZ: \n");
    else if(sa == 1) printf("HERMANO DERECHO de %d: \n", n_recuperar(N)->clave);
    else if(sa == -1) printf("HIJO IZQUIERDO de %d: \n", n_recuperar(N)->clave);
    bool f =ingresoEntero(&val);
    if(f){//si el valor no es nulo(si se quiere cargar el nodo)
        NodoArbol N1;
            if(sa == 0){N1 =a_establecer_raiz(a,te_crear(val));}//si el nodo a cargar es la raiz
            else if(sa == 1){
                N1=a_conectar_hd(a,N,te_crear(val));}
            else if(sa == -1){
                N1=a_conectar_hi(a,N,te_crear(val)); }
            //llamadas recurcivas para seguir cargando tanto por der como por iz
        Cargar_SubArbol_ej8(a,N1,1);
        Cargar_SubArbol_ej8(a,N1,-1);
    }
}
void cargar_arbol_binario_ej8(ArbolBinario A){
    Cargar_SubArbol_ej8(A,NULL,0);
}

//EJERCICIO 8. Dado un árbol “n-ario” se pide:
//a) Determinar la altura del mismo.
int calcular_altura_r(NodoArbol n)
{
    if (n == NULL)
    {
        return 0;  // Si el nodo es NULL, la altura es 0
    }

    // Calculamos la altura del hijo izquierdo (hijos del nodo)
    int altura_hijos = calcular_altura_r(n_hijoizquierdo(n));

    // Calculamos la altura de los hermanos (hijos derechos)
    int altura_hermanos = calcular_altura_r(n_hijoderecho(n));
    int max_altura;
    if (altura_hijos < altura_hermanos)
    {
        return altura_hermanos;
    }
    else
    {
        return 1 + altura_hijos;
    }
    //La altura total es 1 (el nodo actual) + la altura más alta de los hijos
    //return(1 + max_altura);

    //metodo con operador ternario (no se si es valido utilizarlo).
    //return 1 + (altura_hijos > altura_hermanos ? altura_hijos : altura_hermanos);
}
int calcular_altura(ArbolBinario a)
{
    int p = calcular_altura_r(a_raiz(a));
    return p;
}

//b) Determinar el nivel de un nodo.
int encontrar_nivel_r(NodoArbol n, NodoArbol clave_buscada, int nivel_actual)
{
    if (n == NULL)
    {
        return -1;  // Nodo no encontrado
    }

    if (n_recuperar(n)->clave == n_recuperar(clave_buscada)->clave)
    {
        return nivel_actual;  // Nodo encontrado, devolvemos el nivel
    }

    // Buscar en el subárbol izquierdo (hijos)
    int nivel_hijos = encontrar_nivel_r(n_hijoizquierdo(n), clave_buscada, nivel_actual + 1);
    if (nivel_hijos != -1)
    {
        return nivel_hijos;  // Si encontramos el nodo en los hijos, devolvemos el nivel
    }

    // Buscar en el subárbol derecho (hermanos) sin incrementar el nivel
    return encontrar_nivel_r(n_hijoderecho(n), clave_buscada, nivel_actual);
}
int nivel(ArbolBinario a,NodoArbol clave_buscada)
{
    //El nivel de la raiz es cero.
    int p = encontrar_nivel_r(a_raiz(a),clave_buscada,0);
    return p;

}

//c) Listar todos los nodos internos (solo las claves).
void n_interos_r(NodoArbol n, Lista l, ArbolBinario a)
{
    if (n == NULL) return;
    if (n_hijoizquierdo(n) != NULL && n!= a_raiz(a))
    {
        l_agregar(l,n_recuperar(n));
    }
    n_interos_r(n_hijoizquierdo(n),l,a);
    n_interos_r(n_hijoderecho(n),l,a);

}
Lista n_internos(ArbolBinario a)
{
    Lista l = l_crear();
    n_interos_r(a_raiz(a),l,a);
    return l;
}

//d) Determinar si todas las hojas están al mismo nivel.
void hojas_nivel_r(NodoArbol n, Lista l, ArbolBinario a) {//crea una lista con el nivel de todas las hojas.
    if (n == NULL) return;
    if (n_hijoizquierdo(n) == NULL)
    {
        int ni = nivel(a,n);
        l_agregar(l,te_crear(ni));
    }
    hojas_nivel_r(n_hijoizquierdo(n),l,a);
    hojas_nivel_r(n_hijoderecho(n),l,a);
}

bool hojas_nivel(ArbolBinario a)
{
    Lista l = l_crear();
    hojas_nivel_r(a_raiz(a),l,a);
    Iterador it = iterador(l);
    while (hay_siguiente(it)) //recorro la lista e identifico si todos los niveles son iguales.
    {
        TipoElemento x = siguiente(it);
        if(hay_siguiente(it) && x->clave != siguiente(it)->clave )
        {
            return false;
        }
    }
    return true;


}
//INICIALIZADORES DE EJERCICIOS.

void Iniciar8A(){
    printf("Ingresar un arbol n-ario, para determinar la altura del mismo. \n");
    ArbolBinario a = a_crear();
    cargar_arbol_binario_ej8(a);
    int p = calcular_altura(a);
    printf("La altura del arbol ingresado es de: %d \n",p);
}

void Iniciar8B(){
    printf("Ingresar un arbol n-ario, para determinar el nivel de un nodo especifico. \n");
    ArbolBinario a = a_crear();
    cargar_arbol_binario_ej8(a);
    int clave;
    printf("Ingrese la clave del nodo a calcular el nivel (entero): \n");
    ingresoEntero(&clave);
    NodoArbol nodo = n_crear(te_crear(clave));
    int n_nivel = nivel(a,nodo);
    if(n_nivel != -1){
       printf("EL nivel del nodo %d es: %d\n",clave,n_nivel);
    } else printf("El nodo no se encuentra en el arbol.\n");
}
void Iniciar8C(){
    printf("Ingresar un arbol n-ario, para determinar una lista con sus nodos internos. \n");
    ArbolBinario a = a_crear();
    cargar_arbol_binario_ej8(a);
    Lista internos = n_internos(a);
    printf("Los nodos internos (claves) son: \n");
    l_mostrar(internos);
}
void Iniciar8D(){
    printf("Ingresar un arbol n-ario, para determinar si todas sus hojas estan en el mismo nivel. \n");
    ArbolBinario a = a_crear();
    cargar_arbol_binario_ej8(a);
    bool niv_iguales = hojas_nivel(a);
    if (niv_iguales){
        printf("TODOS LOS NIVELES DE LAS HOJAS SON IGUALES!! \n");
    } else printf("LOS NIVELES DE LAS HOJAS NO SON IGUALES. \n");
}

