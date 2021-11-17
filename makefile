all: pista listaPista normalizacion distancia listaOrdenadaDistancias

pista: pista.c
	gcc -g -c pista.c -Wall

listaPista:  listaPista.c 
	gcc -g -c listaPista.c -Wall

normalizacion:	normalizacion.c 
	gcc -g -c normalizacion.c -Wall

distancia:	distancia.c
	gcc -g -c distancia.c pista.o -Wall

listaOrdenadaDistancias:	listaOrdenadaDistancias
	gcc -g -c listaOrdenadaDistancias.c -Wall
