#include <stdio.h>
#include "filas.h"

int main() {

    Fila *fila = criarFila();

    printf("\nInserindo elementos na fila");
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    imprimirFila(fila);

    printf("\nConsultando o primeiro da fila: %d\n", consultarValor(fila));

    printf("\nTamanho da fila: %d\n", tamanhoFila(fila));

    printf("\nRemovendo elemento da fila");
    desenfileirar(fila);
    imprimirFila(fila);

    printf("\nConsultando novo primeiro da fila: %d\n", consultarValor(fila));

    printf("\nTamanho da fila: %d\n", tamanhoFila(fila));

    printf("\nApagando a fila\n");
    apagarFila(fila);

    return 0;
}