#include "sort.h"

void quick_sort(array_t* pA,long* att,long* comp){
    ordena(pA, 0, pA->n-1, att, comp);
}

void ordena(array_t* pA, int esq, int dir, long* att, long* comp) {
    int i, j;
    particao(pA, esq, dir, &i, &j, att, comp);
    if (esq < j) ordena(pA, esq, j, att, comp);
    if (i < dir) ordena(pA, i, dir, att, comp);
}

void particao(array_t* pA, int esq, int dir, int* i, int* j, long* att, long* comp) {
    item_t x, aux;
    *i = esq;
    *j = dir;
    x = pA->item[(*i + *j)/2];
    (*att)++;
    do {
        while (x.key > pA->item[*i].key) {
            (*comp)++;
            (*i)++;
        }
        (*comp)++;
        while (x.key < pA->item[*j].key) {
            (*comp)++;
            (*j)--;
        }
        (*comp)++;
        if (*i <= *j) {
            aux = pA->item[*i];
            pA->item[*i] = pA->item[*j];
            pA->item[*j] = aux;
            (*att)+=3;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}