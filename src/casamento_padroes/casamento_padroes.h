#ifndef CASAMENTO_PADROES_H
#define CASAMENTO_PADROES_H
#include <stdio.h>
#include <string.h>

void forca_bruta(char *texto, char *padrao);
void rabin_karp(char *texto, char *padrao);
void kmp(char *texto, char *padrao);
void boyer_moore(char *texto, char *padrao);
void boyer_moore_horspool(char *texto, char *padrao);
void boyer_moore_horspool_sunday(char *texto, char *padrao);

#endif // CASAMENTO_PADROES_H