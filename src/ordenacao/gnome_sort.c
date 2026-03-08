#include "sort.h"

void gnome_sort(array_t* pA, long* att, long* comp) {
    int indice = 0;
    while (indice < pA->n) {
        if (indice == 0) {
            indice++;
        }
        (*comp)++;
        if (pA->item[indice].key >= pA->item[indice - 1].key) {
            indice++;
        } else {
            item_t aux = pA->item[indice];
            pA->item[indice] = pA->item[indice - 1];
            pA->item[indice - 1] = aux;
            (*att)+=3;
            indice--;
        }
    }
}