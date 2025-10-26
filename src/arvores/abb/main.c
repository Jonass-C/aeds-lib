#include "abb.h"

int main() {
    No* arvore;
    inicializa(&arvore);

    // Inserção de valores
    long valores[] = {50, 30, 70, 20, 40, 60, 80, 90, 100, 35};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("Inserindo valores na ABB:\n");
    for (int i = 0; i < n; i++) {
        if (insere(valores[i], &arvore))
            printf("Inserido: %ld\n", valores[i]);
        else
            printf("Valor duplicado: %ld\n", valores[i]);
    }

    // Impressão em ordem
    printf("\nÁrvore em ordem (central):\n");
    central(arvore);

    // Pesquisa
    long pesquisa_val = 40;
    printf("\nPesquisando %ld: ", pesquisa_val);
    if (pesquisa(arvore, pesquisa_val))
        printf("Encontrado!\n");
    else
        printf("Não encontrado!\n");

    pesquisa_val = 100;
    printf("Pesquisando %ld: ", pesquisa_val);
    if (pesquisa(arvore, pesquisa_val))
        printf("Encontrado!\n");
    else
        printf("Não encontrado!\n");

    // Remoção
    long remover_val = 30;
    printf("\nRemovendo %ld...\n", remover_val);
    if (retira(remover_val, &arvore))
        printf("Removido com sucesso!\n");
    else
        printf("Valor não encontrado!\n");

    printf("\nÁrvore em ordem após remoção:\n");
    central(arvore);

    return 0;
}
