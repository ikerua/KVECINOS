#ifndef DISTANCIA_H
#define DISTANCIA_H
/**
 * @file distancia.h
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//HEADERS NECESARIOS 
#include "pista.h"
#include <stdio.h>
//DEFINICION DE DISTANCIA
typedef struct distancia{
     float dist;
     int clase;
 }Distancia; 
 
 

/*
 * ACCION : calcular distancia Euclidiana
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia euclidiana entre las dos pistas 
 * DESCRIPCION: 
 */
Distancia calcularDistanciaEuclidiana(Pista ,Pista);
/*
 * ACCION : calcular distancia manhattan
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia manhattan entre las dos pistas 
 * DESCRIPCION: 
 */
Distancia calcularDistanciaManhattan(Pista nueva,Pista x);
#endif

