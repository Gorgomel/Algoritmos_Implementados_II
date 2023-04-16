#include "maior_palindromo_forca_bruta.h"

int verifica_palindromo(char *str, int i, int fim){
    
    for(i = i ; i < fim && (str[i] == str[fim]) ; i++, fim--);
    return (fim - i <= 1) ? 1 : 0;
}

char* maior_palindromo(char *str, char *palin, int i, int fim, int *max){

    if(i >= fim)
        return NULL;

    if(verifica_palindromo(str, i, fim)){
        int tam_max = fim - i + 1;

        if(tam_max > *max){
            *max = tam_max;

            strncpy(palin, str +i, tam_max); 
            palin[tam_max] = '\0';
            return palin;
        }
    }
    
    char *S1 = maior_palindromo(str, palin, i, fim-1, max);
    char *S2 = maior_palindromo(str, palin, i+1, fim, max);
    
    if (S1 != NULL && S2 != NULL)
        return (strlen(S1) > strlen(S2)) ? S1 : S2;
    
    else
        return (S1 != NULL) ? S1 : S2;
}

void palindromo(char *str){
    
    if(str != NULL){
        int max = 0;
        int tam = strlen(str);
        char *palin = malloc((tam +1) *sizeof(char));

        tam -= 1;
        if(tam <= 1)
            if(str[0] == str[tam])
                printf("%s\n", str);
        
        if(verifica_palindromo(str, 0, tam) == 0){
            char *maior = maior_palindromo(str, palin, 0, tam, &max);
            
            if(maior != NULL){
                if(maior[0] == maior[strlen(maior)-1])
                    printf("%s\n", maior);
                
                else
                    printf("%c\n", maior[0]);
            }
        }

        else
            printf("%s\n", str);
    }
}

int main(){
    char *str = malloc(256 *sizeof(char));
    
    scanf("%s", str);
    
    palindromo(str);

    free(str);
    
    return 0;
}