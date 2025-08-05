#ifndef FILAS_H
#define FILAS_H
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *cabeca;
} Fila;

Fila *criarFila();
bool estaVazio(Fila *fila);
void enfileirar(Fila *fila, int dado);
int desenfileirar(Fila *fila);
int consultarValor(Fila *fila);
int tamanhoFila(Fila *fila);
void inverterFila(Fila *fila);
Fila *mesclarFilas(Fila *fila1, Fila *fila2);
bool compararFilas(Fila *fila1, Fila *fila2);
void imprimirFila(Fila *fila);
int apagarFila(Fila *fila);

#endif