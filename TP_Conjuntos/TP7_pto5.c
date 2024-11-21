#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "conjuntos.h"
#include "listas.h"

// 5. Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre 
// dos conjuntos. La diferencia simétrica es una operación entre dos conjuntos donde el 
// conjunto  resultante  está  conformado  por  los  elementos  no  comunes  a  los  dos 
// conjuntos.

// 1,2,3,5,6  -> 5
// 3,2,1      -> 3

//prototipos
Conjunto cargar_conjunto(Conjunto conjunto);
Conjunto diferencia_simetrica(Conjunto a, Conjunto b, Conjunto resu);

Conjunto cargar_conjunto(Conjunto conjunto){
    printf("Cuantos elementos desea cargar:\n");
    int clave = entero_entre(0,100);
    fflush(stdin);
    TipoElemento TE;
    for (int i = 1; i <= clave; i++)
    {
        printf("Ingrese %d clave:\n",i);
        int clavela=entero_entre(0,1000);
        fflush(stdin);
        TE = te_crear(clavela);
        if (!cto_pertenece(conjunto, clavela));
        {
            cto_agregar(conjunto, TE);
        }
    }
    return conjunto;
}

Conjunto diferencia_simetrica(Conjunto a,Conjunto b,Conjunto resu){
    
    TipoElemento xa,xb;   int canta,cantb,mayor;

    canta=cto_cantidad_elementos(a);
    cantb=cto_cantidad_elementos(b);
    
    if (canta>cantb){mayor=canta;} //sacamos el conjunto de mayor tamaño
    else{mayor=cantb;}

    for (int i = 1; i <= mayor; i++) // recorremos el conjunto para comparar con el conjunto b y agregar a resu los que no coinciden
    {
        xa=cto_recuperar(a,i);
        xb=cto_recuperar(b,i);
        if (xa==NULL || xb==NULL){
            if (xa==NULL && (!cto_pertenece(resu,xb->clave))){ 
                cto_agregar(resu,xb);
            }else if(xb==NULL && (!cto_pertenece(resu,xa->clave))){
                cto_agregar(resu,xa);
            }
        }
        else if(xa->clave!=xb->clave){
            if(!cto_pertenece(resu,xa->clave)){
                cto_agregar(resu,xa);
            }
            if (!cto_pertenece(resu,xb->clave)){
                cto_agregar(resu,xb);
            }
        }
    }
    
    return resu;
}


int main(){
    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    Conjunto resu = cto_crear();

    a=cargar_conjunto(a);
    b=cargar_conjunto(b);

    resu=diferencia_simetrica(a,b,resu);
    cto_mostrar(resu);
    
    return 0;
}