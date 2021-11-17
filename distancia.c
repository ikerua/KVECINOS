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
#include "listaOrdenadaDistancias.h"
#include "listaPista.h"
#include <stdio.h>
#include <math.h>

//IMPLEMENTACION DE FUNCIONES/ACCIONES EXPORTADAS
/*
 * Funcion : Sacar distancias
 * ENTRADAS: Una lista de pistas y una pista 
 *  REQUISITOS: Ninguno
 * SALIDA:Una lista ordenada de las distancias
 * DESCRIPCION: 
 */
tipoListaOrdenadaDistancias sacarDistancias(tipoLista listaPistas,Pista nueva){
    celdaLista *p=listaPistas->ini;
    tipoListaOrdenadaDistancias listaDistancias;
    Distancia d;
    nuevaListaOrdenada(&listaDistancias);
    while(p!=NULL){
        calcularDistancia(nueva,p->pista,d);
        insertarListaOrdenada(&listaDistancias,d);
        p=p->sig;
    }
    return listaDistancias;
}
/*
 * ACCION : calcular distancia
 * ENTRADAS: Dos pistas 
 *  REQUISITOS: Ninguno
 * SALIDA:En la variable tipo distancia queda almacenada la distancia entre las dos pistas 
 * DESCRIPCION: 
 */
void calcularDistancia(Pista nueva,Pista x,Distancia d){
    float aux=0;
    for(int i=0;i<len(nueva.datos);i++){
        aux+=pow(nueva.datos[i]-x.datos[i],2);
    }
    d.dist=sqrt(aux);
    d.clase=x.clase;
}

