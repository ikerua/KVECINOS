/*
* FICHERO: colaTriples.c
* VERSION: 1.0.0
* HISTORICO:
* Creado por Iñigo Varela 15/9/21
*/
#include "colaDatos.h"
#include <stdio.h>
#include <stdlib.h>


void nuevaCola(tipoCola *c){
    c->ini = NULL;
    c->fin = NULL; 
}
void errorCola(char s[]){
    printf("\n\n\nERROR en el modulo cola: %s \n", s);
    exit(-1);
}
void encolar(tipoCola *c, tipoElementoCola x){
    celdaCola *q;
    if((q=malloc(sizeof(celdaCola))) == NULL){
        errorCola("no hay memoria para pideTurno");
    }
    q->elem = x;
    q->sig = NULL;
    if(c->fin == NULL){ 
        c->ini = q;
    }else{
        c->fin->sig = q;
    }
    c->fin = q; 
}
void desencolar(tipoCola *c){
    celdaCola *q;
    if(esNulaCola(*c)){
        errorCola("avanzando en cola nula");
    }
    q = c->ini;
    c->ini = c->ini->sig;
    if(c->ini == NULL){ //caso de que solo habia un elemento en la cola
        c->fin = NULL;
    }
    free(q);
}
tipoElementoCola frente(tipoCola c){
    if(esNulaCola(c)){
        errorCola("frente de una cola nula");
    }
    return (c.ini->elem);
}
bool esNulaCola(tipoCola c){
    return (c.ini == NULL);
}
