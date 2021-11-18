all: matriz pista normalizacion distancia listaPista listaOrdenadaDistancias algoritmok version1 

version1:  version1.c *.o
	gcc -g -o version1 version1.c *.o -lm -Wall

matriz: matriz.c
	gcc -g -c -Wall matriz.c

pista: pista.c
	gcc -g -c -Wall pista.c 

listaPista:  listaPista.c 
	gcc -g -c -Wall listaPista.c 

normalizacion:	normalizacion.c 
	gcc -g -c -Wall -lm normalizacion.c 

distancia:	distancia.c 
	gcc -g -c -Wall -lm distancia.c 

listaOrdenadaDistancias:	listaOrdenadaDistancias.c 
	gcc -g -c -Wall listaOrdenadaDistancias.c 

algoritmok:		algoritmok.c 
	gcc -g -c -Wall algoritmok.c 