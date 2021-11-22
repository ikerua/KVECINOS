/**
 * @file normalizacion.c
 * @brief 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
//HEADERS NECESARIOS
#include "normalizacion.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>
//FUNCIONES NECESARIAS PERO NO EXPORTADAS
/**
 * @brief 
 * 
 * @param dat 
 * @return float 
 */
float leerDato(FILE *dat){
    double parteEntera=0,parteDecimal=0,x=0;
    bool entero = true, negativo =false;
    char aux=fgetc(dat);
    int numDigitos=0;
    if(aux=='-'){
        negativo=true;
        aux=fgetc(dat);
    }
    //LEEMOS EL STRING Y LO CONVERTIMOS EN REAL.
    while(aux!=';'){
        if(aux == ','){
            entero = false;
            aux=fgetc(dat);
        }
        if(entero){
            parteEntera = 10*parteEntera+atoi(&aux);
        }else{
            numDigitos++;
            parteDecimal = parteDecimal+atoi(&aux)/(pow(10,numDigitos));
        }
        aux=fgetc(dat);  
    } 
    x =(parteEntera+parteDecimal);
    if(negativo)
        x *=-1;
    //printf("%f ",x);
    return x;
}

/**
 * @brief 
 * 
 * @param dat 
 * @return int 
 */
int sacarClase(FILE * dat){
    int x;
    char aux=fgetc(dat);
    
    if(aux=='b')
        x=0;
    else if(aux=='c'){
        aux=fgetc(dat);
        if(aux=='l')
            x=1;
        else if(aux=='o')
            x=2;
    }else if(aux=='d')
        x=3;
    else if(aux=='h')
        x=4;
    else if(aux=='j')
        x=5;
    else if(aux=='m')
        x=6;
    else if(aux=='p')
        x=7;
    else if(aux=='r'){
        aux=fgetc(dat);
        if(aux=='e')
            x=8;
        else if(aux=='o')
            x=9;
    }
    while(aux!=';' && !feof(dat))
        aux=fgetc(dat);
    
    return x;
}

/**
 * FUNCION:
 * ENTRADA:
 *  REQUISITOS:
 * SALIDA: Un float 
 * DESCRICPCION:
 */
float minimo(matriz m,int x){
    float min=m[0][x];
    for(int i=1;i<FILA;i++){
        if(min>m[i][x])
            min=m[i][x];
    }
    return min;
}

/**
 * FUNCION:
 * ENTRADA:
 *  REQUISITOS:
 * SALIDA: Un float 
 * DESCRICPCION:
 */
float maximo(matriz m,int x){
    float max=m[0][x];
    for(int i=1;i<FILA;i++){
        if(max<m[i][x])
            max=m[i][x];
    }
    return max;
}

/**
 * @brief 
 * 
 * @param valor 
 * @param maximo 
 * @param minimo 
 * @return float 
 */
float obtnormalizado(float valor, float maximo, float minimo){
    return ((valor-minimo)/(maximo-minimo));
}

/**
 * @brief 
 * 
 * @param m 
 */
matriz normalizarMatriz(matriz m){
    matriz n;
    float max,min;
    for(int i=0;i<(COLUMNA-1);i++){
        max=maximo(m,i);
        min=minimo(m,i);
        for(int j=0;j<FILA;j++)
            n[j][i]=obtnormalizado(m[j][i],max,min);
    }
    return n;
}

/**
 * @brief 
 * 
 * @param m 
 * @param dat 
 */
void introEnMatriz(matriz m, FILE * dat){
    for(int i=0;i<FILA;i++){
        for(int j = 0; j<COLUMNA-1; j++){
           m[i][j] = leerDato(dat); 
        }
        m[i][COLUMNA-1]=(float)sacarClase(dat);
    }   
}
