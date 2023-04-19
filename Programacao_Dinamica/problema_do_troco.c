#include <stdio.h>
#include <stdlib.h>

int troco_moedas(int *moedas, int troco, int n){

    int mat[troco + 1][n + 1];
    int i, j, x, y;

    for(i = 0 ; i <= n ; i++)
        mat[0][i] = moedas[0];

    for(i = 1 ; i <= troco ; i++){
        for(j = 0 ; j < n ; j++){
            x = ((i - moedas[j]) >= 0) ? mat[i - moedas[j]][j] : 0;
            y = (j >= 1) ? mat[i][j - 1] : 0;
            mat[i][j] = x + y;
        }
    }

    return mat[troco][n - 1];
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
