#include "filas.h"

int main() {

    Fila *fila = criar_fila();

    printf("\nInserindo elementos na fila");
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    imprimir_fila(fila);

    printf("\nConsultando o primeiro da fila: %d\n", consultar_valor(fila));

    printf("\nTamanho da fila: %d\n", tamanho_fila(fila));

    printf("\nRemovendo elemento da fila");
    desenfileirar(fila);
    imprimir_fila(fila);

    printf("\nConsultando novo primeiro da fila: %d\n", consultar_valor(fila));

    printf("\nTamanho da fila: %d\n", tamanho_fila(fila));

    printf("\nInvertendo a fila");
    inverter_fila(fila);
    imprimir_fila(fila);

    printf("\nCriando segunda fila para comparar e mesclar");
    Fila *fila2 = criar_fila();
    enfileirar(fila2, 50);
    enfileirar(fila2, 60);
    enfileirar(fila2, 70);

    imprimir_fila(fila2);

    printf("\nComparando fila original com fila2: %s\n", comparar_filas(fila, fila2) ? "Iguais" : "Diferentes");

    printf("\nMesclando as duas filas");
    imprimir_fila(mesclar_filas(fila, fila2));

    printf("\nApagando a fila\n");
    apagar_fila(fila);
    apagar_fila(fila2);

    return 0;
}