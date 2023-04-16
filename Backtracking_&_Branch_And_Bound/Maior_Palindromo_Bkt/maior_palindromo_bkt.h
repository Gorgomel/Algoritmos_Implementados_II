#ifndef MAIOR_PALINDROMO_BKT_H
#define MAIOR_PALINDROMO_BKT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_palindromo(const char *str, size_t inicio, size_t fim);

char* copia_string(const char *str, size_t inicio, size_t fim);

char* maior_palin_bkt(const char *str, char *maior, size_t tam, size_t inicio, size_t fim);

#endif