all: pista normalizacion distancia listaPista listaOrdenadaDistancias algoritmok version1

version1:  version1.c *.o
	gcc -g -o version1 version1.c *.o

pista: pista.c
	gcc -g -c -Wall pista.c 

normalizacion:	normalizacion.c 
	gcc -g -c -Wall normalizacion.c 

distancia:	distancia.c pista.o
	gcc -g -c -Wall -lm distancia.c pista.o 

listaPista:  listaPista.c distancia.o
	gcc -g -c -Wall listaPista.c distancia.o

listaOrdenadaDistancias:	listaOrdenadaDistancias.c listaPista.o
	gcc -g -c -Wall listaOrdenadaDistancias.c listaPista.o

algoritmok:		algoritmok.c listaOrdenadaDistancias.o 
	gcc -g -c -Wall algoritmok.c listaOrdenadaDistancias.o 