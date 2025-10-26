#ifndef PESQUISA_H
#define PESQUISA_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    long Item[MAX + 1];
    int numElementos;
} Tabela;

void inicializa(Tabela*);
int pesquisaSeq(Tabela*, long);
int pesquisaBin(Tabela*, long);
void insere(long, Tabela*);
void retira(long, Tabela*);

#endif