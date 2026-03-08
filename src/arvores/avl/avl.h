#ifndef ARVORE_H
#define ARVORE_H
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

int fb(No*);
int altura(No*);
int balanceamento(No**);
void rse(No**);
void rsd(No**);
int balanca_esquerda(No**);
int balanca_direita(No**);
void imprimir_alturas(No*);

#endif