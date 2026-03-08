#include "casamento_padroes.h"

#define BASE 256
#define MOD 101

void rabin_karp(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }

    int hash_texto = 0;
    int hash_padrao = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }
    for (int i = 0; i < m; i++) {
        hash_padrao = (BASE * hash_padrao + padrao[i]) % MOD;
        hash_texto = (BASE * hash_texto + texto[i]) % MOD;
    }
    for (int i = 0; i <= n - m; i++) {
        if (hash_padrao == hash_texto) {
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
        if (i < n - m) {
            hash_texto = (BASE * (hash_texto - texto[i] * h) + texto[i + m]) % MOD;

            if (hash_texto < 0) {
                hash_texto += MOD;
            }
        }
    }
    printf("\nComparações: %lld\n", comparacoes);
}