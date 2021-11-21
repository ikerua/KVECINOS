all: modulos version1 calculoEficiencia

version1:  version1.c *.o
	gcc -g -o version1 version1.c *.o -lm -Wall

calculoEficiencia: calculoEficiencia.c *.o
	gcc -g -o calculoEficiencia calculoEficiencia.c *.o -lm -Wall

modulos: matriz.c normalizacion.c pista.c listaPista.c distancia.c listaOrdenadaDistancias.c algoritmok.c
	gcc -g -c -Wall matriz.c
	gcc -g -c -Wall -lm normalizacion.c 
	gcc -g -c -Wall pista.c 
	gcc -g -c -Wall listaPista.c  
	gcc -g -c -Wall -lm distancia.c 
	gcc -g -c -Wall listaOrdenadaDistancias.c 
	gcc -g -c -Wall algoritmok.c 
