#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *criarNo(int valor) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->valor = valor;
    adicionar->esquerda = NULL;
    adicionar->direita = NULL;

    return adicionar;
}

void preOrdem(No *raiz) {
    if (raiz == NULL) return;

    printf("%d ", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem(No *raiz) {
    if (raiz == NULL) return;

    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

void posOrdem(No *raiz) {
    if (raiz == NULL) return;

    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->valor);
}