/**
 * @file algoritmok.c
 * DESCRICPION:
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//DEFINICION DE CONSTANTES
#define NUMCLASES 10
//HEADERS NECESARIOS
#include "algoritmok.h"

//IMPLEMENTACION DE ACCION EXPORTADA
void sacarClase(tipoListaOrdenadaDistancias lista ,Pista p, int k){
    int tablaClases[NUMCLASES];
    for (int j=0;j<NUMCLASES;j++)
        tablaClases[j]=0;
    celdaListaOrdenada *aux= lista.ini;   
    for(int i =0; i<k;i++){
        if(aux->sig == NULL){
            perror("ERROR FUNCION SACAR CLASE");
            exit(-1);
        }
        tablaClases[aux->elem.clase]++;
        aux = aux->sig;
    }
}
/*
 * Funcion : Sacar distancias
 * ENTRADAS: Una lista de pistas y una pista 
 *  REQUISITOS: Ninguno
 * SALIDA:Una lista ordenada de las distancias
 * DESCRIPCION: 
 */
tipoListaOrdenadaDistancias sacarDistancias(tipoLista listaPistas,Pista nueva){
    celdaLista * p=listaPistas.ini;
    Distancia d;
    tipoListaOrdenadaDistancias listaDistancias;
    Distancia d;
    nuevaListaOrdenada(&listaDistancias);
    while(p!=NULL){
        d=calcularDistancia(nueva,p->pista);
        insertarListaOrdenada(&listaDistancias,d);
        p=p->sig;
    }
    return listaDistancias;
}

