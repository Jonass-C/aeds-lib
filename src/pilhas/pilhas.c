#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilhas.h"

Pilha *criarPilha() {

    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->tamanho = 0;

    pilha->topo = (No*) malloc(sizeof(No));
    pilha->topo->prox = NULL;
    pilha->topo->dado = -1;

    return pilha;
}

bool estaVazio(Pilha *pilha) {
    return pilha->topo->prox == NULL;
}

void inserirElemento(Pilha *pilha, int dado) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->prox = pilha->topo->prox;

    pilha->topo->prox = adicionar;
    pilha->tamanho++;
}

void removerElementos(Pilha *pilha) {

    if (estaVazio(pilha)) {
        printf("Lista vazia\n");
        return;
    }

    No *remover = pilha->topo->prox;
    pilha->topo->prox = remover->prox;
    free(remover);
    pilha->tamanho--;
}

int consultarValor(Pilha *pilha) {
    if (estaVazio(pilha)) {
        printf("Pilha vazia\n");
        return 0;
    }
    return pilha->topo->prox->dado;
}

int tamanhoPilha(Pilha *pilha) {

    // return pilha->tamanho;

    if (estaVazio(pilha)) {
        return 0;
    }

    No *aux = pilha->topo;
    int tamanho = 0;
    for (int i = 0; i < pilha->tamanho; i++) {
        aux = aux->prox;
        tamanho++;
    }

    return tamanho;
}

void imprimirPilha(Pilha *pilha) {

    No *aux = pilha->topo->prox;
    while (aux != NULL) {
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int apagarPilha(Pilha *pilha) {

    if (estaVazio(pilha)) {
        printf("Pilha vazia\n");
        free(pilha->topo);
        free(pilha);
        return 0;
    }

    No *aux = pilha->topo;
    No *apagar;
    while (aux != NULL) {
        apagar = aux;
        aux = aux->prox;
        free(apagar);
    }

    free(pilha);
    return 1;
}