#include <stdio.h>
#include "filas.h"

int main() {

    Fila *fila = criarFila();

    printf("\nInserindo elementos na fila");
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    imprimirFila(fila);

    printf("\nConsultando o primeiro da fila: %d\n", consultarValor(fila));

    printf("\nTamanho da fila: %d\n", tamanhoFila(fila));

    printf("\nRemovendo elemento da fila");
    desenfileirar(fila);
    imprimirFila(fila);

    printf("\nConsultando novo primeiro da fila: %d\n", consultarValor(fila));

    printf("\nTamanho da fila: %d\n", tamanhoFila(fila));

    printf("\nInvertendo a fila");
    inverterFila(fila);
    imprimirFila(fila);

    printf("\nCriando segunda fila para comparar e mesclar");
    Fila *fila2 = criarFila();
    enfileirar(fila2, 50);
    enfileirar(fila2, 60);
    enfileirar(fila2, 70);

    imprimirFila(fila2);

    printf("\nComparando fila original com fila2: %s\n", compararFilas(fila, fila2) ? "Iguais" : "Diferentes");

    printf("\nMesclando as duas filas");
    imprimirFila(mesclarFilas(fila, fila2));

    printf("\nApagando a fila\n");
    apagarFila(fila);
    apagarFila(fila2);

    return 0;
}