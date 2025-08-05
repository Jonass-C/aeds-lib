#include <stdio.h>
#include "arvore.h"

int main() {

    // Criando nó raiz da árvore
    No *raiz = criarNo(10);

    // Adicionando nós internos
    raiz->esquerda = criarNo(5);
    raiz->direita  = criarNo(15);

    // Adicionando nós folhas
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita  = criarNo(7);

    raiz->direita->esquerda = criarNo(12);
    raiz->direita->direita  = criarNo(18);

    printf("\nPercurso em pre-ordem: ");
    preOrdem(raiz);

    printf("\nPercurso em ordem: ");
    emOrdem(raiz);

    printf("\nPercurso em pos-ordem: ");
    posOrdem(raiz);

    printf("\n");

    return 0;
}