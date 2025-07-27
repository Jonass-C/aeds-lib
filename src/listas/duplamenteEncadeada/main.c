#include <stdio.h>
#include "listasduplas.h"

int main() {

    Lista *lista = criarLista();

    printf("\nInserindo elementos no inicio");
    inserirNoInicio(lista, 10);
    inserirNoInicio(lista, 20);
    inserirNoInicio(lista, 30);
    imprimirLista(lista);

    printf("\nInserindo elementos no fim");
    inserirNoFim(lista, 40);
    inserirNoFim(lista, 50);
    imprimirLista(lista);

    printf("\nInserindo elemento na posicao 2");
    inserirPorPosicao(lista, 2, 25);
    imprimirLista(lista);

    printf("\nRemovendo elemento na posicao 3");
    removerPorPosicao(lista, 3);
    imprimirLista(lista);

    printf("\nTrocando elementos nas posicoes 1 e 3");
    trocarElementos(lista, 1, 3);
    imprimirLista(lista);

    printf("\nTamanho atual da lista: %d\n", lista->tamanho);

    printf("\nOrdenando lista em ordem crescente");
    ordenarCrescenteDados(lista);
    imprimirLista(lista);

    printf("\nOrdenando lista em ordem decrescente");
    ordenarDecrescenteDados(lista);
    imprimirLista(lista);

    printf("\nApagando lista\n");
    apagarLista(lista);

    return 0;
}