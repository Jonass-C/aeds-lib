#include "sort.h"

void select_sort(array_t* pA,long* att,long*comp) {
    int i, j, min;
    item_t aux;
    for (i = 0; i < pA->n-1; i++) {
        min = i;
        for (j = i+1; j < pA->n; j++) {
            (*comp)++;
            if (pA->item[j].key < pA->item[min].key) {
                min = j;
            }
        }
        (*att)+=3;
        aux           = pA->item[min];
        pA->item[min] = pA->item[i];
        pA->item[i]   = aux;
    }
}

void select_sort_otimizado(array_t* pA,long* att,long* comp) {
    int min;
    item_t aux;
    for (int i = 0; i < pA->n-1; i++) {
        min = i;
        for (int j = i+1; j < pA->n; j++) {
            (*comp)++;
            if (pA->item[j].key < pA->item[min].key) {
                min = j;
            }
        }
        if (i != min) {
            (*att)+=3;
            aux           = pA->item[min];
            pA->item[min] = pA->item[i];
            pA->item[i]   = aux;
        }
    }
}