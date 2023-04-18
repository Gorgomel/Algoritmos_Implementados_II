#include "somatoria_em_arranjo.h"

int somatorio(int *vet, int inicio, int fim){

    int a = 0, b = 0, meio;
    
    if(((fim - inicio) <= 1)){
        if(inicio != fim){
            printf("%d %d\n", vet[inicio], vet[fim]);
            return (vet[inicio] + vet[fim]);
        }
        
        else
            return (vet[inicio]);
    }

    else{
        for(int i = inicio ; i <= fim ; i++)
            printf("%d ", vet[i]);
        
        printf("\n");

        meio = ((inicio+fim)/2);
        a += somatorio(vet, inicio, meio);
        b += somatorio(vet, meio + 1, fim);
        
        return (a + b);
    }
}

int main() {
    int tam;
    
    scanf("%d", &tam);

    int vet[tam];

    for(int i = 0 ; i < tam ; i++)
        scanf("%d", &vet[i]);

    printf("soma: %d", somatorio(vet, 0, tam-1));
    
    return 0;
}