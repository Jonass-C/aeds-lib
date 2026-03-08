#include "tabela_hash.h"

/*!
 * @brief Hashing ABERTO, usando o método da DIVISÃO e não permitindo números negativos.
 */

// somente para ter todos os nós nulos
void inicializar(tabela_hash *h) {
	for (int i = 0; i < BUCKETS; i++) {
		h->tabela[i] = NULL;
	}
}

// função do slide: h(k) = (k % 13) ou h(k) = k mod m, onde m = buckets e k é a chave
int funcao_hash (int chave) {
	return chave % BUCKETS;
}

int buscar(tabela_hash *h, int chave) {
	int indice = funcao_hash(chave);
	No *atual = h->tabela[indice];

	while (atual != NULL) {
		if (atual->chave == chave) {
			return 1;
		}
		atual = atual->prox;
	}
	return 0;
}

void inserir(tabela_hash *h, int chave) {
	if (buscar(h, chave)) {
		printf("Chave %d já existe. Pulando inserção\n", chave);
		return;
	}

	int indice = funcao_hash(chave);

	No *novo_no = (No*) malloc(sizeof(No));
	if (novo_no == NULL) {
		printf("Erro de alocação\n");
		exit(1);
	}

	novo_no->chave = chave;
	novo_no->prox = h->tabela[indice];
	h->tabela[indice] = novo_no;
}

void mostrar(tabela_hash *h) {
	printf("\n");
	for (int i = 0; i < BUCKETS; i++) {
		printf("[%d]: ", i);
		No *atual = h->tabela[i];
		while (atual != NULL) {
			printf("%d -> ", atual->chave);
			atual = atual->prox;
		}
		printf("NULL\n");
	}
	printf("\n");
}

void liberar_tabela(tabela_hash *h) {
	for (int i = 0; i < BUCKETS; i++) {
		No *atual = h->tabela[i];
		while (atual != NULL) {
			No *temp = atual;
			atual = atual->prox;
			free(temp);
		}
		h->tabela[i] = NULL;
	}
}

void encontrar_chave(tabela_hash *th, int i) {
	if (buscar(th, i)) {
		printf("Chave %d encontrada!\n", i);
	}
	else {
		printf("Chave %d não encontrada!\n", i);
	}
}