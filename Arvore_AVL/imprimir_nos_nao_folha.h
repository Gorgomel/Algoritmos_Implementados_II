#ifndef IMPRIMIR_NOS_NAO_FOLHA_H
#define IMPRIMIR_NOS_NAO_FOLHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node* criar(int item);

void liberar_arvore(Node* tree);

Node* inserir(Node* tree, int value, int *grown);

void imprimir_nao_folha(Node *tree);

#endif