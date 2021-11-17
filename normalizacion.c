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
//FUNCIONES NECESARIAS PERO NO EXPORTADAS
/**
 * @brief 
 * 
 * @param dat 
 * @return float 
 */
float leerDato(FILE *dat){
    float x=0;
    char aux=fgetc(dat);
    int numDigitos=0;
    while(aux!=';'){
        if(aux!=','){
            x=10*x+atoi(&aux);
            numDigitos++;
        }
        aux=fgetc(dat);
    }
    x=x/numDigitos;
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
float minimo(matriz m,int columna){
    float min=m[0][columna];
    for(int i=1;i<COLUMNA;i++){
        if(min>m[i][columna])
            min=m[i][columna];
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
float maximo(matriz m,int columna){
    float max=m[0][columna];
    for(int i=1;i<COLUMNA;i++){
        if(max<m[i][columna])
            max=m[i][columna];
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
void normalizarMatriz(matriz m){
    float max,min;
    for(int i=0;i<(COLUMNA-1);i++){
        max=maximo(m,i);
        min=minimo(m,i);
        for(int j=0;j<FILA;j++)
            m[j][i]=obtnormalizado(m[j][i],max,min);
    }
}

/**
 * @brief 
 * 
 * @param m 
 * @param dat 
 */
void introEnMatriz(matriz m, FILE * dat){
    int i=0;
    while(!feof(dat)){
        for(int j = 0; j<COLUMNA-1; j++){
           m[i][j] = leerDato(dat); 
        }
        m[i][COLUMNA-1]=(float)sacarClase(dat);
        i++;
    }   
}
