#include "sort.h"

void shell_sort(array_t* pA,long* att,long* comp){
    int intervalo, i, j;
    item_t aux;
    for (intervalo = pA->n / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < pA->n; i++) {
            aux = pA->item[i];
            (*att)++;
            j = i;
            while (j >= intervalo && aux.key < pA->item[j - intervalo].key) {
                (*comp)++;
                (*att)++;
                pA->item[j] = pA->item[j - intervalo];
                j -= intervalo;
            }
            if (j >= intervalo)
                (*comp)++;
            (*att)++;
            pA->item[j] = aux;
        }
    }
}