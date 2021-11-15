/**
 * @file distancia.c
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//HEADERS NECESARIOS 
#include "distancia.h"
#include <stdio.h>
#include <math.h>
/*//DEFINICION DE DISTANCIA
typedef struct distancia{
     float dist;
     int clase;
 }Distancia; 
 */
 
/*
 * ACCION : calcular distancia
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia entre las dos pistas 
 * DESCRIPCION: 
 */
void calcularDistancia(Pista nueva,Pista x,Distancia d){
    d.dist=0;
    for(int i=0;i<len(nueva.datos);i++){
        d.dist+=sqrt(pow(nueva.datos[i],2)+pow(x.datos[i],2));
    }
    d.clase=x.clase;
}
