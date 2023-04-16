#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_palindromo(const char *str, size_t inicio, size_t fim){
    int i, j = fim;
    for(i = inicio ; i < j && (str[i] == str[j]) ; i++, j--);
    
    return ((j - i <= 1) && str[inicio] == str[fim]) ? 1 : 0;
}

void aux_maior_palin_bkt(const char *str, char *maior, size_t *tam_maior, size_t inicio, size_t fim){
    if(fim < 0 || *tam_maior >= (fim - inicio + 1))
        return;
    
    if(verifica_palindromo(str, inicio, fim)){
        int tam = fim - inicio + 1;

        if(tam > *tam_maior){
            strncpy(maior, str + inicio, tam);
            maior[tam] = '\0';
            *tam_maior = tam;
        }
    }
 
    aux_maior_palin_bkt(str, maior, tam_maior, inicio + 1, fim);
    aux_maior_palin_bkt(str, maior, tam_maior, inicio, fim - 1);
}

void maior_palin_bkt(char *str){
    size_t tam = strlen(str);
    size_t tam_maior = 0;
    char maior[tam + 1];

    aux_maior_palin_bkt(str, maior, &tam_maior, 0, tam - 1);
    
    if(tam_maior > 1)
        printf("%s", maior);
    
    else
        printf("%c", str[0]);
    
}

int main (){
    char *str = malloc(sizeof(char));

    scanf("%s", str);
    
    maior_palin_bkt(str);
    
    free(str);

    return 0;
}
