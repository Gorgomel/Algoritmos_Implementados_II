#ifndef MAIOR_PALINDROMO_BKT_H
#define MAIOR_PALINDROMO_BKT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_palindromo(const char *str, size_t inicio, size_t fim);

void aux_maior_palin_bkt(const char *str, char *maior, size_t *tam_maior, size_t inicio, size_t fim);

void maior_palin_bkt(char *str);

#endif