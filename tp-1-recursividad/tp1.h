#include <stdbool.h>

//1)buscar palidromo
bool espalindromoaux(char *cadena, int inicio, int fin);
bool palindromo(char *cadena);
void eliminarEspacios(char *cadena);
void pasarminusculas(char *palabra);
void iniciarPalidromo();


//2) producto
int producto(int m, int n);
void eliminarEspaciosProducto(char* string);
int esNumeroValido(char* string);
int validarNumero(char* cadena2);
void iniciarProducto();


//3) fibo
int validarK();
int terminoSerieFibonacci(int k);
void iniciarTerminoSerieFibonacci();


//4) division
int validarM();
int validarN();
float division(int m, int n);
void iniciarDivision();


//5) agregarSeparadorMiles
void agregarSeparadorMiles(char *numero, int tam, int ultima_pos, int contador, char *arr_aux, int tam_arr_aux);
void iniciarAgregarSeparadorMiles();


//6) mafiaChina
void mostrarMaficaChina(int n, int izquierda, int derecha);
void iniciarMafiaChina();


//7) ondaDigital
void ondaDigital(char onda[], int inicio, int fin);
void iniciarOndaDigital();


//8) subconjuntosQueSumanN
void subconjuntosQueSumanN(int vec[], int n, int tam, int val_inicial, int sumatoria, int arr_aux[], int aux_tam);
void iniciarSubconjuntosQueSumanN();


//9) funcion multiplo de 7
bool divisiblePor7(int entero);
int validarM7();
void iniciarDivisiblePor7();


//10) fragmentacion
void agregarValor(int valor, int lista[], int *pos);
void agregarValor(int valor, int lista[], int *pos);
int *explosion(int n, int b);
void imprimirLista(int indice, int lista[], int pos);
int es_numero(char *cadena);
int validarEntrada();
void iniciarFragmentacion();





