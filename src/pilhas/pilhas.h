#ifndef PILHAS_H
#define PILHAS_H
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *topo; // será a célula cabeça da minha pilha, não o primeiro elemento. Primeiro elemento será topo->prox
} Pilha;

Pilha *criarPilha();
bool estaVazio(Pilha *pilha);
void inserirElemento(Pilha *pilha, int dado);
void removerElementos(Pilha *pilha);
int consultarValor(Pilha *pilha);
int tamanhoPilha(Pilha *pilha);
void imprimirPilha(Pilha *pilha);
int apagarPilha(Pilha *pilha);

#endif //PILHAS_H