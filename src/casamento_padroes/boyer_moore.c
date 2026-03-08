#include "casamento_padroes.h"

#define MAX_CHARS 256
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

void tabela_bom_sufixo(char *padrao, int m, int good_suffix[]) {
    int i, j;
    int border[m + 1];

    for (i = 0; i <= m; i++) {
        good_suffix[i] = 0;
    }

    i = m;
    j = m + 1;
    border[i] = j;

    while (i > 0) {
        while (j <= m && padrao[i - 1] != padrao[j - 1]) {
            if (good_suffix[j] == 0) {
                good_suffix[j] = j - i;
            }
            j = border[j];
        }
        i--;
        j--;
        border[i] = j;
    }

    j = border[0];

    for (i = 0; i <= m; i++) {
        if (good_suffix[i] == 0) {
            good_suffix[i] = j;
        }
        if (i == j) {
            j = border[j];
        }
    }
}

void boyer_moore(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }

    int bad_char[MAX_CHARS];

    for (int i = 0; i < MAX_CHARS; i++) {
        bad_char[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        bad_char[(unsigned char)padrao[i]] = i;
    }

    int good_suffix[m + 1];
    tabela_bom_sufixo(padrao, m, good_suffix);

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;
        while (j >= 0) {
            comparacoes++;
            if (padrao[j] != texto[shift + j]) {
                break;
            }
            j--;
        }

        if (j< 0) {
            printf("\nPadrão encontrado na posição: %d", shift);
            shift += good_suffix[0];
        } else {
            int bad_shift = j - bad_char[(unsigned char)texto[shift + j]];
            int good_shift = good_suffix[j + 1];
            shift += MAX(1, MAX(bad_shift, good_shift));
        }
    }
    printf("\nComparações: %lld\n", comparacoes);
}