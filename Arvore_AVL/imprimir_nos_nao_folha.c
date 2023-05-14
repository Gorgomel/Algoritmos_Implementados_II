#include "imprimir_nos_nao_folha.h"

struct Node{
    int item;
    int fb;
    struct Node *left;
    struct Node *right;
};

Node* criar(int item){
    Node * tree = (Node *) malloc(sizeof(Node));

    tree->item = item;
        tree->fb = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

static Node* rotateL(Node *tree){
    Node *auxA = tree->left, *auxB = auxA->right;
    
    if (auxA->fb == +1){
        tree->left = auxA->right;
        auxA->right = tree;
        tree->fb = 0;
        tree = auxA;
    }
    
    else{
        auxA->right = auxB->left;
        auxB->left = auxA;
        tree->left = auxB->right;
        auxB->right = tree;
        
            if (auxB->fb == +1)
                tree->fb = -1;
        else
            tree->fb = 0;

        if (auxB->fb == -1)
            auxA->fb = +1;
        else
            auxA->fb = 0;

        tree = auxB;
    }
    
    return tree;
}

static Node* rotateR(Node *tree){
    Node *auxA = tree->right, *auxB;

    if (auxA->fb == -1){
        tree->right = auxA->left;
        auxA->left = tree;
        tree->fb = 0;
        tree = auxA;
    }
    
    else{
        auxB = auxA->left;
        auxA->left = auxB->right;
        auxB->right = auxA;
        tree->right = auxB->left;
        auxB->left = tree;

        if (auxB->fb == -1)
            tree->fb = +1;
        
        else
            tree->fb = 0;

        if (auxB-> fb == +1)
            auxA->fb = -1;
        
        else
            auxA->fb = 0;

        tree = auxB;
    }
    
    return tree;
}

static Node* rotateLRM(Node *tree, int *reduced){
    Node *auxA, *auxB;

    switch (tree->fb){
        case +1: tree->fb = 0; break;
        case 0: tree->fb = -1; *reduced = 0; break;
        case -1: auxA = tree->right;

            if (auxA->fb <= 0){
                tree->right = auxA->left;
                auxA->left = tree;

                if(auxA->fb == 0){
                    tree->fb = -1;
                    auxA->fb = +1;
                    *reduced = 0;
                }
                
                else
                    tree->fb = auxA->fb = 0;

                tree = auxA;
            }
            
            else{
                auxB = auxA->left;
                auxA->left = auxB->right;
                auxB->right = auxA;
                tree->right = auxB->left;
                auxB->left = tree;

                if (auxB->fb == -1)
                    tree->fb = +1;
                
                else
                    tree->fb = 0;

                if (auxB->fb == +1)
                    auxA->fb = -1;
                
                else
                    auxA->fb = 0;

                tree = auxB;
                auxB->fb = 0;
            }
    }

    return tree;
}

static Node* rotateRRM(Node *tree, int *reduced){
    Node *auxA, *auxB;

    switch (tree->fb){
        case -1: tree->fb = 0; *reduced = 0; break;
        case 0: tree->fb = 1; break;
        case +1:
            auxA = tree->left;

            if (auxA->fb >= 0){
                tree->left = auxA->right;
                auxA->right = tree;

                if(auxA->fb == 0){
                    tree->fb = +1;
                    auxA->fb = -1;
                    *reduced = 0;
                }
                
                else
                    tree->fb = auxA->fb = 0;

                tree = auxA;
            }
            
            else{
                auxB = auxA->right;
                auxA->right = auxB->left;
                auxB->left = auxA;
                tree->left = auxB->right;
                auxB->right = tree;

                if (auxB->fb == +1)
                    tree->fb = -1;
                else
                    tree->fb = 0;

                if (auxB->fb == -1)
                    auxA->fb = +1;
                else
                    auxA->fb = 0;

                tree = auxB;
                auxB->fb = 0;
            }
    }

    return tree;
}

Node* inserir(Node* tree, int value, int *grown){
    if(tree == NULL){
        tree = criar(value);

        *grown = 1;
    }
    
    else if (value < tree->item){
        tree->left = inserir(tree->left, value, grown);

        if (*grown){
            switch (tree->fb){
                case -1: tree->fb = 0; *grown = 0; break;
                case 0: tree->fb = +1; break;
                case +1: tree = rotateL(tree); tree->fb = 0; *grown = 0; break;
                case +2: tree = rotateLRM(tree, grown); tree->fb = 0; *grown = 0; break;
                case -2: tree = rotateRRM(tree, grown); tree->fb = 0; *grown = 0; 
            }
        }
    }
    
    else if (value > tree->item){
        tree->right = inserir(tree->right, value, grown);

        if (*grown){
            switch (tree->fb){
                case +1: tree->fb = 0; *grown = 0; break;
                case 0: tree->fb = -1; break;
                case -1: tree = rotateR(tree); tree->fb = 0; *grown = 0; break;
                case +2: tree = rotateLRM(tree, grown); tree->fb = 0; *grown = 0; break;
                case -2: tree = rotateRRM(tree, grown); tree->fb = 0; *grown = 0; 
                    
            }
        }
    }

    return tree;
}

void imprimir_nao_folha(Node *tree){
    if(tree->left == NULL && tree->right == NULL)
        return;

    else{
        printf("%d ", tree->item);
        
        if(tree->left != NULL)
            imprimir_nao_folha(tree->left);   
        
        if(tree->right != NULL)
            imprimir_nao_folha(tree->right);   
    }
}

int main(){
    Node *tree = NULL;
    int n, item, grown;

    scanf("%d", &n);

    while(n > 0){
        scanf("%d", &item);
        tree = inserir(tree, item, &grown);
        n--;
    }

    imprimir_nao_folha(tree);
    
    liberar_arvore(tree);
    
    return 0;
}