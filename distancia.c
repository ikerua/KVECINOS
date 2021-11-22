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

//IMPLEMENTACION DE FUNCIONES/ACCIONES EXPORTADAS

/*
 * ACCION : calcular distancia
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia entre las dos pistas 
 * DESCRIPCION: 
 */
Distancia calcularDistancia(Pista nueva,Pista x){
    Distancia d;
    float aux=0;
    for(int i=0;i<NUMDATOS;i++){
        aux+=pow(nueva.datos[i]-x.datos[i],2);
    }
    d.dist=sqrt(aux);
    d.clase=x.clase;
    return d;
}

