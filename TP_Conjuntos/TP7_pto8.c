// Dados  dos  conjuntos  de  números  naturales  se  pide  determinar  si  son  iguales  sin 
// importar la posición de sus elementos.  Determinar la complejidad algorítmica. 
 
// Ejemplo: si A = (3, 4, 5, 6) y B = (3, 5, 4, 6) entonces a “A” es igual “B” y viceversa

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "conjuntos.h"
#include "listas.h"

Conjunto cargar_conjunto(Conjunto conjunto);
bool ConjuntosIguales(Conjunto a, Conjunto b);

Conjunto cargar_conjunto(Conjunto conjunto){

    printf("Cuantos elementos desea cargar:\n");
    int clave = entero_entre(0,100);
    fflush(stdin);
    TipoElemento TE;
    for (int i = 1; i <= clave; i++)
    {
        printf("Ingrese %d clave:\n",i);
        int clavela=entero_entre(1,1000);
        fflush(stdin);
        TE = te_crear(clavela);
        if (!cto_pertenece(conjunto, clavela));
        {
            cto_agregar(conjunto, TE);
        }
    }
    return conjunto;
}


bool ConjuntosIguales(Conjunto a, Conjunto b){
    int canta=cto_cantidad_elementos(a);
    int cantb=cto_cantidad_elementos(b);
    int mayor;
    TipoElemento Ta;
    TipoElemento Tb;
    bool resu;
    // if (canta>cantb)
    // {
    //     mayor=canta;
    // }else mayor= cantb;
    if (canta != cantb) return false;
    
    for (int i = 1; i <= canta; i++)
    {
        Ta = cto_recuperar(a, i);
        resu=false;
        for (int j = 1; j <= cantb; j++)
        {
            Tb = cto_recuperar(b, j);
            if (Ta->clave == Tb->clave) resu=true;
            if (resu==false && j == cantb) return false;
        }
    }
    return resu;
}

int main(){

    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    printf("Conjunto A\n");
    a=cargar_conjunto(a);
    printf("Conjunto B\n");
    b=cargar_conjunto(b);
    bool iguales=ConjuntosIguales(a,b);
    if (iguales==true)
    {
        printf("Son iguales\n");
    }else printf("No son iguales\n");
    printf("La complejidad es de O(n2)\n");
    
    return 0;
}