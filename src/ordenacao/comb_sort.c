#include "sort.h"

void comb_sort(array_t* pA, long* att, long* comp) {
    int intervalo = pA->n;
    int troca = 1;
    const float encolhimento = 1.3;
    item_t temp;
    while (intervalo > 1 || troca) {
        intervalo = (int)(intervalo / encolhimento);
        if (intervalo < 1) intervalo = 1;
        troca = 0;
        for (int i = 0; i + intervalo < pA->n; i++) {
            (*comp)++;
            if (pA->item[i].key > pA->item[i + intervalo].key) {
                temp = pA->item[i];
                pA->item[i] = pA->item[i + intervalo];
                pA->item[i + intervalo] = temp;
                (*att) += 3;
                troca = 1;
            }
        }
    }
}