#ifndef REMOVER_NUMERO_IMPAR_H
#define REMOVER_NUMERO_IMPAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node* criar(int item);

Node* inserir(int item, Node* tree);

Node* removerV2(int item, Node** tree);

void liberar_arvore(Node* tree);

void imprimirPrefix(Node* tree);

Node* remover_impares(Node **tree);

#endif
