#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// por enquanto há apenas as funções mais simples de percurso
No *criarNo(int valor);
void preOrdem(No *raiz);
void emOrdem(No *raiz);
void posOrdem(No *raiz);

#endif