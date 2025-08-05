#include <stdio.h>
#include "pilhas.h"

int main() {

    Pilha *pilha = criarPilha();

    printf("\nInserindo elementos na pilha");
    empilha(pilha, 10);
    empilha(pilha, 20);
    empilha(pilha, 30);
    empilha(pilha, 40);
    empilha(pilha, 50);
    imprimirPilha(pilha);

    printf("\nConsultando o topo da pilha: %d", consultarValor(pilha));

    printf("\nTamanho da pilha: %d\n", tamanhoPilha(pilha));

    printf("\nRemovendo elemento do topo");
    desempilha(pilha);
    imprimirPilha(pilha);

    printf("\nRemovendo o valor 30 da pilha");
    removerItem(pilha, 30);
    imprimirPilha(pilha);

    printf("\nOrdenando a pilha");
    ordenarPilha(pilha);
    imprimirPilha(pilha);

    printf("\nInvertendo a pilha");
    inverterPilha(pilha);
    imprimirPilha(pilha);

    printf("\nConsultando novo topo da pilha: %d", consultarValor(pilha));

    printf("\nTamanho da pilha: %d\n", tamanhoPilha(pilha));

    printf("\nApagando a pilha\n");
    apagarPilha(pilha);

    return 0;
}