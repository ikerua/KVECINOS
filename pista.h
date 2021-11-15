/*
 * FICHERO: pista.h
 * VERSION: 1.0.0
 * Este módulo contiene el tipo de datos que utilizaremos en el trabajo.
 * Este tipo es una tupla de 28 reales correspondientes a los 28 campos distintos que definen una cancion. 
 * Ademas de un ultimo tipo que sera la clase a la que pertenecen segun el genero musical 
 * 
 * Definiremos las clases de cada tipo con un entero del 0 al 9 segun este criterio
 * blues=0; classical=1; country=2; disco=3; hiphop=4
 * jazz=5; metal=6; pop=7; reggae=8; rock=9
 * 
 */
//HEADERS NECESARIOS
#include <stdio.h>
#include <stdlib.h>
//DEFINICION DE COSNTANTE
#define NUMDATOS 28
#define FILA 1000
#define COLUMNA 29
//DEFINICION DE MATRIZ
typedef float matriz[FILA][COLUMNA];

//DEFINICION DE PISTA
typedef struct pista{
     float datos[NUMDATOS];
     int clase;
 }Pista; 
 
 
/*
 * ACCION : leerPista
 * ENTRADAS: Un archivo de texto en formato txt y una variable de tipo Dato
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo Pista queda almacenada la pista i del fichero f
 * DESCRIPCION: 
 */
void leerPista(matriz ,Pista, int);
