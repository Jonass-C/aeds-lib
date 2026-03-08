#include "arvore.h"

int main() {

    // Criando nó raiz da árvore
    No *raiz = criar_no(10);

    // Adicionando nós internos
    raiz->esquerda = criar_no(5);
    raiz->direita  = criar_no(15);

    // Adicionando nós folhas
    raiz->esquerda->esquerda = criar_no(3);
    raiz->esquerda->direita  = criar_no(7);

    raiz->direita->esquerda = criar_no(12);
    raiz->direita->direita  = criar_no(18);

    printf("\nPercurso em pre-ordem: ");
    pre_ordem(raiz);

    printf("\nPercurso em ordem: ");
    em_ordem(raiz);

    printf("\nPercurso em pos-ordem: ");
    pos_ordem(raiz);

    printf("\n");

    return 0;
}