#include "listas.h"

Lista *criar_lista() {

    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->tamanho = 0;

    lista->cabeca = (No*) malloc(sizeof(No));
    lista->cabeca->dado = -1;
    lista->cabeca->prox = NULL;

    return lista;
}

bool esta_vazio(Lista *lista) {
    return lista->cabeca->prox == NULL;
}

void inserir_elemento_inicio(Lista *lista, int dado) {

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;

    No *aux = lista->cabeca->prox;
    lista->cabeca->prox = adicionar;
    adicionar->prox = aux;
    lista->tamanho++;
}

void inserir_elemento_final(Lista *lista, int dado) {

    No *aux = lista->cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    No *adicionar = (No*) malloc(sizeof(No));
    adicionar->dado = dado;
    adicionar->prox = NULL;
    aux->prox = adicionar;
    lista->tamanho++;
}

void inserir_por_posicao(Lista *lista, int posicao, int dado) {

    if (posicao >= 0 && posicao <= lista->tamanho) {
        No *aux = lista->cabeca;
        for (int i = 0; i < posicao; i++) {
            aux = aux->prox;
        }

        No *adicionar = (No*) malloc(sizeof(No));
        adicionar->dado = dado;
        adicionar->prox = aux->prox;
        aux->prox = adicionar;
        lista->tamanho++;
    }
    else {
        printf("Posição incorreta\n");
        return;
    }
}

