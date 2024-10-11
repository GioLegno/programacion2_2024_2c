#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tp4.h"
#include "tipo_elemento.h"

void Clientes(Cola c1, Cola c2, Cola c3, int q);

void Clientes(Cola c1, Cola c2, Cola c3, int q) {
    TipoElemento x1, x2, x3;
    int contador_c1 = 0, contador_c2 = 0, contador_c3 = 0;
    int cliente_c1 = 1, cliente_c2 = 1, cliente_c3 = 1;

    do {
        if (!c_es_vacia(c1)) {
            x1 = c_desencolar(c1);
            contador_c1 = x1->clave;

            if (contador_c1 <= q) {
                printf("Cliente %d de la Cola 1 fue atendido\n", cliente_c1);
                cliente_c1++;
            } else {
                contador_c1 -= q;
                c_encolar(c1, te_crear(contador_c1));
            }
        }

        if (!c_es_vacia(c2)) {
            x2 = c_desencolar(c2);
            contador_c2 = x2->clave;

            if (contador_c2 <= q) {
                printf("Cliente %d de la Cola 2 fue atendido\n", cliente_c2);
                cliente_c2++;
            } else {
                contador_c2 -= q;
                c_encolar(c2, te_crear(contador_c2));
            }
        }

        if (!c_es_vacia(c3)) {
            x3 = c_desencolar(c3);
            contador_c3 = x3->clave;

            if (contador_c3 <= q) {
                printf("Cliente %d de la Cola 3 fue atendido\n", cliente_c3);
                cliente_c3++;
            } else {
                contador_c3 -= q;
                c_encolar(c3, te_crear(contador_c3));
            }
        }

    } while (!c_es_vacia(c1) || !c_es_vacia(c2) || !c_es_vacia(c3));

}

void IniciarEjercicio7(){
    bool b;
    int n, m, p;

    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();
    printf("\n");
    printf("Cargue tres colas y una cantidad de tiempo disponible para que el encargado atienda a cada una de ellas. \n");
    printf("\n");

    printf("Proceder con la carga de la cola 1 (MAX 10)\n");

    int cant_validos_c1 = 0;
    do {
        b = ingresoEntero(&n);
        if (b){
            c_encolar(c1, te_crear(n));
            cant_validos_c1++;
        };
    } while (b && cant_validos_c1 < 10);


    printf("Proceder con la carga de la cola 2 (MAX 10)\n");
    int cant_validos_c2 = 0;
    do {
        b = ingresoEntero(&m);
        if (b){
             c_encolar(c2, te_crear(m));
             cant_validos_c2++;
        };
    } while (b && cant_validos_c2 < 10);


    printf("Proceder con la carga de la cola 3 (MAX 10)\n");
    int cant_validos_c3 = 0;
    do {
        b = ingresoEntero(&p);
        if (b){
            c_encolar(c3, te_crear(p));
            cant_validos_c3++;
        };

    } while(b && cant_validos_c3 < 10);

    printf("\n");
    printf("Ingrese tiempo disponible para atender a cada cliente\n");
    int tiempo = ingresoUnSoloEntero();

    Clientes(c1, c2, c3, tiempo);
}
