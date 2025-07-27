#include <stdio.h>
#include "pilhas.h"

int main() {

    Pilha *pilha = criarPilha();

    printf("\nInserindo elementos na pilha");
    inserirElemento(pilha, 10);
    inserirElemento(pilha, 20);
    inserirElemento(pilha, 30);
    imprimirPilha(pilha);

    printf("\nConsultando o topo da pilha: ");
    printf("%d\n", consultarValor(pilha));

    printf("\nTamanho da pilha: %d\n", tamanhoPilha(pilha));

    printf("\nRemovendo elemento do topo");
    removerElementos(pilha);
    imprimirPilha(pilha);

    printf("\nConsultando novo topo da pilha: %d\n", consultarValor(pilha));

    printf("\nTamanho da pilha: %d\n", tamanhoPilha(pilha));

    printf("\nApagando a pilha\n");
    apagarPilha(pilha);

    return 0;
}