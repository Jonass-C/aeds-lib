#include "../pesquisa.h"

void inicializa(Tabela* tabela) {
    tabela->numElementos = 0;
}

int pesquisaSeq(Tabela* tabela, long valor) {
    tabela->Item[0] = valor;
    int i = tabela->numElementos;
    while (tabela->Item[i] != valor){
        i--;
    }
    return i;
}

void insere(long valor, Tabela* tabela) {
    if (tabela->numElementos == MAX)
        printf("Tabela cheia\n");
    else if (pesquisaSeq(tabela, valor))
        printf("Valor já inserido\n");
    else {
        tabela->numElementos++;
        tabela->Item[tabela->numElementos] = valor;
    }
}

void retira(long valor, Tabela* tabela) {
    int i = pesquisaSeq(tabela, valor);
    if (i == 0)
        printf("Valor não está na tabela\n");
    else {
        for (int j = i; j < tabela->numElementos; j++) {
            tabela->Item[j] = tabela->Item[j + 1];
        }
        tabela->numElementos--;
    }
}
