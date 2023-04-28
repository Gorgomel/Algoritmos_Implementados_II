#include "remover_numero_impar.h"

struct Node{
    int item; 
    struct Node *left; 
    struct Node *right; 
};

Node* remover_impares(Node **tree){
     if(*tree != NULL){
         remover_impares(&((*tree)->left));
         remover_impares(&((*tree)->right));
         
         if(((*tree)->item % 2) != 0)
             *tree = remover((*tree)->item, tree);
     }
    
    return *tree;
}

int main(){
    int raiz, item;
    
    scanf("%d", &raiz);
    
    scanf("%d", &item);    
    Node *tree = criar(item);
    
    for(int i = 0 ; i < raiz ; i++){
        scanf("%d", &item);
        tree = inserir(item, tree);
    }
    
    remover_impares(&tree);
    
    imprimirPrefix(tree);
    
    liberar_arvore(tree);
    
    return 0;
}