#include "casamento_padroes.h"

void forca_bruta(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            comparacoes++;
            if (texto[i + j] != padrao[j]) {
                break;
            }
        }
        if (j == m) {
            printf("\nPadrão encontrado na posição %d", i);
        }
    }
    printf("\nComparações: %lld\n", comparacoes);
}