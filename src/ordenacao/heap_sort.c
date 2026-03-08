#include "sort.h"

void heap_sort(array_t *pA, long *att, long *comp) {
    int n = pA->n;
    constroi(pA, n, att, comp);

    while (n > 1) {
        item_t aux = pA->item[0];
        pA->item[0] = pA->item[n-1];
        pA->item[n-1] = aux;
        (*att)+=3;
        n--;
        refaz(pA, 0, n-1, att, comp);
    }
}

void constroi(array_t* pA, int n, long* att, long* comp) {
    int esq = (n/2)-1;
    while (esq >= 0){
        refaz(pA, esq, n-1, att, comp);
        esq--;
    }
}

void refaz(array_t* pA, int esq, int dir, long* att, long* comp) {
    int i = esq, j = esq*2+1;
    item_t aux = pA->item[i];

    while (j<=dir) {
        if (j < dir) {
            (*comp)++;
            if (pA->item[j].key < pA->item[j+1].key) j++;
        }
        (*comp)++;
        if (aux.key >= pA->item[j].key) break;
        pA->item[i] = pA->item[j];
        (*att)++;
        i = j;
        j = i*2+1;
    }
    pA->item[i] = aux;
    (*att)++;
}