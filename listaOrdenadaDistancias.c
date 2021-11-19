/**
 * @file listaOrdenadaDistancias.c
 * @author Iker Urdiroz
 * @version 1.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//HEADERS NECESARIOS PARA LA COMPILACION
#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenadaDistancias.h"
//IMPLEMENTACION DE ACCIONES/FUNCIONES EXPORTADAS
/**
 * ACCION: nuevaLista
 * ENTRADA: Un elemento tipoLista
 *  REQUISITOS: No debe estar inicializada
 * SALIDA: La lista inicializada
 */
void nuevaListaOrdenada(tipoListaOrdenadaDistancias * l){
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
void insertarListaOrdenada(tipoListaOrdenadaDistancias * l, Distancia elem){
    CeldaListaOrdenada * q, * aux;
    if((q=malloc(sizeof(CeldaListaOrdenada)))==NULL){
        perror("No hay memoria para insertar");
    }
    q->elem = elem;
    q->ant = NULL;
    q->sig = NULL;
    if(esNulaListaOrdenada(*l)){
        l->ini = q;
        l->fin = q;
    }
    else if(q->elem.dist <= l->ini->elem.dist){
        l->ini->ant = q;
        q->sig=l->ini;
        l->ini = q;
    }
    else if(q->elem.dist >= l->fin->elem.dist){
        l->fin->sig =q;
        q->ant = l->fin;
        l->fin = q;
    }
    else{
        aux = l->ini;
        while ((aux->sig != NULL)&&(aux->elem.dist< q->elem.dist))
        {
            aux = aux->sig;
        }
        aux->ant->sig = q;
        q->ant = aux->ant;
        aux->ant = q;
        q->sig = aux;
        
    }
}

/**
 * ACCION: eliminarMenor
 * ENTRADA: Una lista
 *  REQUISITOS: Debe estar inicializada y no debe ser vacía
 * SALIDA: La lista sin el elemento menor
 */
void eliminarMenorListaOrdenada(tipoListaOrdenadaDistancias * l){
    if(esNulaListaOrdenada(*l)){
        perror("Eliminando elemento en una lista vacía \n\n");
    }
    l->ini = l->ini->sig;
    free(l->ini->ant);
    l->ini->ant = NULL;
}

/**
 * ACCION:eliminarMayor
 * ENTRADA: una lista
 *  REQUISITOS: debe estar inicializada y no debe ser vacía
 * SALIDA: La lista sin el elemento mayor
 */
void eliminarMayorListaOrdenada(tipoListaOrdenadaDistancias * l){
    if(esNulaListaOrdenada(*l)){
        perror("Eliminando elemento en una lista vacía \n\n");
    }
    l->fin = l->fin->ant;
    free(l->fin->sig);
    l->fin->sig = NULL;
}

/**
 * FUNCION: consultaMenor
 * ENTRADA: una lista
 *  REQUISITOS:la lista debe estar incializada y no debe ser vacía
 * SALIDA: el elemento menor
 */
Distancia consultarMenorListaOrdenada(tipoListaOrdenadaDistancias l){
    if(esNulaListaOrdenada(l)){
        perror("Consultando elemento en lista vacía\n\n");
    }
    return(l.ini->elem);
}
/**
 * FUNCION: consultaMayor
 * ENTRADA: una lista
 *  REQUISITOS:la lista debe estar incializada y no debe ser vacía
 * SALIDA: el elemento mayor
 */
Distancia consultarMayorListaOrdenada(tipoListaOrdenadaDistancias l){
    if(esNulaListaOrdenada(l)){
        perror("Consultando elemento en lista vacía\n\n");
    }
    return(l.fin->elem);
}

/**
 * FUNCION: estaElemento
 * ENTRADA: una lista
 *  REQUISITOS:la lista debe estar incializada y no debe ser vacía
 * SALIDA: un booleano indicando si el elemento deseado se encuentra en la lista
 */
bool estaElementoListaOrdenada(tipoListaOrdenadaDistancias l, Distancia elem){
    CeldaListaOrdenada * aux; 
    aux = l.ini;
    while((aux!=NULL)&&(aux->elem.dist<elem.dist)){
        aux = aux->sig;
    }
    return(aux->elem.dist==elem.dist);  
}
/**
 * FUNCION: esNulaLista
 * ENTRADA: una lista
 *  REQUISITOS:la lista debe estar incializada 
 * SALIDA: un booleano que indica si la lista esta vacía o no
 */
bool esNulaListaOrdenada(tipoListaOrdenadaDistancias l){
    return (l.ini ==NULL);
}
/**
 * ACCION: vaciarListaOrdenada
 * ENTRADA: una lista
 *  REQUISITOS:la lista debe estar incializada 
 * SALIDA: la lista queda vaciada
 */
void vaciarListaOrdenada(tipoListaOrdenada *l){
    while(!esNulaListaOrdenada(&l))
        eliminarMayorListaOrdenada(&l);
}
