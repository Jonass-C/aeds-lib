#ifndef LISTASDUPLAS_H
#define LISTASDUPLAS_H
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
    struct no *ant;
} No;

typedef struct {
    int tamanho;
    No *cabeca;
} Lista;

// apenas as funções que possuem lógicas diferentes de listas simples
Lista *criarLista();
bool estaVazio(Lista *lista);
void inserirPorPosicao(Lista *lista, int posicao, int dado);
void inserirNoInicio(Lista *lista, int dado);
void inserirNoFim(Lista *lista, int dado);
void removerPorPosicao(Lista *lista, int posicao);
void trocarElementos(Lista *lista, int posicao1, int posicao2);
void ordenarCrescenteDados(Lista *lista);
void ordenarDecrescenteDados(Lista *lista);
void imprimirLista(Lista *lista);
int apagarLista(Lista *lista);

#endif