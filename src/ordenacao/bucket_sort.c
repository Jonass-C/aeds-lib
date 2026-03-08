#include "sort.h"

void bucket_sort(array_t* pA, long* att, long* comp) {
    if (pA->n <= 0) return;
    int n = pA->n;
    int max = pA->item[0].key;
    for (int i = 1; i < n; i++) {
        (*comp)++;
        if (pA->item[i].key > max) {
            max = pA->item[i].key;
            (*att)++;
        }
    }
    int num_buckets = n;
    if (num_buckets > 10000) num_buckets = 10000;

    item_t** buckets = (item_t**) malloc(num_buckets * sizeof(item_t*));
    int* bucket_sizes = (int*) calloc(num_buckets, sizeof(int));
    int* bucket_cap = (int*) malloc(num_buckets * sizeof(int));
    for (int i = 0; i < num_buckets; i++) {
        bucket_cap[i] = 4;
        buckets[i] = (item_t*) malloc(bucket_cap[i] * sizeof(item_t));
        (*att)++;
    }
    for (int i = 0; i < n; i++) {
        long long index = ((long long)pA->item[i].key * num_buckets) / ((long long)max + 1);
        if (index >= num_buckets) index = num_buckets - 1;
        if (bucket_sizes[index] >= bucket_cap[index]) {
            bucket_cap[index] *= 2;
            buckets[index] = (item_t*) realloc(buckets[index], bucket_cap[index] * sizeof(item_t));
        }
        buckets[index][bucket_sizes[index]++] = pA->item[i];
        (*att)++;
    }
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            item_t aux = buckets[i][j];
            (*att)++;
            int k = j - 1;
            while (k >= 0 && aux.key < buckets[i][k].key) {
                (*comp)++;
                (*att)++;
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            if (k >= 0) (*comp)++;
            (*att)++;
            buckets[i][k + 1] = aux;
        }
    }
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            pA->item[index++] = buckets[i][j];
            (*att)++;
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
    free(bucket_cap);
}