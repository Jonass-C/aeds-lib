#ifndef PILHAS_H
#define PILHAS_H
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *topo; // aponta para o primeiro elemento
} Pilha;

Pilha *criarPilha();
bool estaVazio(Pilha *pilha);
void empilha(Pilha *pilha, int dado);
int desempilha(Pilha *pilha);
void removerItem(Pilha *pilha, int dado);
int consultarValor(Pilha *pilha);
int tamanhoPilha(Pilha *pilha);
void ordenarPilha(Pilha *pilha);
void inverterPilha(Pilha *pilha);
void imprimirPilha(Pilha *pilha);
int apagarPilha(Pilha *pilha);

#endif