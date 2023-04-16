#ifndef MAIOR_PALINDROMO_FOCA_BRUTA_H
#define MAIOR_PALINDROMO_FOCA_BRUTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palindromo(char *str);

char* maior_palindromo(char *str, char *palin, int i, int fim, int *max);

int verifica_palindromo(char *str, int i, int fim);

#endif