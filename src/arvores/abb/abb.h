#ifndef ABB_H
#define ABB_H
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    long valor;
    struct no *esq, *dir;
} No;

void inicializa(No**);
int pesquisa(No*, long);
int insere(long, No**);
No *cria_no(long);
int retira(long, No**);
void antecessor(No*, No**);
void central(No*);

#endif