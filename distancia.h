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
 * Funcion : Sacar distancias
 * ENTRADAS: Una lista de pistas y una pista 
 *  REQUISITOS: Ninguno
 * SALIDA:Una lista ordenada de las distancias
 * DESCRIPCION: 
 */
tipoListaOrdenadaDistancias sacarDistancias(tipoLista listaPistas,Pista nueva);

/*
 * ACCION : calcular distancia
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia entre las dos pistas 
 * DESCRIPCION: 
 */
void calcularDistancia(Pista ,Pista ,Distancia);



