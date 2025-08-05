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

void empilha(Pilha *pilha, int dado) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->prox = pilha->topo->prox;

    pilha->topo->prox = adicionar;
    pilha->tamanho++;
}

int desempilha(Pilha *pilha) {

    if (estaVazio(pilha)) {
        return -1;
    }

    No *remover = pilha->topo->prox;
    pilha->topo->prox = remover->prox;

    int dado = remover->dado;
    free(remover);
    pilha->tamanho--;

    return dado;
}

void removerItem(Pilha *pilha, int dado) {

    Pilha *aux = criarPilha();

    while (!estaVazio(pilha)) {
        int valor = desempilha(pilha);
        if (valor == dado) {
            break;
        } else {
            empilha(aux, valor);
        }
    }

    while (!estaVazio(aux)) {
        empilha(pilha, desempilha(aux));
    }
}

int consultarValor(Pilha *pilha) {

    if (estaVazio(pilha)) {
        printf("Pilha vazia\n");
        return -1;
    }

    return pilha->topo->prox->dado;
}

int tamanhoPilha(Pilha *pilha) {

    // return pilha->tamanho;

    // lógica para retornar o tamanho
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

void ordenarPilha(Pilha *pilha) {

    Pilha *aux = criarPilha();

    while (!estaVazio(pilha)) {
        int valor = desempilha(pilha);

        while (!estaVazio(aux) && aux->topo->prox->dado > valor) {
            empilha(pilha, desempilha(aux));
        }

        empilha(aux, valor);
    }

    while (!estaVazio(aux)) {
        empilha(pilha, desempilha(aux));
    }
}

void inverterPilha(Pilha *pilha) {

    // uso de duas pilhas auxiliares

    Pilha *aux1 = criarPilha();
    while (!estaVazio(pilha)) {
        empilha(aux1, desempilha(pilha));
    }

    Pilha *aux2 = criarPilha();
    while (!estaVazio(aux1)) {
        empilha(aux2, desempilha(aux1));
    }

    while (!estaVazio(aux2)) {
        empilha(pilha, desempilha(aux2));
    }
}

void imprimirPilha(Pilha *pilha) {

    if (estaVazio(pilha)) {
        printf("Pilha vazia\n");
        return;
    }

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