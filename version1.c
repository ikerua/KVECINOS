/*
  FICHERO: programa principal
  VERSION: 1.0
  Fecha 10/11/21
*/
#include "listaOrdenadaDistancias.h"
#include "listaPista.h"
#include "normalizacion.h"
#include "algoritmok.h"
#include "algoritmoWilson.h"
#include "calculaEficiencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DECLARACION DE FUNCIONES ACCIONES
void introducePista(Pista * );
void clonarMatriz(matriz ,matriz);
//PROGRAMA PRINCIPAL
int main(void){
    //DECLARACION DE VARIABLES NECESARIAS
    tipoLista listaPistas;
    tipoListaOrdenadaDistancias listaDistancias;
    Pista p,nueva;
    matriz matrizDatos,matrizNormalizada;
    int k=10;//SE HA CALCULADO EN BASE A UN ALGORITMO EXTRA calculoEficiencia.c
    FILE *f=fopen("DataBase.txt","r");   //APERTURA DEL FICHERO DE DATOS
    if(f==NULL)
      perror("Error al abrir el fichero\n");//COMPROBACION DE QUE EL FICHERO SE HA ABIERTO CORRECTAMENTE
    //INICIALIZACION DE ESTRUCTURAS NECESARIAS
    nuevaLista(&listaPistas);
    nuevaListaOrdenada(&listaDistancias);
    introEnMatriz(matrizDatos,f);                      //INSERTAR EN LA MATRIZ LA BASE DE DATOS
    fclose(f);
    clonarMatriz(matrizDatos,matrizNormalizada);        //CLONAMOS LA MATRIZ PARA DESPUES PODER NORMALIZAR LOS DATOS DE LA NUEVA PISTA INTRODUCIDA
    //imprimeMatriz(matrizDatos);                         //IMPRIME MATRIZ SIN NORMALIZAR
    normalizarMatriz(matrizNormalizada);                     //NORMALIZAMOS MATRIZ
   // imprimeMatriz(matrizNormalizada);                        //IMPRIME MATRIZ NORMALIZADA
    //CREACION DE LA LISTA DE PISTAS
    for(int i=0;i<FILA;i++){
        p=leerPista(matrizNormalizada,i);
        insertar(&listaPistas,p);
    }
    calculaEficiencia(listaPistas,k);
    algoritmoWilson(&listaPistas,k);
    calculaEficiencia(listaPistas,k);
    introducePista(&nueva); //METEMOS POR TECLADO LA NUEVA PISTA DE LA CUAL QUEREMOS CALCULAR SU CLASE
    normalizarPista(&nueva,matrizDatos);
    listaDistancias=sacarDistancias(listaPistas,nueva);//CALCULO DE LAS DISTANCIAS
    calcularClase(listaDistancias,&nueva,k);//CALCULO DE LA CLASE DE LA PISTA INTRODUCIDA
    printf("La clase de la pista introducida es: %d\n",nueva.clase);
    return 0;
}
//FUNCION NECESARIA
void introducePista(Pista * p){
  char *d = (char *)malloc(sizeof(char));
  for(int i=0;i<COLUMNA-1;i++){
    printf("Introduce el valor del dato Nº %d ",i+1);
    scanf("%[^\n]%*c",d);
    p->datos[i]=atof(d);
  }
}
void clonarMatriz(matriz m,matriz nueva){
    for(int i=0;i<FILA;i++){
      for(int j=0;j<COLUMNA;j++)
          nueva[i][j]=m[i][j];
    }
}