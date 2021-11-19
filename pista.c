/**
 * @file pista.c
 * @brief 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
//HEADERS NECESARIOS 
#include "pista.h"
//DEFINICIOM DE FUNCIONES EXPORTADAS
/*
 * ACCION : leerPista
 * ENTRADAS: Una matriz y una variable tipo Pista
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo Pista queda almacenada la pista i de la matriz
 * DESCRIPCION: 
 */
Pista leerPista(matriz m,int fila){
    Pista p;
    for(int i=0;i<28;i++){
        p.datos[i]=m[fila][i];
    }
    p.clase=m[fila][COLUMNA-1];
    return p;
}

/*
 * ACCION : normalizarPista
 * ENTRADAS: Una pista y una tabla de maximos y minimos
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo Pista queda almacenada la pista normalizada
 * DESCRIPCION: 
 */
void normalizarPista(Pista *p, maxYmin m){
    for(int i=0;i<COLUMNA-1;i++)
        p->datos[i]=(p->datos[i]-m[1][i])/(m[0][i]-m[1][i]);

}