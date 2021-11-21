#ifndef LISTA_ORDENADA_DISTANCIAS_H
#define LISTA_ORDENADA_DISTANCIAS_H
/*
  FICHERO: listaOrdenadaDistancias.h
  VERSION: 1.0.0
*/

#include <stdbool.h>
#include "distancia.h"

 typedef struct celdaListaOrdenada{
	 Distancia elem;
	 struct celdaListaOrdenada *sig;
	 struct celdaListaOrdenada *ant;
 }CeldaListaOrdenada; 
typedef struct tipoListaOrdenada{
	CeldaListaOrdenada *ini;
	CeldaListaOrdenada *fin;
}tipoListaOrdenadaDistancias;

void nuevaListaOrdenada(tipoListaOrdenadaDistancias *);

void insertarListaOrdenada(tipoListaOrdenadaDistancias *, Distancia);

void eliminarMenorListaOrdenada(tipoListaOrdenadaDistancias *);

void eliminarMayorListaOrdenada(tipoListaOrdenadaDistancias *);

Distancia consultarMenorListaOrdenada(tipoListaOrdenadaDistancias);

Distancia consultarMayorListaOrdenada(tipoListaOrdenadaDistancias);

bool estaElementoListaOrdenada(tipoListaOrdenadaDistancias, Distancia);

bool esNulaListaOrdenada(tipoListaOrdenadaDistancias);

void vaciarListaOrdenada(tipoListaOrdenadaDistancias *);
#endif
