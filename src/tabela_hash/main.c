#include "tabela_hash.h"

int main() {
    tabela_hash th;
    inicializar(&th);

    inserir(&th, 10);
    inserir(&th, 24);
    inserir(&th, 17);
    inserir(&th, 12);
    inserir(&th, 22);
    inserir(&th, 32);
    inserir(&th, 5);
    inserir(&th, 15);
    inserir(&th, 28);
    inserir(&th, 42);
    inserir(&th, 48);
    inserir(&th, 48);

    mostrar(&th);

    encontrar_chave(&th, 17);
    encontrar_chave(&th, 49);

    liberar_tabela(&th);
}