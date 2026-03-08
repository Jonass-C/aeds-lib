#include "sort.h"

void merge_sort(array_t* pA,long* att,long* comp){
    ordena_merge(pA, 0, pA->n-1, att, comp);
}
void ordena_merge(array_t* pA, int ini, int fim, long* att, long* comp) {
    int meio;
    if (fim == ini) return;

    meio = (ini+fim)/2;
    ordena_merge(pA, ini, meio, att, comp);
    ordena_merge(pA, meio+1, fim, att, comp);
    intercala(pA, ini, meio, fim, att, comp);
    return;
}
void intercala(array_t* pA, int ini, int meio, int fim, long* att, long* comp) {
    int i, j, k;
    item_t* C = (item_t*) malloc((fim-ini+1)*sizeof(item_t));
    for (i = ini, j = meio+1, k = 0; k <= fim-ini; k++) {
        if (i == meio+1) {
            C[k] = pA->item[j++];
            (*att)++;
            continue;
        }
        if (j == fim+1) {
            C[k] = pA->item[i++];
            (*att)++;
            continue;
        }
        (*comp)++;
        if (pA->item[i].key < pA->item[j].key)
            C[k] = pA->item[i++];
        else
            C[k] = pA->item[j++];
        (*att)++;
    }
    for (i = ini, k = 0; i <= fim; i++, k++) {
        pA->item[i] = C[k];
        (*att)++;
    }
    free(C);
}