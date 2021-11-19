/**
 * @file listaPista.c
 * @version 1.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//HEADERS NECESARIOS PARA LA COMPILACION
#include <stdio.h>
#include <stdlib.h>
#include "listaPista.h"
//IMPLEMENTACION DE ACCIONES/FUNCIONES EXPORTADAS
/**
 * ACCION: nuevaLista
 * ENTRADA: Un elemento tipoLista
 *  REQUISITOS: No debe estar inicializada
 * SALIDA: La lista inicializada
 */
void nuevaLista(tipoLista * l){
    l->ini = NULL;
    l->fin = NULL;
}

/**
 * ACCION: insertar
 * ENTRADA: Un elemento y una lista
 *  REQUISITOS: La lista debe estar inicializada
 * SALIDA: La lista con el elemento introducido en el
 * DESCRIPCION: El elemento se insertara de manera ordenada en la lista
 */
void insertar(tipoLista * l, Pista elem){
    celdaLista * q;
    if((q=malloc(sizeof(celdaLista)))==NULL){
        perror("No hay memoria para insertar");
    }
    q->pista = elem;
    q->ant = NULL;
    q->sig = NULL;
    if(esNulaLista(*l)){
        l->ini = q;
        l->fin = q;
    }
    else {
        l->fin->sig = q;
        l->fin = l->fin->sig;
    }
    
}
/**
 * FUNCION: eliminaPista
 * ENTRADA: una lista y un puntero a la pista que se desea eliminar
 *  REQUISITOS: la lista debe estar inicializada y contener almenos un valor
 * SALIDA: la lista con el elemento a eliminar
 * DESCRIPCION: Será necesaria en el algoritmo de wilson para eliminar outliers
 */
void eliminaPista(tipoLista * l, celdaLista * pista){
    if(esNulaLista(*l))
        perror("ELIMINANDO EN UNA LISTA VACÍA");
    if(l->ini == pista){
        l->ini = pista->sig;
        l->ini->ant = NULL;
    }
    else if(l->ini == pista){
        l->fin = pista->ant ;
        l->fin->sig =NULL;
    }
    else{
        pista->ant->sig = pista->sig;
        pista->sig->ant = pista->ant;
    }
    free(pista);

}
/**
 * ACCION: eliminar
 * ENtrada: una lista de pistas
 * Salida: la primera pista queda eliminada de la lista
 */
void eliminar(tipoLista * l){
    if(esNulaLista(*l)){
        perror("Eliminando elemento en una lista vacía \n\n");
    }
    l->ini = l->ini->sig;
    free(l->ini->ant);
    l->ini->ant = NULL;
}
/**
 * FUNCION: esNulaLista
 * ENTRADA: una lista
 *  REQUISITOS:la lista debe estar incializada 
 * SALIDA: un booleano que indica si la lista esta vacía o no
 */
bool esNulaLista(tipoLista l){
    return (l.ini ==NULL);
}
/**
 * ACCION:Vaciar lista
 * Entrada: Una lista de pistas
 * SALIDA: La lista queda vaciada
 * 
 */
void vaciarLista(tipoLista *l){
    while(!esNulaLista(&l))
        eliminar(&l);
}