#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_palindromo(char *str, int inicio, int fim){
    for (int i = inicio; i < fim ; i++, fim--) 
        if (str[i] != str[fim]) 
            return 0;
        
    return 1;
}

char* copia_string(char *str, int inicio, int fim){
    int j = 0;
    
    if((inicio <= fim) && (fim < strlen(str))){
        char *nstr = malloc(sizeof(char)*(fim - inicio + 2));
        
        for(int i = inicio ; i <= fim ; i++, j++)
            nstr[j] = str[i];
        
        return nstr;
    }
    return NULL;
}

char* maior_palin_bkt(char *str, char *maior, int tam, int inicio, int fim){
    if(inicio >= tam)
        return maior;
        
    else if(fim <= inicio)
        return maior; 
    
    else{
        int k;
        char *aux;
        
        for(k = fim ; k >= inicio ; k--)
            if(verifica_palindromo(str, inicio, k)){
                aux = copia_string(str, inicio, k);
                
                if(strlen(aux) > strlen(maior))
                    strcpy(maior, aux);
            }
        
        char *m1 = maior_palin_bkt(str, maior, tam, inicio + 1, fim);
        char *m2 = maior_palin_bkt(str, maior, tam, inicio, fim - 1);
        
        return (m1 > m2) ? m1 : m2;
    }
}

int main (){
    char *str = malloc(sizeof(char));
    char *maior = malloc(sizeof(char));
    
    scanf("%s", str);
    
    int tam = strlen(str);
    
    printf("%s", maior_palin_bkt(str, maior, tam, 0, tam - 1));
    
    free(str);
    free(maior);
    
    return 0;
}
