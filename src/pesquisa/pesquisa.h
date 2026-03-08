#ifndef PESQUISA_H
#define PESQUISA_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    long Item[MAX + 1];
    int num_elementos;
} Tabela;

void inicializa(Tabela*);
int pesquisa_seq(Tabela*, long);
int pesquisa_bin(Tabela*, long);
void insere(long, Tabela*);
void retira(long, Tabela*);

#endif