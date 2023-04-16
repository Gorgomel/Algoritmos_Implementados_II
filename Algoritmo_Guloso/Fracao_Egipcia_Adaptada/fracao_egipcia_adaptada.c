#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eh_palin(const char *str, int i, int n){
int k = n;
  for(i = i ; (i <= k) && (str[i] == str[k]) ; i++, k--){}

    return (i + k == n) ? 1 : 0;
}

char* nova_string(char *str, int i, int n){
char *s = malloc(sizeof(char) * ((n-i) +1));
 for(i = i ; i <= n ; i++)
    s[i] = str[i];

return s;
}

char* maior_palin(char *str, char *maior, int n, int i){

if(i >= n)
    return maior;

else {
    int j;
    int k = n;
  for(j = i ; (j <= k) ; k--){
if(eh_palin(str, j, k))
    if(((k - j) + 1) > strlen(maior))
        strcpy(maior, nova_string(str, j, k));
}

if(j >= i)
   return maior = maior_palin(str, maior, n, i+j-1);

else 
   maior_palin(str, maior, n, i+j-1);
    
    return NULL;
}

}

int main (){

char *str = malloc(sizeof(char));
char *maior = NULL;

scanf("%s", str);

printf("%s",maior_palin(str, maior, strlen(str), 0));

return 0;
}