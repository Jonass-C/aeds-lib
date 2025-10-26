#include "../pesquisa.h"

void inicializa(Tabela* tabela) {
    tabela->numElementos = 0;
}

int pesquisaBin(Tabela* tabela, long valor) {
    if (tabela->numElementos == 0)
        return 0;

    int i, esq = 1, dir = tabela->numElementos;
    do {
        i = (esq + dir) / 2;
        if (valor > tabela->Item[i])
            esq = i + 1;
        else
            dir = i - 1;
    } while ( (valor != tabela->Item[i]) && (esq <= dir) );

    if (valor == tabela->Item[i])
        return i;
    else
        return 0;
}

void insere(long valor, Tabela* tabela) {
    if (tabela->numElementos == MAX)
        printf("Tabela cheia\n");
    else if (pesquisaBin(tabela, valor))
        printf("Valor já inserido\n");
    else {
        int i = tabela->numElementos;
        while (i > 0 && tabela->Item[i] > valor) {
            tabela->Item[i + 1] = tabela->Item[i];
            i--;
        }
        tabela->Item[i + 1] = valor;
        tabela->numElementos++;
    }
}

void retira(long valor, Tabela* tabela) {
    int i = pesquisaBin(tabela, valor);
    if (i == 0)
        printf("Valor não está na tabela\n");
    else {
        for (int j = i; j < tabela->numElementos; j++) {
            tabela->Item[j] = tabela->Item[j + 1];
        }
        tabela->numElementos--;
    }

}