void remover_elemento_inicio(Lista *lista) {

    if (esta_vazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    No *aux = lista->cabeca->prox;
    lista->cabeca->prox = aux->prox;
    free(aux);
    lista->tamanho--;
}

void remover_elemento_final(Lista *lista) {

    if (esta_vazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    No *aux = lista->cabeca;
    for (int i = 0; i < lista->tamanho - 1; i++) {
        aux = aux->prox;
    }

    No *remover = aux->prox;
    aux->prox = NULL;
    free(remover);
    lista->tamanho--;
}

void remover_por_posicao(Lista *lista, int posicao) {

    if (esta_vazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    if (posicao >= 0 && posicao < lista->tamanho) {
        No *aux = lista->cabeca;
        for (int i = 0; i < posicao; i++) {
            aux = aux->prox;
        }

        No *remover = aux->prox;
        aux->prox = remover->prox;
        free(remover);
        lista->tamanho--;
    }
    else {
        printf("Posição incorreta\n");
        return;
    }
}

void remover_por_dado(Lista *lista, int dado) {

    if (esta_vazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    No *remover = lista->cabeca->prox;
    int posicao = -1;
    for (int i = 0; i < lista->tamanho; i++) {
        if (remover->dado == dado) {
            posicao = i;
            break;
        }
        remover = remover->prox;
    }

    if (posicao == -1) {
        printf("Dado não encontrado\n");
        return;
    }
    else if (posicao == 0) {
        lista->cabeca->prox = remover->prox;
        free(remover);
        lista->tamanho--;
    }
    else {
        No *aux = lista->cabeca->prox;
        for (int i = 0; i < posicao - 1; i++) {
            aux = aux->prox;
        }
        aux->prox = remover->prox;
        free(remover);
        lista->tamanho--;
    }
}

int procurar_por_posicao(Lista *lista, int posicao) {

    if (posicao >= 0 && posicao < lista->tamanho) {

        No *aux = lista->cabeca->prox;
        for (int i = 0; i < posicao; i++) {
            aux = aux->prox;
        }
        return(aux->dado);
    }
    else return -1;
}

int procurar_por_dado(Lista *lista, int dado) {

    No *aux = lista->cabeca->prox;
    for (int i = 0; i < lista->tamanho; i++) {
        if (aux->dado == dado) {
            return(i);
        }
        aux = aux->prox;
    }

    return -1;
}

bool contem_dado(Lista *lista, int dado) {

    No *aux = lista->cabeca->prox;
    for (int i = 0; i < lista->tamanho; i++) {
        if (aux->dado == dado) {
            return true;
        }
        aux = aux->prox;
    }

    return false;
}

int ocorrencias_dado(Lista *lista, int dado) {

    No *aux = lista->cabeca->prox;
    int ocorrencias = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (aux->dado == dado) {
            ocorrencias++;
        }
        aux = aux->prox;
    }

    return ocorrencias;
}

void troca_dados(Lista *lista, int m, int n) {

    No *aux1 = lista->cabeca->prox;
    for (int i = 0; i < m; i++) {
        aux1 = aux1->prox;
    }

    No *aux2 = lista->cabeca->prox;
    for (int i = 0; i < n; i++) {
        aux2 = aux2->prox;
    }

    int dado = aux1->dado;
    aux1->dado = aux2->dado;
    aux2->dado = dado;
}

void troca_elementos(Lista *lista, int m, int n) {

    No *antM = lista->cabeca;
    for (int i = 0; i < m; i++) {
        antM = antM->prox;
    }

    No *antN = lista->cabeca;
    for (int i = 0; i < n; i++) {
        antN = antN->prox;
    }

    No *N = antN->prox;
    No *postN = N->prox;
    No *M = antM->prox;
    No *postM = M->prox;

    antM->prox = N;
    N->prox = postM;

    antN->prox = M;
    M->prox = postN;
}

void troca_seguinte(Lista *lista, int pos) {

    No *ant = lista->cabeca;
    for (int i = 0; i < pos-1; i++) {
        ant = ant->prox;
    }

    No *troca1 = ant->prox;
    No *troca2 = troca1->prox;

    ant->prox = troca2;
    troca1->prox = troca2->prox;
    troca2->prox = troca1;
}

void ordenar_crescente_dados(Lista *lista) {

    if (lista->tamanho < 2) {
        return;
    }

    No *primeiro = lista->cabeca->prox;
    No *segundo;
    for (int i = 0; i < lista->tamanho - 1; i++) {
        segundo = primeiro->prox;
        for (int j = i + 1; j < lista->tamanho; j++) {
            if (segundo->dado < primeiro->dado) {
                int troca = primeiro->dado;
                primeiro->dado = segundo->dado;
                segundo->dado = troca;
            }
            segundo = segundo->prox;
        }
        primeiro = primeiro->prox;
    }
}

void ordenar_decrescente_dados(Lista *lista) {

    if (lista->tamanho < 2) {
        return;
    }

    No *primeiro = lista->cabeca->prox;
    No *segundo;
    for (int i = 0; i < lista->tamanho - 1; i++) {
        segundo = primeiro->prox;
        for (int j = i + 1; j < lista->tamanho; j++) {
            if (segundo->dado > primeiro->dado) {
                int troca = primeiro->dado;
                primeiro->dado = segundo->dado;
                segundo->dado = troca;
            }
            segundo = segundo->prox;
        }
        primeiro = primeiro->prox;
    }
}

int tamanho_lista(Lista *lista) {

    // return lista->tamanho;

    // lógica para retornar o tamanho
    if (esta_vazio(lista)) {
        return 0;
    }

    No *aux = lista->cabeca;
    int tamanho = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        aux = aux->prox;
        tamanho++;
    }

    return tamanho;
}

Lista *mesclar_listas(Lista *lista1, Lista *lista2) {

    Lista *listaFinal = criar_lista();
    listaFinal->tamanho = lista1->tamanho + lista2->tamanho;

    No *elementoLista = listaFinal->cabeca;

    No *auxL1 = lista1->cabeca->prox;
    while (auxL1 != NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->dado = auxL1->dado;
        novo->prox = NULL;
        elementoLista->prox = novo;
        elementoLista = novo;
        auxL1 = auxL1->prox;
    }

    No *auxL2 = lista2->cabeca->prox;
    while (auxL2 != NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->dado = auxL2->dado;
        novo->prox = NULL;
        elementoLista->prox = novo;
        elementoLista = novo;
        auxL2 = auxL2->prox;
    }

    return listaFinal;
}

void imprimir_lista(Lista *lista) {

    if (esta_vazio(lista)) {
        printf("Lista vazia\n");
        return;
    }

    No *aux = lista->cabeca->prox;

    while (aux != NULL) {
        printf("\n%d", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int apagar_lista(Lista *lista) {

    if (esta_vazio(lista)) {
        printf("Lista vazia\n");
        free(lista->cabeca);
        free(lista);
        return 0;
    }

    No *aux = lista->cabeca;
    No *apagar;
    while (aux != NULL) {
        apagar = aux;
        aux = aux->prox;
        free(apagar);
    }

    free(lista);
    return 1;
}