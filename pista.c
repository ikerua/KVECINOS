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
 * ENTRADAS: Un archivo de texto en formato txt y una variable de tipo Dato
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo Pista queda almacenada la pista i del fichero f
 * DESCRIPCION: 
 */
void leerPista(matriz m,Pista p, int fila){
    for(int i=0;i<28;i++){
        p.datos[i]=m[fila][i];
    }
    p.clase=m[fila][COLUMNA-1];
}
