#ifndef LISTASDUPLAS_H
#define LISTASDUPLAS_H
#include <stdio.h>
#include <stdlib.h>
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
Lista *criar_lista();
bool esta_vazio(Lista *lista);
void inserir_por_posicao(Lista *lista, int posicao, int dado);
void inserir_no_inicio(Lista *lista, int dado);
void inserir_no_fim(Lista *lista, int dado);
void remover_por_posicao(Lista *lista, int posicao);
void trocar_elementos(Lista *lista, int posicao1, int posicao2);
void ordenar_crescente_dados(Lista *lista);
void ordenar_decrescente_dados(Lista *lista);
void imprimir_lista(Lista *lista);
int apagar_lista(Lista *lista);

#endif