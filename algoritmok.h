#ifndef ALGORITMO_K_H
#define ALGORTIMO_K_H
/**
 * @file algoritmok.h
 * DESCRICPION:
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//HEADERS NECESARIOS
#include <stdio.h>
#include "listaOrdenadaDistancias.h"
#include "listaPista.h"

//FUNCIONES EXPORTADAS
/**
 * ACCION: Una lista ordenada de pis
 * ENTRADA:
 *  REQUISITOS: La lista ordenada debe contener las distancias 
 * SALIDA: una clase
 * DESCRIPCION:
 * 
 */
void sacarClase(tipoListaOrdenadaDistancias ,Pista, int);

/*
 * Funcion : Sacar distancias
 * ENTRADAS: Una lista de pistas y una pista 
 *  REQUISITOS: Ninguno
 * SALIDA:Una lista ordenada de las distancias
 * DESCRIPCION: 
 */
tipoListaOrdenadaDistancias sacarDistancias(tipoLista listaPistas,Pista nueva);
#endif