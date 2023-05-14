#ifndef SOMA_NOS_NOS_H
#define SOMA_NOS_NOS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

int soma_nos(Node* tree);

void liberar_arvore(Node* tree);

Node* inserir(int item, Node* tree);

Node* criar(int item);

#endif