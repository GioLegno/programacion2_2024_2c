#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tp4.h"
#include "tipo_elemento.h"

bool ColasIguales(Cola c1, Cola c2) {
    TipoElemento x1, x2;
    Cola aux = c_crear();
    bool Resultado = true;

    while (!c_es_vacia(c1) && !c_es_vacia(c2)) {
        x1 = c_desencolar(c1);
        x2 = c_desencolar(c2);

        c_encolar(aux, x1);
        c_encolar(aux, x2);

        if (x1->clave != x2->clave) {
            Resultado = false;
            break;
        }
    }

    if (!c_es_vacia(c1) || !c_es_vacia(c2)) {
        Resultado = false;
    }

    while (!c_es_vacia(aux)) {
        x1 = c_desencolar(aux);
        x2 = c_desencolar(aux);
        c_encolar(c1, x1);
        c_encolar(c2, x2);
    }

    return Resultado;
}

void IniciarEjercicio3(){
    bool b;
    int n, m;

    Cola c1 = c_crear();
    Cola c2 = c_crear();

    printf("\n");
    printf("Cargar dos colas, luego visualizara si sus contenidos son iguales tanto en posicion como en datos");
    printf("\n");

    printf("Proceder con la carga de la cola 1 (MAX 10)\n");
    printf("\n");

    int cant_validos_c1 = 0;
    do {
        b = ingresoEntero(&n);
        if (b){
          c_encolar(c1, te_crear(n));
          cant_validos_c1++;
        }
    } while (b && cant_validos_c1 < 10);

    int cant_validos_c2 = 0;

    printf("Proceder con la carga de la cola 2 (MAX 10)\n");
    do {
        b = ingresoEntero(&m);
        if (b){
            c_encolar(c2, te_crear(m));
            cant_validos_c2++;
        }
    } while (b && cant_validos_c2 < 10);

    bool resu = ColasIguales(c1, c2);
    printf("\n");
    if(resu){
      printf("Las colas son iguales\n");
    } else {
      printf("Las colas son distintas\n");
    }
}
