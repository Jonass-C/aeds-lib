#ifndef LISTAS_H
#define LISTAS_H
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *cabeca;
} Lista;

Lista *criarLista();
bool estaVazio(Lista *lista);
void inserirElementoInicio(Lista *lista, int dado);
void inserirElementoFinal(Lista *lista, int dado);
void inserirPorPosicao(Lista *lista, int posicao, int dado);
void removerElementoInicio(Lista *lista);
void removerElementoFinal(Lista *lista);
void removerPorPosicao(Lista *lista, int posicao);
void removerPorDado(Lista *lista, int dado);
int procurarPorPosicao(Lista *lista, int posicao);
int procurarPorDado(Lista *lista, int dado);
bool contemDado(Lista *lista, int dado);
int ocorrenciasDado(Lista *lista, int dado);
void trocaDados(Lista *lista, int m, int n);
void trocaElementos(Lista *lista, int m, int n);
void trocaSeguinte(Lista *lista, int pos);
void ordenarCrescenteDados(Lista *lista);
void ordenarDecrescenteDados(Lista *lista);
int tamanhoLista(Lista *lista);
Lista *mesclarListas(Lista *lista1, Lista *lista2);
void imprimirLista(Lista *lista);
int apagarLista(Lista *lista);

#endif