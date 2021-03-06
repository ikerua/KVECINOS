/*
  FICHERO: calculo de la Eficiencia para k=i
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

//PROGRAMA PRINCIPAL
int main(void){
    //DECLARACION DE VARIABLES NECESARIAS
    tipoLista listaPistas;
    tipoListaOrdenadaDistancias listaDistancias;
    Pista p,nueva;
    matriz m;
    int k,eficiencia;
    FILE *f=fopen("DatosNormalizados.txt","r");   //APERTURA DEL FICHERO DE DATOS
    if(f==NULL)
      perror("Error al abrir el fichero\n");//COMPROBACION DE QUE EL FICHERO SE HA ABIERTO CORRECTAMENTE
    printf("Introduce un valor de k para calcular su eficiencia: ");
    scanf("%d",&k);
    //INICIALIZACION DE ESTRUCTURAS NECESARIAS
    nuevaLista(&listaPistas);
    nuevaListaOrdenada(&listaDistancias);
    introEnMatriz(m,f);                      //INSERTAR EN LA MATRIZ LA BASE DE DATOS
    fclose(f);
    //imprimeMatriz(m);                         //IMPRIME MATRIZ SIN NORMALIZAR
    normalizarMatriz(m);                     //NORMALIZAMOS MATRIZ
    //imprimeMatriz(m);                        //IMPRIME MATRIZ NORMALIZADA
    
    //CREACION DE LA LISTA DE PISTAS
    for(int i=0;i<FILA;i++){
        p=leerPista(m,i);
        insertar(&listaPistas,p);
    }
    celdaLista * aux=listaPistas.ini;
    for (int i=0;i<FILA;i++){
        /*if(aux==NULL){
          perror("ERROR EN EFICIENCIA");
          exit(-1);
        }*/
        nueva=aux->pista;
        listaDistancias=sacarDistancias(listaPistas,nueva);
        listaDistancias.ini=listaDistancias.ini->sig; //AVANZAMOS UNA POSICION EN LA LISTA PARA EVITAR COMPARAR EL DATO CONSIGO MISMO
        calcularClase(listaDistancias,&nueva,k);//CALCULO DE LA CLASE DE LA PISTA INTRODUCIDA
        if(aux->pista.clase==nueva.clase)
            eficiencia++;
        //vaciarListaOrdenada(&listaDistancias);
        aux=aux->sig;
    }
    printf("La eficiencia del algorimo para k=%d, es del:%d \n",k,eficiencia);
  //vaciarLista(&listaPistas);
    /*introducePista(&nueva); //METEMOS POR TECLADO LA NUEVA PISTA DE LA CUAL QUEREMOS CALCULAR SU CLASE
    normalizarPista(&nuevo,n);
    listaDistancias=sacarDistancias(listaPistas,nueva);//CALCULO DE LAS DISTANCIAS
    calcularClase(listaDistancias,&nueva,k);//CALCULO DE LA CLASE DE LA PISTA INTRODUCIDA
    printf("La clase de la pista introducida es: %d\n",nueva.clase);*/
    
    return 0;
}

