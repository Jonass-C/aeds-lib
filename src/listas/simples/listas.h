#ifndef LISTAS_H
#define LISTAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *cabeca;
} Lista;

Lista *criar_lista();
bool esta_vazio(Lista *lista);
void inserir_elemento_inicio(Lista *lista, int dado);
void inserir_elemento_final(Lista *lista, int dado);
void inserir_por_posicao(Lista *lista, int posicao, int dado);
void remover_elemento_inicio(Lista *lista);
void remover_elemento_final(Lista *lista);
void remover_por_posicao(Lista *lista, int posicao);
void remover_por_dado(Lista *lista, int dado);
int procurar_por_posicao(Lista *lista, int posicao);
int procurar_por_dado(Lista *lista, int dado);
bool contem_dado(Lista *lista, int dado);
int ocorrencias_dado(Lista *lista, int dado);
void troca_dados(Lista *lista, int m, int n);
void troca_elementos(Lista *lista, int m, int n);
void troca_seguinte(Lista *lista, int pos);
void ordenar_crescente_dados(Lista *lista);
void ordenar_decrescente_dados(Lista *lista);
int tamanho_lista(Lista *lista);
Lista *mesclar_listas(Lista *lista1, Lista *lista2);
void imprimir_lista(Lista *lista);
int apagar_lista(Lista *lista);

#endif