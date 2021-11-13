/*
  FICHERO: colaTriples.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Iñigo Varela 15/9/21.

*/

#include <stdbool.h>
#include "dato.h"
typedef Dato tipoElementoCola;
typedef struct celdaC{
	 tipoElementoCola elem;
	 struct celdaC *sig;
 } celdaCola; 
typedef struct tipoC{
	celdaCola* ini;
	celdaCola* fin;
}tipoCola;

void nuevaCola(tipoCola *);

void encolar(tipoCola *, tipoElementoCola );

void desencolar(tipoCola *);

tipoElementoCola frente(tipoCola);

bool esNulaCola(tipoCola);
