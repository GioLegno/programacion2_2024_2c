
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacion.h"
#include "conjuntos.h"
#include "listas.h"

Conjunto cargar_conjunto(Conjunto conjunto);
bool TipoSubConjuntoABC(Conjunto a, Conjunto b, Conjunto c);
bool TipoSubConjuntoBAC(Conjunto b, Conjunto a, Conjunto c);
bool TipoSubConjuntoCAB(Conjunto c, Conjunto a, Conjunto b);



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


// Ejemplo: si A = (3, 4, 5) y B = (1,2,3,4,5,6,7,8,9) y C = (2,4,6,8,7) entonces a  “A” es un
// subconjunto total “B” porque todos los elementos de “A” están en “B”,  “C” es un
// subconjunto total de “B” porque todos los elementos de “C” están en “B”.  A su vez
// “B” es un subconjunto parcial de “C” porque al menos la mitad de los elementos de
// “B” están en “C”

bool TipoSubConjuntoABC(Conjunto a, Conjunto b, Conjunto c){

    int cantidada = cto_cantidad_elementos(a);
    int cantidadb = cto_cantidad_elementos(b);
    int cantidadc = cto_cantidad_elementos(c);
    TipoElemento TE;
    float contadorb=0;
    float contadorc=0;
    float suma;

    float diva=cantidada/2.0;
    for (int i = 1; i <= cantidada; i++)
    {
        TE= cto_recuperar(a,i);
        if (cto_pertenece(b, TE->clave)) contadorb++;
        if (cto_pertenece(c, TE->clave)) contadorc++;

    }
    if (contadorb==cantidada)
    {
        printf("A es SubConjunto Total de B porque todos los elementos de A estan en B\n");
    }else if (contadorb>diva)
    {
        printf("A es SubConjunto Parcial de B porque al menos la mitad de los elementos A están en B\n");
    }
    if (contadorc==cantidada)
    {
        printf("A es SubConjunto Total de C porque todos los elementos de A estan en C\n");
    }else if (contadorc>diva)
    {
        printf("A es SubConjunto Parcial de C porque al menos la mitad de los elementos A están en C\n");
    }else{return false;}
    return true;
}

bool TipoSubConjuntoBAC(Conjunto b, Conjunto a, Conjunto c){

    int cantidada = cto_cantidad_elementos(a);
    int cantidadb = cto_cantidad_elementos(b);
    int cantidadc = cto_cantidad_elementos(c);
    TipoElemento TE;
    float contadora=0;
    float contadorc=0;

    float divb = cantidadb/2.0;

    for (int i = 1; i <= cantidadb; i++)
    {
        TE= cto_recuperar(b,i);
        if (cto_pertenece(a, TE->clave)) contadora++;
        if (cto_pertenece(c, TE->clave)) contadorc++;

    }
    if (contadora==cantidadb)
    {
        printf("B es SubConjunto Total de A porque todos los elementos de B estan en A\n");
    }else if (contadora>divb)
    {
        printf("B es SubConjunto Parcial de A porque al menos la mitad de los elementos B están en A\n");
    }
    if (contadorc==cantidadb)
    {
        printf("B es SubConjunto Total de C porque todos los elementos de B estan en C\n");
    }else if (contadorc>divb)
    {
        printf("B es SubConjunto Parcial de C porque al menos la mitad de los elementos B están en C\n");
    }else{return false;}
    return true;
}

bool TipoSubConjuntoCAB(Conjunto c, Conjunto a, Conjunto b){

    int cantidada = cto_cantidad_elementos(a);
    int cantidadb = cto_cantidad_elementos(b);
    int cantidadc = cto_cantidad_elementos(c);
    TipoElemento TE;
    float contadora=0;
    float contadorb=0;
    float divc = cantidadc/2.0;
    for (int i = 1; i <= cantidadc; i++)
    {
        TE= cto_recuperar(c,i);
        if (cto_pertenece(a, TE->clave)) contadora++;
        if (cto_pertenece(b, TE->clave)) contadorb++;

    }
    if (contadora==cantidadc)
    {
        printf("C es SubConjunto Total de A porque todos los elementos de C estan en A\n");
    }else if (contadora>divc)
    {
        printf("C es SubConjunto Parcial de A porque al menos la mitad de los elementos C estan en B\n");
    }
    if (contadorb==cantidadc)
    {
        printf("C es SubConjunto Total de B porque todos los elementos de C estan en B\n");
    }else if (contadorb>divc)
    {
        printf("C es SubConjunto Parcial de B porque al menos la mitad de los elementos C estan en B\n");
    }else{return false;}
    return true;
}

int main(){
    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    Conjunto c = cto_crear();
    printf("Conjunto A\n");
    a=cargar_conjunto(a);
    printf("Conjunto B\n");
    b=cargar_conjunto(b);
    printf("Conjunto C\n");
    c=cargar_conjunto(c);
    bool ABC,BAC,CAB;
    ABC=TipoSubConjuntoABC(a,b,c);
    BAC=TipoSubConjuntoBAC(b,a,c);
    CAB=TipoSubConjuntoCAB(c,a,b);
    if(!(ABC&&BAC&&CAB)){printf("ninguno de los conjuntos es subconjunto total del otro");}
    return 0;
}
