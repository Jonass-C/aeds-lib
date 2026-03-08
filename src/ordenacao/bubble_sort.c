#include "sort.h"

void bubble_sort(array_t* pA, long* att, long* comp) {
    item_t aux;
    for(int i = 0; i < pA->n-1; i++){
        for(int j = 1; j < pA->n-i; j++){
            (*comp)++;
            if(pA->item[j].key < pA->item[j-1].key) {
                (*att)+=3;
                aux               = pA->item[j];
                pA->item[j]       = pA->item[j-1];
                pA->item[j-1]     = aux;
            }
        }
    }
}

void bubble_sort_otimizado(array_t* pA, long* att, long* comp) {
    int troca;
    item_t aux;
    for (int i = 0; i < pA->n-1; i++) {
        troca = 0;
        for (int j = 1; j < pA->n-i; j++) {
            (*comp)++;
            if (pA->item[j].key < pA->item[j-1].key) {
                (*att)+=3;
                aux               = pA->item[j];
                pA->item[j]       = pA->item[j-1];
                pA->item[j-1]     = aux;
                troca = 1;
            }
        }
        if (troca == 0) break;
    }
}