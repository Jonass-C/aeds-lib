#include "casamento_padroes.h" // Ajuste o caminho dependendo de onde colocar este main

int main() {

    char texto[] = "GATCGATGGGCCTATATGGATCGGCCGCGTTAGAC";
    char padrao[] = "ATGGAT";

    printf("=== Testando Algoritmos de Casamento de Padroes ===\n");
    printf("Texto: '%s'\n", texto);
    printf("Padrao: '%s'\n\n", padrao);

    printf("--- Forca Bruta ---");
    forca_bruta(texto, padrao);

    printf("\n--- Rabin-Karp ---");
    rabin_karp(texto, padrao);

    printf("\n--- KMP ---");
    kmp(texto, padrao);

    printf("\n--- Boyer-Moore ---");
    boyer_moore(texto, padrao);

    printf("\n--- Boyer-Moore-Horspool ---");
    boyer_moore_horspool(texto, padrao);

    printf("\n--- Boyer-Moore-Horspool-Sunday ---");
    boyer_moore_horspool_sunday(texto, padrao);

    return 0;
}