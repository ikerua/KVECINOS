/*
  FICHERO: calculo de la Eficiencia para k=i
  VERSION: 1.0
  Fecha 10/11/21
*/
#include "calculaEficiencia.h"
#include "algoritmok.h"
#include <stdio.h>
/*
 * ACCION: calculaEficiencia
 * ENTRADA: Una lista de Pistas y un entero 
 *  REQUISITOS: La lista de Pistas debe estar inicializada y no ser vacia y el entero debe ser la k mas eficiente para el problema
 * SALIDA: 
 * DESCRIPCION:
 */
void calculaEficiencia(tipoLista listaPistas,int k){
    tipoListaOrdenadaDistancias listaDistancias;
    Pista nueva;
    int numPistasBuenas=0,numPistas=0;
    celdaLista * aux=listaPistas.ini;
    while(aux!=NULL){
        nueva=aux->pista;
        listaDistancias=sacarDistancias(listaPistas,nueva);
        listaDistancias.ini=listaDistancias.ini->sig; //AVANZAMOS UNA POSICION EN LA LISTA PARA EVITAR COMPARAR EL DATO CONSIGO MISMO
        calcularClase(listaDistancias,&nueva,k);//CALCULO DE LA CLASE DE LA PISTA INTRODUCIDA
        if(aux->pista.clase==nueva.clase)
            numPistasBuenas++;
        aux=aux->sig;
        numPistas++;
    }
    printf("La eficiencia del algorimo para k=%d, es del: %.2f \n",k,100*((float)numPistasBuenas/numPistas));
}
