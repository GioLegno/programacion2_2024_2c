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
/*6. Dados dos conjuntos de números naturales se pide determinar si uno es subconjunto
propio del otro. Determinar la complejidad algorítmica.
Ejemplo: si A = (3, 4, 5) y B = (1,2,3,4,5,6,7,8,9) entonces a “A” es un subconjunto
propio del conjunto “B” porque todos los elementos de “A” están en “B” pero “A” <>
“B”.*/
bool iguales(Conjunto a, Conjunto b){
    int canta=cto_cantidad_elementos(a);
    int cantb=cto_cantidad_elementos(b);
    int mayor;
    TipoElemento Ta;
    TipoElemento Tb;
    bool resu;
    if (canta != cantb) return false;
    for (int i = 1; i <= canta; i++){
        Ta = cto_recuperar(a, i);
        resu=false;
        for (int j = 1; j <= cantb; j++){
            Tb = cto_recuperar(b, j);
            if (Ta->clave == Tb->clave) resu=true;
            if (resu==false && j == cantb) return false;
        }
    }
    return resu;
}
bool subconjuntoPropio(Conjunto A,Conjunto B){
    Conjunto C= cto_interseccion(A,B);

    return iguales(A,C);
}
/*bool subconjuntoPropio(Conjunto A, Conjunto B) {
    Conjunto interseccion = cto_interseccion(A, B);
    if (iguales(A, interseccion) && !iguales(B, interseccion)) {
        // A es subconjunto propio de B
        return true;
    }
    if (iguales(B, interseccion) && !iguales(A, interseccion)) {
        // B es subconjunto propio de A
        return true;
    }
    return false;
}*/

int main(){
    Conjunto a=cto_crear();
    Conjunto b=cto_crear();
    printf("CONJUNTO A\n");
    a=cargar_conjunto(a);
     printf("CONJUNTO B\n");
    b=cargar_conjunto(b);
    if(subconjuntoPropio(a,b)){printf("'A' es un subconjunto propio del conjunto 'B'\n");}
    else{printf("'A' no es un subconjunto propio del conjunto 'B'\n");}
    if(subconjuntoPropio(b,a)){printf("'B' es un subconjunto propio del conjunto 'A'\n");}
    else{printf("'B' no es un subconjunto propio del conjunto 'A'\n");}

    printf("La complejidad total de subconjuntoPropio es O(n*m), n siendo el tamanio del Conjunto A y m el tamanio del Conjunto B (COMPLEJIDAD CUADRATICA O BILINEAL)");
    return 0;
}
