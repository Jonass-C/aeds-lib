#include "listas_duplas.h"

int main() {

    Lista *lista = criar_lista();

    printf("\nInserindo elementos no inicio");
    inserir_no_inicio(lista, 10);
    inserir_no_inicio(lista, 20);
    inserir_no_inicio(lista, 30);
    imprimir_lista(lista);

    printf("\nInserindo elementos no fim");
    inserir_no_fim(lista, 40);
    inserir_no_fim(lista, 50);
    imprimir_lista(lista);

    printf("\nInserindo elemento na posicao 2");
    inserir_por_posicao(lista, 2, 25);
    imprimir_lista(lista);

    printf("\nRemovendo elemento na posicao 3");
    remover_por_posicao(lista, 3);
    imprimir_lista(lista);

    printf("\nTrocando elementos nas posicoes 1 e 3");
    trocar_elementos(lista, 1, 3);
    imprimir_lista(lista);

    printf("\nTamanho atual da lista: %d\n", lista->tamanho);

    printf("\nOrdenando lista em ordem crescente");
    ordenar_crescente_dados(lista);
    imprimir_lista(lista);

    printf("\nOrdenando lista em ordem decrescente");
    ordenar_decrescente_dados(lista);
    imprimir_lista(lista);

    printf("\nApagando lista\n");
    apagar_lista(lista);

    return 0;
}