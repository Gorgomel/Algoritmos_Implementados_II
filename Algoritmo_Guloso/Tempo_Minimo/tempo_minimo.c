#include "tempo_minimo.h"

void caminho_pokemon(const int *pokemons, const int *pokebolas, size_t n){
    int tempo = 0, min;

    for(size_t i = 0 ; i < n ; i++){
        min = abs(pokebolas[i] - pokemons[i]);

        tempo = min > tempo ? min : tempo;
    }

    printf("%d", tempo);
}

int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

#include "tempo_minimo.h"

int main(void){
    int n, *pokemons, *pokebolas;

    scanf("%d", &n);
    
    pokemons = malloc(sizeof(int)* n);
    pokebolas = malloc(sizeof(int)* n);

    for(int i = 0 ; i < n ; i++)
        scanf("%d", &pokemons[i]);

    for(int i = 0 ; i < n ; i++)
        scanf("%d", &pokebolas[i]);
    
    qsort(pokemons, n, sizeof(int), cmpfunc);
    qsort(pokebolas, n, sizeof(int), cmpfunc);

    caminho_pokemon(pokemons, pokebolas, n);
    
    free(pokemons);
    free(pokebolas);

}