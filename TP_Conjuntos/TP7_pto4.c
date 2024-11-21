#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "conjuntos.h"
#include "listas.h"

// 4. Desarrollar un algoritmo que dado tres conjuntos puedan demostrar la propiedad de la
// transitividad:  “si A es subconjunto de B y B a su vez es subconjunto de C, entonces A
// es subconjunto de C”.
//prototipos
bool transitividad(Conjunto a, Conjunto b, Conjunto c);
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

bool transitividad(Conjunto a, Conjunto b, Conjunto c){
    TipoElemento x;
    int cantidada,cantidadb, cantidadc;
    cantidada= cto_cantidad_elementos(a);
    cantidadb= cto_cantidad_elementos(b);
    cantidadc= cto_cantidad_elementos(c);
    if (cantidada>cantidadb || cantidadb>cantidadc) return false;
    //preguntar si es necesario que a sea menor que b
    //if (cantidada>=cantidadb || cantidadb>=cantidadc) return false;

    for (int i = 1; i <= cantidada; i++)
    {
        x=cto_recuperar(a, i);
        if (cto_pertenece(b, x->clave)!=true) return false;
    }
    for (int i = 1; i <= cantidadb; i++)
    {
        x=cto_recuperar(b, i);
        if (!cto_pertenece(c, x->clave)) return false;
    }
    return true;
}

int main(){
    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    Conjunto c = cto_crear();
    printf("CONJUNTO A\n");
    a=cargar_conjunto(a);
    printf("CONJUNTO B\n");
    b=cargar_conjunto(b);
    printf("CONJUNTO C\n");
    c=cargar_conjunto(c);
    if (transitividad(a,b,c)==true){
        printf("---A es SubConjunto de C---");
    }else printf("---A no es SubConjunto de C---");
    return 0;
}
