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
    for (int i = 1; i <= t.num_elementos; i++) {
        printf("%ld ", t.Item[i]);
    }
    printf("\n");

    printf("\n=== Testando pesquisa sequencial ===\n");
    printf("Pesquisando 10: %d\n", pesquisa_seq(&t, 10));
    printf("Pesquisando 99: %d\n", pesquisa_seq(&t, 99));

    printf("\n=== Testando remoção ===\n");
    retira(10, &t);
    retira(99, &t);

    printf("Tabela após remoções: ");
    for (int i = 1; i <= t.num_elementos; i++) {
        printf("%ld ", t.Item[i]);
    }
    printf("\n");

    return 0;
}