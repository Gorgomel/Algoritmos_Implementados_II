#include <stdio.h>
#include <stdlib.h>

/*A função troco_moedas recebe como parâmetros um vetor moedas com o conjunto de moedas, um inteiro n com a quantidade de 
moedas, e um inteiro troco com o valor do troco a ser dado. 
A função retorna um inteiro que representa a quantidade de formas possíveis para devolver o troco utilizando as moedas 
do conjunto.

O algoritmo utiliza uma matriz mat para armazenar a solução parcial do problema. A matriz tem troco + 1 linhas e n + 1 
colunas, onde a linha i representa o valor do troco e a coluna j representa o conjunto de moedas utilizado.

A primeira coluna da matriz é inicializada com zero, pois não é possível dar um troco com valor zero utilizando moedas 
de qualquer conjunto. A primeira linha da matriz é inicializada com um, pois é possível dar um troco com qualquer valor 
utilizando apenas uma moeda de valor igual ao valor do troco.

O preenchimento da matriz é feito utilizando programação dinâmica. Para cada célula (i, j) da matriz, o algoritmo verifica
se a moeda moedas[j - 1] pode ser utilizada para dar um troco de valor i. Se for possível, a solução da subestrutura 
anterior mat[i - moedas[j - 1]][j] é somada à solução da subestrutura anterior mat[i][j - 1].

Ao final do preenchimento da matriz, a solução do problema é dada pela célula mat[troco][n], que representa a quantidade de 
formas possíveis para dar um troco de valor troco utilizando o conjunto de moedas moedas.*/

int troco_moedas(int *moedas, int troco, int n){

    int mat[troco + 1][n + 1];
    int i, j;


    for(i = 0 ; i <= troco ; i++)
        mat[i][0] = 0;

    for(i = 0 ; i <= n ; i++)
        mat[0][i] = 1;

    for(i = 1 ; i <= troco ; i++){
        for(j = 1 ; j <= n ; j++){
            mat[i][j] = mat[i][j - 1];

            if(moedas[j - 1] <= i)
                mat[i][j] += mat[i - moedas[j - 1]][j];
        }
    }

    return mat[troco][n];
}
   

int main(){

    int troco, n;

    scanf("%d %d", &troco, &n);

    int moedas[n];

    for(int i = 0 ; i < n ; i++)
        scanf("%d", &moedas[i]);

    printf("%d", troco_moedas(moedas, troco, n));

    return 0;
}
