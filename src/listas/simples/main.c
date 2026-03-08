#include "listas.h"

int main() {

    Lista *lista = criar_lista();

    printf("\nInserindo elementos no inicio");
    inserir_elemento_inicio(lista, 10);
    inserir_elemento_inicio(lista, 20);
    inserir_elemento_inicio(lista, 30);
    imprimir_lista(lista);

    printf("\nInserindo elementos no final");
    inserir_elemento_final(lista, 40);
    inserir_elemento_final(lista, 50);
    inserir_elemento_final(lista, 60);
    imprimir_lista(lista);

    printf("\nInserindo elemento na posicao 2");
    inserir_por_posicao(lista, 2, 25);
    imprimir_lista(lista);

    printf("\nRemovendo elemento do inicio");
    remover_elemento_inicio(lista);
    imprimir_lista(lista);

    printf("\nRemovendo elemento do final");
    remover_elemento_final(lista);
    imprimir_lista(lista);

    printf("\nRemovendo elemento na posicao 2");
    remover_por_posicao(lista, 2);
    imprimir_lista(lista);

    printf("\nRemovendo elemento com dado 20");
    remover_por_dado(lista, 20);
    imprimir_lista(lista);

    printf("\nDado do elemento na posicao 1: ");
    int dadoPos = procurar_por_posicao(lista, 1);
    printf("%d\n", dadoPos);

    printf("\nPosicao do elemento com dado 25: ");
    int posDado = procurar_por_dado(lista, 25);
    printf("%d\n", posDado);

    printf("\nVerificando se a lista possui dado 25: ");
    printf(contem_dado(lista, 25) ? "Sim\n" : "Nao\n");

    printf("\nAdicionando outro dado 25");
    inserir_elemento_final(lista, 25);
    imprimir_lista(lista);

    printf("\nOcorrencias do dado 25: %d\n", ocorrencias_dado(lista, 25));

    printf("\nTamanho da lista: %d\n", tamanho_lista(lista));

    printf("\nTrocando os dados dos elementos nas posicoes 1 e 3");
    troca_dados(lista, 1, 3);
    imprimir_lista(lista);

    printf("\nTrocando os elementos nas posicoes 0 e 2");
    troca_elementos(lista, 0, 2);
    imprimir_lista(lista);

    printf("\nTrocando elemento seguinte a posicao 0");
    troca_seguinte(lista, 0);
    imprimir_lista(lista);

    printf("\nOrdenando lista em ordem crescente");
    ordenar_crescente_dados(lista);
    imprimir_lista(lista);

    printf("\nOrdenando lista em ordem decrescente");
    ordenar_decrescente_dados(lista);
    imprimir_lista(lista);

    printf("\nCriando nova lista para mesclar");
    Lista *lista2 = criar_lista();
    inserir_elemento_final(lista2, 100);
    inserir_elemento_final(lista2, 200);
    imprimir_lista(lista2);

    printf("\nMesclando lista original com a nova lista");
    Lista *listaMesclada = mesclar_listas(lista, lista2);
    imprimir_lista(listaMesclada);

    printf("\nApagando lista\n");
    apagar_lista(lista);
    apagar_lista(lista2);
    apagar_lista(listaMesclada);

    return 0;
}