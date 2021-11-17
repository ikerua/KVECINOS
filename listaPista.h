/*
  FICHERO: listaPista.h
  VERSION: 1.0.0
*/

//HEADERS NECESARIOS 
#include <stdbool.h>
#include "distancia.h"

 typedef struct celdaL{
	 Pista pista;
	 struct celdaL *sig;
	 struct celdaL *ant;
 }celdaLista; 
typedef struct tipoL{
	celdaLista *ini;
	celdaLista *fin;
}tipoLista;

void nuevaLista(tipoLista *);

void insertar(tipoLista *, Pista);

void eliminaPista(tipoLista *, celdaLista *);

bool esNulaLista(tipoLista);

