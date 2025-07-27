#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filas.h"

#include <math.h>

Fila *criarFila() {

    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->tamanho = 0;

    fila->cabeca = (No*) malloc(sizeof(No));
    fila->cabeca->dado = -1;
    fila->cabeca->prox = NULL;

    return fila;
}

bool estaVazio(Fila *fila) {
    return fila->cabeca->prox == NULL;
}

void enfileirar(Fila *fila, int dado) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->prox = NULL;

    No *aux = fila->cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = adicionar;
    fila->tamanho++;
}

int desenfileirar(Fila *fila) {

    if (estaVazio(fila)) {
        printf("Fila vazia\n");
        return -1;
    }

    No *remover = fila->cabeca->prox;
    fila->cabeca->prox = remover->prox;

    int dado = remover->dado;
    free(remover);
    fila->tamanho--;
    return dado;
}

int consultarValor(Fila *fila) {

    if (estaVazio(fila)) {
        printf("Lista vazia\n");
        return -1;
    }

    return fila->cabeca->prox->dado;
}

int tamanhoFila(Fila *fila) {
    return fila->tamanho;
}

void imprimirFila(Fila *fila) {

    No *aux = fila->cabeca->prox;
    while (aux != NULL) {
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int apagarFila(Fila *fila) {

    if (estaVazio(fila)) {
        printf("Lista vazia\n");
        free(fila->cabeca);
        free(fila);
        return 0;
    }

    No *aux = fila->cabeca;
    No *apagar;
    while (aux != NULL) {
        apagar = aux;
        aux = aux->prox;
        free(apagar);
    }

    free(fila);
    return 1;
}
