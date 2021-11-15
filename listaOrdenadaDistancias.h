/*
  FICHERO: listaOrdenadaDistancias.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include <stdbool.h>
#include "distancias.h"

 typedef Distancia tipoElementoLista;
 typedef struct celdaL{
	 tipoElementoLista elem;
	 struct celdaL *sig;
	 struct celdaL *ant;
 }celdaLista; 
typedef struct tipoL{
	celdaLista *ini;
	celdaLista *fin;
}tipoListaOrdenada;

void nuevaListaOrdenada(tipoListaOrdenada *);

void insertarListaOrdenada(tipoListaOrdenada *, tipoElementoLista);

void eliminarMenorListaOrdenada(tipoListaOrdenada *);

void eliminarMayorListaOrdenada(tipoListaOrdenada *);

tipoElementoLista consultarMenorListaOrdenada(tipoListaOrdenada);

tipoElementoLista consultarMayorListaOrdenada(tipoListaOrdenada);

bool estaElementoListaOrdenada(tipoListaOrdenada, tipoElementoLista);

bool esNulaListaListaOrdenada(tipoListaOrdenada);
