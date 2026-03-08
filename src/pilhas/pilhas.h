#ifndef PILHAS_H
#define PILHAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *topo; // aponta para o primeiro elemento
} Pilha;

Pilha *criar_pilha();
bool esta_vazio(Pilha *pilha);
void empilha(Pilha *pilha, int dado);
int desempilha(Pilha *pilha);
void remover_item(Pilha *pilha, int dado);
int consultar_valor(Pilha *pilha);
int tamanho_pilha(Pilha *pilha);
void ordenar_pilha(Pilha *pilha);
void inverter_pilha(Pilha *pilha);
void imprimir_pilha(Pilha *pilha);
int apagar_pilha(Pilha *pilha);

#endif