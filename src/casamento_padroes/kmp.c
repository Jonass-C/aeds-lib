#include "casamento_padroes.h"

void array_lps (char *padrao, int *lps) {
    int m = strlen(padrao);

    if (m == 0) {
        return;
    }

    lps[0] = 0;
    int j = 0;
    int i = 1;

    while (i < m) {
        if (padrao[i] == padrao[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp (char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }

    int lps[m];
    array_lps(padrao, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        comparacoes++;
        if (padrao[j] == texto[i]) {
            i++;
            j++;

            if (j == m) {
                printf("\nPadrão encontrado na posição: %d", i - j);
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    printf("\nComparações: %lld\n", comparacoes);
}