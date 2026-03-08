#include "pilhas.h"

int main() {

    Pilha *pilha = criar_pilha();

    printf("\nInserindo elementos na pilha");
    empilha(pilha, 10);
    empilha(pilha, 20);
    empilha(pilha, 30);
    empilha(pilha, 40);
    empilha(pilha, 50);
    imprimir_pilha(pilha);

    printf("\nConsultando o topo da pilha: %d", consultar_valor(pilha));

    printf("\nTamanho da pilha: %d\n", tamanho_pilha(pilha));

    printf("\nRemovendo elemento do topo");
    desempilha(pilha);
    imprimir_pilha(pilha);

    printf("\nRemovendo o valor 30 da pilha");
    remover_item(pilha, 30);
    imprimir_pilha(pilha);

    printf("\nOrdenando a pilha");
    ordenar_pilha(pilha);
    imprimir_pilha(pilha);

    printf("\nInvertendo a pilha");
    inverter_pilha(pilha);
    imprimir_pilha(pilha);

    printf("\nConsultando novo topo da pilha: %d", consultar_valor(pilha));

    printf("\nTamanho da pilha: %d\n", tamanho_pilha(pilha));

    printf("\nApagando a pilha\n");
    apagar_pilha(pilha);

    return 0;
}