#include "maior_palindromo_bkt.h"

int verifica_palindromo(const char *str, size_t inicio, size_t fim){
    int i;
    for(i = inicio ; i <= fim && (str[i] == str[fim]) ; i++, fim--);
    return (fim - i <= 1) ? 1 : 0;
}

char* copia_string(const char *str, size_t inicio, size_t fim){
    int j = 0;
    
    if((inicio <= fim) && (fim < strlen(str))){
        char *nstr = malloc(sizeof(char)*(fim - inicio + 2));
        
        for(int i = inicio ; i <= fim ; i++, j++)
            nstr[j] = str[i];
        
        return nstr;
    }
    return NULL;
}

char* maior_palin_bkt(const char *str, char *maior, size_t tam, size_t inicio, size_t fim){
    if(inicio >= tam)
        return maior;
        
    else if(fim <= inicio)
        return maior; 
    
    else{
        int k;
        char *aux;
        char *maior1 = maior;
        char *maior2 = maior;
        
        for(k = fim ; k >= inicio ; k--){
            if(verifica_palindromo(str, inicio, k)){
                aux = copia_string(str, inicio, k);
                
                if(strlen(aux) > strlen(maior)){
                    strncpy(maior, aux, (k-inicio+1));
                    maior[k-inicio+1] = '\0';
                }
            }
        }
        
        maior1 = maior_palin_bkt(str, maior, tam, inicio + 1, fim);
        maior2 = maior_palin_bkt(str, maior, tam, inicio, fim - 1);
        
        return (strlen(maior1) > strlen(maior2)) ? maior1 : maior2;
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
