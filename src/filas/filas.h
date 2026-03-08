#ifndef FILAS_H
#define FILAS_H
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
} Fila;

Fila *criar_fila();
bool esta_vazio(Fila *fila);
void enfileirar(Fila *fila, int dado);
int desenfileirar(Fila *fila);
int consultar_valor(Fila *fila);
int tamanho_fila(Fila *fila);
void inverter_fila(Fila *fila);
Fila *mesclar_filas(Fila *fila1, Fila *fila2);
bool comparar_filas(Fila *fila1, Fila *fila2);
void imprimir_fila(Fila *fila);
int apagar_fila(Fila *fila);

#endif