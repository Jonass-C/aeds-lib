#include "../pesquisa.h"

int main() {
    Tabela t;
    inicializa(&t);

    printf("=== Testando inserção ===\n");
    insere(10, &t);
    insere(5, &t);
    insere(20, &t);
    insere(15, &t);
    insere(5, &t); // repetido

    printf("Tabela atual: ");
    for (int i = 1; i <= t.numElementos; i++) {
        printf("%ld ", t.Item[i]);
    }
    printf("\n");

    printf("\n=== Testando pesquisa binária ===\n");
    printf("Pesquisando 15: %d\n", pesquisaBin(&t, 15));
    printf("Pesquisando 7: %d\n", pesquisaBin(&t, 7));

    printf("\n=== Testando remoção ===\n");
    retira(10, &t);
    retira(99, &t);

    printf("Tabela após remoções: ");
    for (int i = 1; i <= t.numElementos; i++) {
        printf("%ld ", t.Item[i]);
    }
    printf("\n");

    return 0;
}
