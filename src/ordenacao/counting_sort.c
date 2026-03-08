#include "sort.h"

void counting_sort(array_t* pA, long* att, long* comp) {
    int max = pA->item[0].key;
    for (int i = 1; i < pA->n; i++) {
        (*comp)++;
        if (pA->item[i].key > max)
            max = pA->item[i].key;
    }
    int* count = (int*) calloc(max + 1, sizeof(int));
    item_t* aux = (item_t*) malloc(pA->n * sizeof(item_t));
    for (int i = 0; i < pA->n; i++) {
        count[pA->item[i].key]++;
        (*att)++;
    }
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = pA->n - 1; i >= 0; i--) {
        aux[count[pA->item[i].key] - 1] = pA->item[i];
        count[pA->item[i].key]--;
        (*att)++;
    }
    for (int i = 0; i < pA->n; i++) {
        pA->item[i] = aux[i];
        (*att)++;
    }
    free(count);
    free(aux);
}