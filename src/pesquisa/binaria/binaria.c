#include "../pesquisa.h"

void inicializa(Tabela* tabela) {
    tabela->num_elementos = 0;
}

int pesquisa_bin(Tabela* tabela, long valor) {
    if (tabela->num_elementos == 0)
        return 0;

    int i, esq = 1, dir = tabela->num_elementos;
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
    if (tabela->num_elementos == MAX)
        printf("Tabela cheia\n");
    else if (pesquisa_bin(tabela, valor))
        printf("Valor já inserido\n");
    else {
        int i = tabela->num_elementos;
        while (i > 0 && tabela->Item[i] > valor) {
            tabela->Item[i + 1] = tabela->Item[i];
            i--;
        }
        tabela->Item[i + 1] = valor;
        tabela->num_elementos++;
    }
}

void retira(long valor, Tabela* tabela) {
    int i = pesquisa_bin(tabela, valor);
    if (i == 0)
        printf("Valor não está na tabela\n");
    else {
        for (int j = i; j < tabela->num_elementos; j++) {
            tabela->Item[j] = tabela->Item[j + 1];
        }
        tabela->num_elementos--;
    }

}