// 2. Desarrollar un algoritmo que dado dos conjuntos de elementos tipo numérico (clave)
// verifique las operaciones de Unión, Intersección, Diferencia y Pertenencia.
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "conjuntos.h"
#include "listas.h"

Conjunto cargar_conjunto(Conjunto conjunto);

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

int main(){
    int accion;
    Conjunto ConjuntoA = cto_crear();
    Conjunto ConjuntoB = cto_crear();
    Conjunto Resu = cto_crear();
    printf("Conjunto 1: \n");
    ConjuntoA=cargar_conjunto(ConjuntoA);
    printf("Conjunto 2: \n");
    ConjuntoB=cargar_conjunto(ConjuntoB);

    cto_mostrar(ConjuntoA);
    cto_mostrar(ConjuntoB);

    do
    {
        printf("1:Union / 2:Interseccion / 3:Diferencia /4:Pertenencia\n");
        printf("\t\t0:Salir\n");
        accion = entero_entre(0,4);
        fflush(stdin);
        switch (accion)
        {
        case 1:
            Resu = cto_union(ConjuntoA, ConjuntoB);
            if (!cto_es_vacio(Resu)){
               cto_mostrar(Resu);
            } else printf("CONJUNTO VACIO!\n");
            break;
        case 2:
            Resu = cto_interseccion(ConjuntoA, ConjuntoB);
            if (!cto_es_vacio(Resu)){
               cto_mostrar(Resu);
            } else printf("CONJUNTO VACIO!\n");

            break;
        case 3:
            Resu = cto_diferencia(ConjuntoA, ConjuntoB);
            if (!cto_es_vacio(Resu)){
               cto_mostrar(Resu);
            } else printf("CONJUNTO VACIO!\n");
            break;
        case 4:
            printf("\nIngrese una clave a buscar:\n");
            int clave=entero_entre(0,1000);
            fflush(stdin);
            if(cto_pertenece(ConjuntoA, clave)){
                cto_mostrar(ConjuntoA);
                printf("La clave %d pertenece al conjunto A\n", clave);
            }if(cto_pertenece(ConjuntoB, clave)){
                cto_mostrar(ConjuntoB);
                printf("La clave %d pertenece al conjunto B\n",clave);
            } else printf("La clave no pertenece a ningun cunjunto.\n");
            break;
        }

    } while (accion!=0);

    return 0;
}



