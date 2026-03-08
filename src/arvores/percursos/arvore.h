#ifndef ARVORE_H
#define ARVORE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// por enquanto há apenas as funções mais simples de percurso
No *criar_no(int valor);
void pre_ordem(No *raiz);
void em_ordem(No *raiz);
void pos_ordem(No *raiz);

#endif