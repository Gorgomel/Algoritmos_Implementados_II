#ifndef TEMPO_MINIMO_H
#define TEMPO_MINIMO_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//Encontra o menor caminho entre uma lista de objetos
void caminho_pokemon(const int *pokemons, const int *pokebolas, size_t n);

//Função necessaria para ordenação através da qsort()
int cmpfunc(const void *a, const void *b);

#endif