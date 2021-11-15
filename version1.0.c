/*
  FICHERO: programa principal
  VERSION: 1.0
  Fecha 10/11/21
*/
#include "listaPista.h"
#include "pista.h"
#include "normalizacion.h"
#include "distancia.h"
#include "listaOrdenadaDistancias.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    tipoLista listaPistas;
    tipoListaOrdenada listaDistancias;
    Pista p;
    Matriz m;
    FILE *f=fopen("DatosNormalizados.txt",r);
    nuevaLista(&listaPistas);
    nuevaListaOrdenada(&listaDistancias);
    introEnMatriz(&m,f);
    normalizarMatriz(&m);
    for(int i=0;i<FILA;i++){
        leerPista(m,&p,i);
        insertar(&listaPistas,p);
    }
    
    return 0;
}
