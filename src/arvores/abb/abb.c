#include "abb.h"

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
        return insere(valor, &(*raiz)->esq);
    else if (valor > (*raiz)->valor)
        return insere(valor, &(*raiz)->dir);
    else
        return 0;
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

void antecessor(No* remover, No** subEsq) {
    if ((*subEsq)->dir != NULL)
        antecessor(remover, &(*subEsq)->dir);
    else {
        remover->valor = (*subEsq)->valor;
        No* aux = *subEsq;
        *subEsq = (*subEsq)->esq;
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
