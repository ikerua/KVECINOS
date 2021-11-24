/**
 * @file algoritmoWilson.c
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//HEADERS NECESARIOS
#include "algoritmoWilson.h"
#include "algoritmok.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * ACCION: algoritmoWilson
 * ENTRADA: Una lista de Pistas y un entero 
 *  REQUISITOS: La lista de Pistas debe estar inicializada y no ser vacia y el entero debe ser la k mas eficiente para el problema
 * SALIDA: 
 * DESCRIPCION:
 */
void algoritmoWilson(tipoLista * l, int k){
  tipoListaOrdenadaDistancias listaDistancias;
  Pista nueva;
  celdaLista * aux, * aux2;
  aux=l->ini;
    while(aux!=NULL){
        nueva=aux->pista;
        listaDistancias=sacarDistancias(*l,nueva);
        listaDistancias.ini=listaDistancias.ini->sig; //AVANZAMOS UNA POSICION EN LA LISTA PARA EVITAR COMPARAR EL DATO CONSIGO MISMO
        calcularClase(listaDistancias,&nueva,k);//CALCULO DE LA CLASE DE LA PISTA INTRODUCIDA
        aux2= aux;
        aux=aux->sig;
        if(aux2->pista.clase!=nueva.clase){
            eliminaPista(l,aux2);
        } 
    }
}
  