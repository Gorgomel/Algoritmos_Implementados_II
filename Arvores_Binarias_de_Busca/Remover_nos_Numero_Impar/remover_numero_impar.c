#include "remover_numero_impar.h"
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

Node* removerV2(int item, Node** tree){
    Node *aux, *auxP, *auxF;

    if ((tree != NULL) && (*tree != NULL)){
        if (item < (*tree)->item)
            (*tree)->left = removerV2(item, &((*tree)->left));
        
        else if (item > (*tree)->item)
            (*tree)->right = removerV2(item, &((*tree)->right));

        else{
            aux = *tree;

            if (aux->left == NULL)
                *tree = aux->right;
            
            else if (aux->right == NULL)
                *tree = aux->left;
            
            else{
                auxP = aux->right;
                auxF = auxP;

                while (auxF->left != NULL){
                    auxP = auxF;
                    auxF = auxF->left;
                }

                if (auxP != auxF){
                    auxP->left = auxF->right;
                    auxF->right = aux->right;
                }

                auxF->left = aux->left;

                *tree = auxF;
            }

            free(aux);
        }
    }

    return *tree;
}

// Desalocar todos os nós da árvore
void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

void imprimirPrefix(Node* tree){
	if (tree != NULL){
		printf("\n%i", tree->item);
		imprimirPrefix(tree->left);
		imprimirPrefix(tree->right);
	}
}

Node* remover_impares(Node **tree){
     if(*tree != NULL){
         remover_impares(&((*tree)->left));
         remover_impares(&((*tree)->right));
         
         if(((*tree)->item % 2) != 0)
             *tree = removerV2((*tree)->item, tree);
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