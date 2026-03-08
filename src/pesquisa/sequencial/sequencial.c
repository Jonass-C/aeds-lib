#include "../pesquisa.h"

void inicializa(Tabela* tabela) {
    tabela->num_elementos = 0;
}

int pesquisa_seq(Tabela* tabela, long valor) {
    tabela->Item[0] = valor;
    int i = tabela->num_elementos;
    while (tabela->Item[i] != valor){
        i--;
    }
    return i;
}

void insere(long valor, Tabela* tabela) {
    if (tabela->num_elementos == MAX)
        printf("Tabela cheia\n");
    else if (pesquisa_seq(tabela, valor))
        printf("Valor já inserido\n");
    else {
        tabela->num_elementos++;
        tabela->Item[tabela->num_elementos] = valor;
    }
}

void retira(long valor, Tabela* tabela) {
    int i = pesquisa_seq(tabela, valor);
    if (i == 0)
        printf("Valor não está na tabela\n");
    else {
        for (int j = i; j < tabela->num_elementos; j++) {
            tabela->Item[j] = tabela->Item[j + 1];
        }
        tabela->num_elementos--;
    }
}