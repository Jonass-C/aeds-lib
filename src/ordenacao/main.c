#include "sort.h"

void imprimir_vetor(array_t* arr) {
    for (int i = 0; i < arr->n; i++) {
        printf("%d ", arr->item[i].key);
    }
    printf("\n");
}

void copiar_vetor(array_t* origem, array_t* destino) {
    destino->n = origem->n;
    for (int i = 0; i < origem->n; i++) {
        destino->item[i].key = origem->item[i].key;
    }
}

void executar_sort(
    char* nome,
    void (*sort)(array_t*, long*, long*),
    array_t* original,
    array_t* teste
){
    long comp = 0;
    long att = 0;

    copiar_vetor(original, teste);

    sort(teste, &att, &comp);

    printf("%-25s", nome);
    imprimir_vetor(teste);
    printf("   Comparacoes: %ld\n", comp);
    printf("   Atribuicoes: %ld\n", att);
    printf("--------------------------------------------------\n");
}

int main() {

    int tamanho = 10;
    int valores_iniciais[] = {42, 15, 8, 99, 23, 4, 15, 8, 73, 0};

    array_t vetor_original;
    array_t vetor_teste;

    vetor_original.n = tamanho;
    vetor_original.item = malloc(tamanho * sizeof(item_t));

    vetor_teste.n = tamanho;
    vetor_teste.item = malloc(tamanho * sizeof(item_t));

    for (int i = 0; i < tamanho; i++)
        vetor_original.item[i].key = valores_iniciais[i];

    printf("\n=== TESTE DOS ALGORITMOS DE ORDENACAO ===\n\n");

    printf("Vetor original: ");
    imprimir_vetor(&vetor_original);

    printf("\n--------------------------------------------------\n");

    executar_sort("Bubble Sort", bubble_sort, &vetor_original, &vetor_teste);
    executar_sort("Bubble Sort Otimizado", bubble_sort_otimizado, &vetor_original, &vetor_teste);

    executar_sort("Selection Sort", select_sort, &vetor_original, &vetor_teste);
    executar_sort("Selection Sort Otimizado", select_sort_otimizado, &vetor_original, &vetor_teste);

    executar_sort("Insertion Sort", insertion_sort, &vetor_original, &vetor_teste);
    executar_sort("Insertion Sort Otimizado", insertion_sort_otimizado, &vetor_original, &vetor_teste);

    executar_sort("Shell Sort", shell_sort, &vetor_original, &vetor_teste);

    executar_sort("Quick Sort", quick_sort, &vetor_original, &vetor_teste);

    executar_sort("Merge Sort", merge_sort, &vetor_original, &vetor_teste);

    executar_sort("Heap Sort", heap_sort, &vetor_original, &vetor_teste);

    executar_sort("Comb Sort", comb_sort, &vetor_original, &vetor_teste);

    executar_sort("Gnome Sort", gnome_sort, &vetor_original, &vetor_teste);

    executar_sort("Counting Sort", counting_sort, &vetor_original, &vetor_teste);

    executar_sort("Bucket Sort", bucket_sort, &vetor_original, &vetor_teste);

    free(vetor_original.item);
    free(vetor_teste.item);

    return 0;
}