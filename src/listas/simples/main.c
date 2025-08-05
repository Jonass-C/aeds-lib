#include <stdio.h>
#include "listas.h"

int main() {

    Lista *lista = criarLista();

    printf("\nInserindo elementos no inicio");
    inserirElementoInicio(lista, 10);
    inserirElementoInicio(lista, 20);
    inserirElementoInicio(lista, 30);
    imprimirLista(lista);

    printf("\nInserindo elementos no final");
    inserirElementoFinal(lista, 40);
    inserirElementoFinal(lista, 50);
    inserirElementoFinal(lista, 60);
    imprimirLista(lista);

    printf("\nInserindo elemento na posicao 2");
    inserirPorPosicao(lista, 2, 25);
    imprimirLista(lista);

    printf("\nRemovendo elemento do inicio");
    removerElementoInicio(lista);
    imprimirLista(lista);

    printf("\nRemovendo elemento do final");
    removerElementoFinal(lista);
    imprimirLista(lista);

    printf("\nRemovendo elemento na posicao 2");
    removerPorPosicao(lista, 2);
    imprimirLista(lista);

    printf("\nRemovendo elemento com dado 20");
    removerPorDado(lista, 20);
    imprimirLista(lista);

    printf("\nDado do elemento na posicao 1: ");
    int dadoPos = procurarPorPosicao(lista, 1);
    printf("%d\n", dadoPos);

    printf("\nPosicao do elemento com dado 25: ");
    int posDado = procurarPorDado(lista, 25);
    printf("%d\n", posDado);

    printf("\nVerificando se a lista possui dado 25: ");
    printf(contemDado(lista, 25) ? "Sim\n" : "Nao\n");

    printf("\nAdicionando outro dado 25");
    inserirElementoFinal(lista, 25);
    imprimirLista(lista);

    printf("\nOcorrencias do dado 25: %d\n", ocorrenciasDado(lista, 25));

    printf("\nTamanho da lista: %d\n", tamanhoLista(lista));

    printf("\nTrocando os dados dos elementos nas posicoes 1 e 3");
    trocaDados(lista, 1, 3);
    imprimirLista(lista);

    printf("\nTrocando os elementos nas posicoes 0 e 2");
    trocaElementos(lista, 0, 2);
    imprimirLista(lista);

    printf("\nTrocando elemento seguinte a posicao 0");
    trocaSeguinte(lista, 0);
    imprimirLista(lista);

    printf("\nOrdenando lista em ordem crescente");
    ordenarCrescenteDados(lista);
    imprimirLista(lista);

    printf("\nOrdenando lista em ordem decrescente");
    ordenarDecrescenteDados(lista);
    imprimirLista(lista);

    printf("\nCriando nova lista para mesclar");
    Lista *lista2 = criarLista();
    inserirElementoFinal(lista2, 100);
    inserirElementoFinal(lista2, 200);
    imprimirLista(lista2);

    printf("\nMesclando lista original com a nova lista");
    Lista *listaMesclada = mesclarListas(lista, lista2);
    imprimirLista(listaMesclada);

    printf("\nApagando lista\n");
    apagarLista(lista);
    apagarLista(lista2);
    apagarLista(listaMesclada);

    return 0;
}