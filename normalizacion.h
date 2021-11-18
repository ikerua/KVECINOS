#ifndef NORMALIZACION_H
#define NORMALIZACION_H
/*
 * 
 */

//HEADERS NECESARIOS
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

float minimo(matriz m,int fila);

float maximo(matriz m,int fila);

float obtnormalizado(float valor, float maximo, float minimo);

void normalizarMatriz(matriz m);

void introEnMatriz(matriz m, FILE *);

#endif