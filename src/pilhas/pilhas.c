#include "pilhas.h"

Pilha *criar_pilha() {

    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->tamanho = 0;

    pilha->topo = (No*) malloc(sizeof(No));
    pilha->topo->prox = NULL;
    pilha->topo->dado = -1;

    return pilha;
}

bool esta_vazio(Pilha *pilha) {
    return pilha->topo->prox == NULL;
}

void empilha(Pilha *pilha, int dado) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->prox = pilha->topo->prox;

    pilha->topo->prox = adicionar;
    pilha->tamanho++;
}

int desempilha(Pilha *pilha) {

    if (esta_vazio(pilha)) {
        return -1;
    }

    No *remover = pilha->topo->prox;
    pilha->topo->prox = remover->prox;

    int dado = remover->dado;
    free(remover);
    pilha->tamanho--;

    return dado;
}

void remover_item(Pilha *pilha, int dado) {

    Pilha *aux = criar_pilha();

    while (!esta_vazio(pilha)) {
        int valor = desempilha(pilha);
        if (valor == dado) {
            break;
        } else {
            empilha(aux, valor);
        }
    }

    while (!esta_vazio(aux)) {
        empilha(pilha, desempilha(aux));
    }
}

int consultar_valor(Pilha *pilha) {

    if (esta_vazio(pilha)) {
        printf("Pilha vazia\n");
        return -1;
    }

    return pilha->topo->prox->dado;
}

int tamanho_pilha(Pilha *pilha) {

    // return pilha->tamanho;

    // lógica para retornar o tamanho
    if (esta_vazio(pilha)) {
        return 0;
    }

    No *aux = pilha->topo;
    int tamanho = 0;
    for (int i = 0; i < pilha->tamanho; i++) {
        aux = aux->prox;
        tamanho++;
    }

    return tamanho;
}

void ordenar_pilha(Pilha *pilha) {

    Pilha *aux = criar_pilha();

    while (!esta_vazio(pilha)) {
        int valor = desempilha(pilha);

        while (!esta_vazio(aux) && aux->topo->prox->dado > valor) {
            empilha(pilha, desempilha(aux));
        }

        empilha(aux, valor);
    }

    while (!esta_vazio(aux)) {
        empilha(pilha, desempilha(aux));
    }
}

void inverter_pilha(Pilha *pilha) {

    // uso de duas pilhas auxiliares

    Pilha *aux1 = criar_pilha();
    while (!esta_vazio(pilha)) {
        empilha(aux1, desempilha(pilha));
    }

    Pilha *aux2 = criar_pilha();
    while (!esta_vazio(aux1)) {
        empilha(aux2, desempilha(aux1));
    }

    while (!esta_vazio(aux2)) {
        empilha(pilha, desempilha(aux2));
    }
}

void imprimir_pilha(Pilha *pilha) {

    if (esta_vazio(pilha)) {
        printf("Pilha vazia\n");
        return;
    }

    No *aux = pilha->topo->prox;
    while (aux != NULL) {
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int apagar_pilha(Pilha *pilha) {

    if (esta_vazio(pilha)) {
        printf("Pilha vazia\n");
        free(pilha->topo);
        free(pilha);
        return 0;
    }

    No *aux = pilha->topo;
    No *apagar;
    while (aux != NULL) {
        apagar = aux;
        aux = aux->prox;
        free(apagar);
    }

    free(pilha);
    return 1;
}