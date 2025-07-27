#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listasduplas.h"

Lista *criarLista() {

    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->tamanho = 0;

    lista->cabeca = (No*) malloc(sizeof(No));
    lista->cabeca->dado = -1;
    lista->cabeca->prox = NULL;
    lista->cabeca->ant = NULL;

    return lista;
}

bool estaVazio(Lista *lista) {
    return lista->cabeca->prox == NULL;
}

void inserirPorPosicao(Lista *lista, int posicao, int dado) {
    if (posicao >= 0 && posicao <= lista->tamanho) {
        No *adicionar = (No*) malloc(sizeof(No));
        adicionar->dado = dado;

        No *aux = lista->cabeca;
        for (int i = 0; i < posicao; i++) {
            aux = aux->prox;
        }

        adicionar->ant = aux;
        adicionar->prox = aux->prox;
        if (aux->prox != NULL) {
            aux->prox->ant = adicionar;
        }
        aux->prox = adicionar;
        lista->tamanho++;
    }
    else {
        printf("Posição incorreta\n");
        return;
    }

}

void inserirNoInicio(Lista *lista, int dado) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->ant = lista->cabeca;
    adicionar->prox = lista->cabeca->prox;
    if (lista->cabeca->prox != NULL) {
        lista->cabeca->prox->ant = adicionar;
    }
    lista->cabeca->prox = adicionar;
    lista->tamanho++;

}

void inserirNoFim(Lista *lista, int dado) {

    No *aux = lista->cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->prox = NULL;
    adicionar->ant = aux;
    aux->prox = adicionar;
    lista->tamanho++;

}

void removerPorPosicao(Lista *lista, int posicao) {

    if (estaVazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    if (posicao >= 0 && posicao < lista->tamanho) {
        No *aux = lista->cabeca;
        for (int i = 0; i < posicao; i++) {
            aux = aux->prox;
        }

        No *remover = aux->prox;
        aux->prox = remover->prox;
        if (remover->prox != NULL) {
            remover->prox->ant = aux;
        }
        free(remover);
        lista->tamanho--;
    }
    else {
        printf("Posição incorreta\n");
        return;
    }
}

void trocarElementos(Lista *lista, int posicao1, int posicao2) {


    if (estaVazio(lista) || posicao1 < 0 || posicao2 < 0 || posicao1 >= lista->tamanho || posicao2 >= lista->tamanho || posicao1 == posicao2 || lista->tamanho < 2) {
        printf("Posições incorretas\n");
        return;
    }

    No *troca1 = lista->cabeca->prox;
    for (int i = 0; i < posicao1; i++) {
        troca1 = troca1->prox;
    }

    No *troca2 = lista->cabeca->prox;
    for (int j = 0; j < posicao2; j++) {
        troca2 = troca2->prox;
    }

    if (posicao1 == posicao2 + 1 || posicao1 == posicao2 - 1) {
        if (troca1->prox == troca2) {
            troca1->prox = troca2->prox;
            if (troca2->prox != NULL) {
                troca2->prox->ant = troca1;
            }

            troca1->ant->prox = troca2;
            troca2->ant = troca1->ant;

            troca1->ant = troca2;
            troca2->prox = troca1;

            return;
        }
        else if (troca2->prox == troca1) {
            troca2->prox = troca1->prox;
            if (troca1->prox != NULL) {
                troca1->prox->ant = troca2;
            }

            troca2->ant->prox = troca1;
            troca1->ant = troca2->ant;

            troca2->ant = troca1;
            troca1->prox = troca2;

            return;
        }
    }

    No *aux = troca1;
    troca1->ant = troca2->ant;
    troca2->ant->prox = troca1;
    troca1->prox = troca2->prox;
    troca2->prox->ant = troca1;

    troca2->ant = aux->ant;
    aux->ant->prox = troca2;
    troca2->prox = aux->prox;
    aux->prox->ant = troca2;

}

void ordenarCrescenteDados(Lista *lista) {

    if (lista->tamanho < 2) {
        return;
    }

    No *primeiro = lista->cabeca->prox;
    No *segundo;
    for (int i = 0; i < lista->tamanho - 1; i++) {
        segundo = primeiro->prox;
        for (int j = i + 1; j < lista->tamanho; j++) {
            if (segundo->dado < primeiro->dado) {
                int troca = primeiro->dado;
                primeiro->dado = segundo->dado;
                segundo->dado = troca;
            }
            segundo = segundo->prox;
        }
        primeiro = primeiro->prox;
    }
}

void ordenarDecrescenteDados(Lista *lista) {

    if (lista->tamanho < 2) {
        return;
    }

    No *primeiro = lista->cabeca->prox;
    No *segundo;
    for (int i = 0; i < lista->tamanho - 1; i++) {
        segundo = primeiro->prox;
        for (int j = i + 1; j < lista->tamanho; j++) {
            if (segundo->dado > primeiro->dado) {
                int troca = primeiro->dado;
                primeiro->dado = segundo->dado;
                segundo->dado = troca;
            }
            segundo = segundo->prox;
        }
        primeiro = primeiro->prox;
    }
}

int tamanhoLista(Lista *lista) {
    return lista->tamanho;
}

void imprimirLista(Lista *lista) {

    if (estaVazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    No *aux = lista->cabeca->prox;
    while (aux != NULL) {
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int apagarLista(Lista *lista) {

    if (estaVazio(lista)) {
        printf("Lista vazia\n");
        free(lista->cabeca);
        free(lista);
        return 0;
    }

    No *aux = lista->cabeca;
    No *apagar;
    while (aux != NULL) {
        apagar = aux;
        aux = aux->prox;
        free(apagar);
    }

    free(lista);
    return 1;
}