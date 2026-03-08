#include "sort.h"

void insertion_sort(array_t* pA,long* att,long* comp) {
    int j;
    item_t aux;
    for (int i = 1; i < pA->n; i++) {
        aux = pA->item[i];
        (*att)++;
        j = i-1;
        while ((j >= 0) && (aux.key < pA->item[j].key)) {
            (*comp)++;
            (*att)++;
            pA->item[j+1] = pA->item[j];
            j--;
        }
        (*att)++;
        pA->item[j+1] = aux;
    }
}

void insertion_sort_otimizado(array_t* pA, long* att, long* comp) {
    int j;
    item_t aux;
    int min = 0;
    for (int i = 1; i < pA->n; i++) {
        (*comp)++;
        if (pA->item[i].key < pA->item[min].key) {
            min = i;
        }
    }
    if (min != 0) {
        aux = pA->item[0];
        pA->item[0] = pA->item[min];
        pA->item[min] = aux;
        (*att) += 3;
    }
    for (int i = 2; i < pA->n; i++) {
        aux = pA->item[i];
        (*att)++;
        j = i - 1;
        while (aux.key < pA->item[j].key) {
            (*comp)++;
            (*att)++;
            pA->item[j + 1] = pA->item[j];
            j--;
        }
        (*comp)++;
        (*att)++;
        pA->item[j + 1] = aux;
    }
}