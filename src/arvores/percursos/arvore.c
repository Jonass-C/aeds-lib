#include "arvore.h"

No *criar_no(int valor) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->valor = valor;
    adicionar->esquerda = NULL;
    adicionar->direita = NULL;

    return adicionar;
}

void pre_ordem(No *raiz) {
    if (raiz == NULL) return;

    printf("%d ", raiz->valor);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void em_ordem(No *raiz) {
    if (raiz == NULL) return;

    em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    em_ordem(raiz->direita);
}

void pos_ordem(No *raiz) {
    if (raiz == NULL) return;

    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
}