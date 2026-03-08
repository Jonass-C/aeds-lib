#include "filas.h"

Fila *criar_fila() {

    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->tamanho = 0;

    fila->cabeca = (No*) malloc(sizeof(No));
    fila->cabeca->dado = -1;
    fila->cabeca->prox = NULL;

    return fila;
}

bool esta_vazio(Fila *fila) {
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

    if (esta_vazio(fila)) {
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

int consultar_valor(Fila *fila) {

    if (esta_vazio(fila)) {
        printf("Lista vazia\n");
        return -1;
    }

    return fila->cabeca->prox->dado;
}

int tamanho_fila(Fila *fila) {
    return fila->tamanho;
}

void inverter_fila(Fila *fila) {

    if (fila->tamanho < 2) {
        return;
    }

    int dados[fila->tamanho];
    int tamanho = fila->tamanho;

    for (int i = 0; i < tamanho; i++) {
        dados[i] = desenfileirar(fila);
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        enfileirar(fila, dados[i]);
    }
}

Fila *mesclar_filas(Fila *fila1, Fila *fila2) {

    Fila *mesclada = criar_fila();

    No *no1 = fila1->cabeca->prox;

    while (no1 != NULL) {
        enfileirar(mesclada, no1->dado);
        no1 = no1->prox;
    }

    No *no2 = fila2->cabeca->prox;

    while (no2 != NULL) {
        enfileirar(mesclada, no2->dado);
        no2 = no2->prox;
    }

    return mesclada;
}

bool comparar_filas(Fila *fila1, Fila *fila2) {

    if (fila1->tamanho != fila2->tamanho || esta_vazio(fila1) || esta_vazio(fila2)) {
        return false;
    }

    No *no1 = fila1->cabeca->prox;
    No *no2 = fila2->cabeca->prox;

    while (no1 != NULL && no2 != NULL) {
        if (no1->dado != no2->dado) {
            return false;
        }
        no1 = no1->prox;
        no2 = no2->prox;
    }

    return true;
}

void imprimir_fila(Fila *fila) {

    if (esta_vazio(fila)) {
        printf("Fila vazia\n");
        return;
    }

    No *aux = fila->cabeca->prox;
    while (aux != NULL) {
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int apagar_fila(Fila *fila) {

    if (esta_vazio(fila)) {
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