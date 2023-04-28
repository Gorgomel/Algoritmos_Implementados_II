#include "soma_nos_nos.h"

struct Node{
    int item; 
    struct Node *left; 
    struct Node *right; 
};

int soma_nos(Node* tree){
    if(tree == NULL)
        return 0;
    
    int somaL = 0, somaR = 0;
        
    if (tree->left == NULL && tree->right == NULL)
        return tree->item; 
        
    else{ 
        somaL += soma_nos(tree->left); 
        somaR += soma_nos(tree->right); 
            
        return somaL + somaR;
    } 
}

int main(){
    int n, item;
    
        scanf("%d %d", &n, &item);
    
        Node *tree = criar(item);
        
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &item);
            tree = inserir(item, tree);
        }

        printf("%d", soma_nos(tree));
    
        liberar_arvore(tree);
    
    return 0;
}