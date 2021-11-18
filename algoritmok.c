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
void calcularClase(tipoListaOrdenadaDistancias lista ,Pista *p, int k){
    int tablaClases[NUMCLASES];
    CeldaListaOrdenada *aux= lista.ini; 
    for (int j=0;j<NUMCLASES;j++)
        tablaClases[j]=0;  
    for(int i =0; i<k;i++){
        if(aux->sig == NULL){
            perror("ERROR FUNCION SACAR CLASE");
            exit(-1);
        }
        tablaClases[aux->elem.clase]++;
        aux = aux->sig;
    }
    int posMax=0;
    for(int i=1;i<NUMCLASES;i++){
        if(tablaClases[posMax]<tablaClases[i])
            posMax=i;
    }
    p->clase=posMax;
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
    nuevaListaOrdenada(&listaDistancias);
    while(p->sig!=NULL){
        d=calcularDistancia(nueva,p->pista);
        insertarListaOrdenada(&listaDistancias,d);
        p=p->sig;
    }
    return listaDistancias;
}

