/**
 * FILE: matriz.c
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * DESCRIPCION:
 */
//HEADERS NECESARIOS

#include "matriz.h"
#include <stdio.h>

//IMPLEMENTACION DE ACCION EXPORTADA
/**
 * ACCION: imprimeMatriz
 * ENTRADA: una matriz 
 *  REQUISITOS: debe estar inicializada
 * SALIDA: la matriz por pantalla
 * DESCRIPCION: La funcion recorre la matriz imprimiendo los valores uno a uno
 * 
 */
void imprimeMatriz(matriz m){
    for(int i=0;i<FILA;i++){
        printf("Example %d",i);
        for (int j= 0; j<COLUMNA; j++){
            printf("\t %.8f \t", m[i][j]);
        }
        printf("\n");
    }
}