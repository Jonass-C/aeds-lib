#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int key;
} item_t;

typedef struct{
    item_t* item;
    int n;
} array_t;

void bubble_sort(array_t*,long*,long*);
void bubble_sort_otimizado(array_t* pA, long* att, long* comp);
void select_sort(array_t*,long*,long*);
void select_sort_otimizado(array_t* pA,long* att,long* comp);
void insertion_sort(array_t*,long*,long*);
void insertion_sort_otimizado(array_t* pA, long* att, long* comp);
void shell_sort(array_t*,long*,long*);

void quick_sort(array_t*,long*,long*);
void ordena(array_t* pA, int esq, int dir, long* att, long* comp);
void particao(array_t* pA, int esq, int dir, int* i, int* j, long* att, long* comp);

void heap_sort(array_t*,long*,long*);
void constroi(array_t* pA, int n, long* att, long* comp);
void refaz(array_t* pA, int esq, int dir, long* att, long* comp);

void merge_sort(array_t*,long*,long*);
void ordena_merge(array_t* pA, int ini, int fim, long* att, long* comp);
void intercala(array_t* pA, int ini, int meio, int fim, long* att, long* comp);

void comb_sort(array_t*, long*, long*);
void counting_sort(array_t*, long*, long*);
void gnome_sort(array_t*, long*, long*);
void bucket_sort(array_t* pA, long* att, long* comp);

#endif //SORT_H