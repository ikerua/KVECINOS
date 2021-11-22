/*
  FICHERO: programa principal
  VERSION: 1.0
  Fecha 10/11/21
*/
#include "listaOrdenadaDistancias.h"
#include "listaPista.h"
#include "normalizacion.h"
#include "algoritmok.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DECLARACION DE FUNCIONES ACCIONES
void introducePista(Pista * );

//PROGRAMA PRINCIPAL
int main(void){
    //DECLARACION DE VARIABLES NECESARIAS
    tipoLista listaPistas;
    tipoListaOrdenadaDistancias listaDistancias;
    Pista p,nueva;
    matriz matrizDatos,matrizNormalizada;
    int k=1;
    FILE *f=fopen("DatosNormalizados.txt","r");   //APERTURA DEL FICHERO DE DATOS
    if(f==NULL)
      perror("Error al abrir el fichero\n");//COMPROBACION DE QUE EL FICHERO SE HA ABIERTO CORRECTAMENTE
    //INICIALIZACION DE ESTRUCTURAS NECESARIAS
    nuevaLista(&listaPistas);
    nuevaListaOrdenada(&listaDistancias);
    introEnMatriz(matrizDatos,f);                      //INSERTAR EN LA MATRIZ LA BASE DE DATOS
    fclose(f);
    //imprimeMatriz(matrizDatos);                         //IMPRIME MATRIZ SIN NORMALIZAR
    matrizNormalizada=normalizarMatriz(matrizDatos);                     //NORMALIZAMOS MATRIZ
    //imprimeMatriz(matrizNormalizada);                        //IMPRIME MATRIZ NORMALIZADA
    
    //CREACION DE LA LISTA DE PISTAS
    for(int i=0;i<FILA;i++){
        p=leerPista(m,i);
        insertar(&listaPistas,p);
    }
    
    introducePista(&nueva); //METEMOS POR TECLADO LA NUEVA PISTA DE LA CUAL QUEREMOS CALCULAR SU CLASE
    normalizarPista(&nueva,matrizDatos);
    listaDistancias=sacarDistancias(listaPistas,nueva);//CALCULO DE LAS DISTANCIAS
    calcularClase(listaDistancias,&nueva,k);//CALCULO DE LA CLASE DE LA PISTA INTRODUCIDA
    printf("La clase de la pista introducida es: %d\n",nueva.clase);
    vaciarLista(&listaPistas);
    vaciarListaOrdenada(&listaDistancias);
    
    return 0;
}
//FUNCION NECESARIA
void introducePista(Pista * p){
  char *d = (char *)malloc(sizeof(char));
  for(int i=0;i<COLUMNA-1;i++){
    printf("Introduce el valor normalizado del dato Nº %d ",i+1);
    scanf("%[^\n]%*c",d);
    p->datos[i]=atof(d);
  }
}
