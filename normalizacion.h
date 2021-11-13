/*
 * 
 */

//HEADERS NECESARIOS
#include <stdio.h>
#include <stdlib.h>


//DEFINICION DE CONSTANTES
#define FILA 1000
#define COLUMNA 29
//DEFINICION DE MATRIZ
typedef float matriz[COLUMNA][FILA];

float minimo(matriz m,int columna);

float maximo(matriz m,int columna);

float obtnormalizado(float valor, float maximo, float minimo);

void normalizarMatriz(matriz m);

void introEnMatriz(matriz m, FILE *);