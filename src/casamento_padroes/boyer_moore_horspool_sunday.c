#include "casamento_padroes.h"

#define MAX_CHARS 256
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void boyer_moore_horspool_sunday(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }

    int sunday_shift[MAX_CHARS];

    for (int i = 0; i < MAX_CHARS; i++) {
        sunday_shift[i] = m + 1;
    }
    for (int i = 0; i < m; i++) {
        sunday_shift[(unsigned char)padrao[i]] = m - i;
    }

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;
        while (j >= 0) {
            comparacoes++;
            if(padrao[j] != texto[shift + j]) {
                break;
            }
            j--;
        }

        if (j < 0) {
            printf("\nPadrão encontrado na posição: %d", shift);
        }
        if (shift + m >= n) {
            break;
        }
        shift += sunday_shift[(unsigned char)texto[shift + m]];
    }

    printf("\nComparações: %lld\n", comparacoes);
}