#ifndef AEDS_LIB_TABELA_HASH_H
#define AEDS_LIB_TABELA_HASH_H

#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 7

typedef struct No {
	int chave;
	struct No *prox;
} No;

typedef struct {
	No *tabela[BUCKETS];
} tabela_hash;

void inicializar(tabela_hash *h);
int funcao_hash (int chave);
int buscar(tabela_hash *h, int chave);
void inserir(tabela_hash *h, int chave);
void mostrar(tabela_hash *h);
void liberar_tabela(tabela_hash *h);
void encontrar_chave(tabela_hash *th, int i);

#endif //AEDS_LIB_TABELA_HASH_H