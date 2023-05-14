#include "soma_nos_nos.h"

struct Node{
	int item; // chave
	struct Node *left; // referência para a sub-árvore esquerda
	struct Node *right; // referência para a sub-árvore direita
};

// criar nó
Node* criar(int item){
	Node * tree = (Node *) malloc(sizeof(Node));
	
	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;
		
	return tree;
}

// inserir um novo elemento na árvore
Node* inserir(int item, Node* tree){
	// se o nó é nulo, basta criar um novo
	if (tree == NULL)
		tree = criar(item);
	// Se o valor do nó for maior que o do item a ser inserido,
	// uma chamada recursiva para a sub-árvore esquerda é
	// chamada
	else if (item < tree->item)
		tree->left = inserir(item, tree->left);
	// Se o valor do nó for menor que o do item a ser inserido,
	// uma chamada recursiva para a sub-árvore direita é
	// chamada
	else if (item > tree->item)
		tree->right = inserir(item, tree->right);
		
	return tree;
}

// Desalocar todos os nós da árvore
void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

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