#include "avl.h"

void inicializa(No** arvore) {
    *arvore = NULL;
}

int pesquisa(No* raiz, long valor) {
    if (raiz == NULL)
        return 0;

    if (valor < raiz->valor)
        return pesquisa(raiz->esq, valor);
    else if (valor > raiz->valor)
        return pesquisa(raiz->dir, valor);
    else // valor == raiz->valor
        return 1;
}

int insere(long valor, No** raiz) {
    if (*raiz == NULL) {
        *raiz = cria_no(valor);
        return 1;
    }

    if (valor < (*raiz)->valor)
        insere(valor, &(*raiz)->esq);
    else
        insere(valor, &(*raiz)->dir);

    balanceamento(raiz);
    return 1;
}

No *cria_no(long valor) {
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

int retira(long valor, No** raiz) {
    if (*raiz == NULL)
        return 0;

    if (valor < (*raiz)->valor)
        return retira(valor, &(*raiz)->esq);
    else if (valor > (*raiz)->valor)
        return retira(valor, &(*raiz)->dir);
    else {
        No* aux;
        if ((*raiz)->esq == NULL) {
            aux = *raiz;
            *raiz = (*raiz)->dir;
            free(aux);
        }
        else if ((*raiz)->dir == NULL) {
            aux = *raiz;
            *raiz = (*raiz)->esq;
            free(aux);
        }
        else // nó com dois filhos
            antecessor(*raiz, &(*raiz)->esq);

        return 1;
    }
}

void antecessor(No* remover, No** sub_esq) {
    if ((*sub_esq)->dir != NULL)
        antecessor(remover, &(*sub_esq)->dir);
    else {
        remover->valor = (*sub_esq)->valor;
        No* aux = *sub_esq;
        *sub_esq = (*sub_esq)->esq;
        free(aux);
    }
}

void central(No* raiz) {
    if (raiz == NULL)
        return;

    central(raiz->esq);
    printf("%ld\n", raiz->valor);
    central(raiz->dir);
}

int fb(No* raiz) {
    if (raiz == NULL)
        return 0;

    return altura(raiz->esq) - altura(raiz->dir);
}

int altura(No* raiz) {
    int alt_esq, alt_dir;
    if (raiz == NULL)
        return 0;

    alt_esq = altura(raiz->esq);
    alt_dir = altura(raiz->dir);

    if (alt_esq > alt_dir)
        return alt_esq + 1;
    else
        return alt_dir + 1;
}

int balanceamento(No** raiz) {
    int fator = fb(*raiz);
    if (fator > 1)
        return balanca_esquerda(raiz);
    else if (fator < -1)
        return balanca_direita(raiz);
    else
        return 0;
}

void rse(No** raiz) {
    No* aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    *raiz = aux;
}

void rsd(No** raiz) {
    No* aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    *raiz = aux;
}

int balanca_esquerda(No** raiz) {
    if (fb((*raiz)->esq) <= 0) {
        rsd(raiz);
        return 1;
    }
    else {
        rse(&(*raiz)->esq);
        rsd(raiz);
        return 1;
    }
    return 0;
}

int balanca_direita(No** raiz) {
    if (fb((*raiz)->dir) <= 0) {
        rse(raiz);
        return 1;
    }
    else {
        rsd(&(*raiz)->dir);
        rse(raiz);
        return 1;
    }
    return 0;
}

void imprimir_alturas(No* raiz) {
    if (!raiz) return;
    imprimir_alturas(raiz->esq);
    printf("Valor: %ld, FB: %d\n", raiz->valor, fb(raiz));
    imprimir_alturas(raiz->dir);
}