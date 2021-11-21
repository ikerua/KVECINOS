/**
 * FILE: matriz.h
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * DESCRIPCION:
 */

//DECLARACION DE CONSTANTES
#define FILA 1000
#define COLUMNA 29
//DEFINICION DE MATRIZ
typedef double matriz[FILA][COLUMNA];
//DECLARACION DE FUNCIONES EXPORTADAS
/**
 * ACCION: imprimeMatriz
 * ENTRADA: una matriz 
 *  REQUISITOS: debe estar inicializada
 * SALIDA: la matriz por pantalla
 * DESCRIPCION: La funcion recorre la matriz imprimiendo los valores uno a uno
 * 
 */
void imprimeMatriz(matriz);