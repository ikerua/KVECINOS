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
 * ACCION : calcular distancia
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia entre las dos pistas 
 * DESCRIPCION: 
 */
Distancia calcularDistancia(Pista ,Pista);



