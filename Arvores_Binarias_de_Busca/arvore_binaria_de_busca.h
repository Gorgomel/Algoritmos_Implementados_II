#ifndef ARVORE_BINARIA_DE_BUSCA_H
#define ARVORE_BINARIA_DE_BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

Node* criar(int item);

Node* pesquisar(int item, Node* tree);

int min(Node* tree);

int max(Node* tree);

Node* inserir(int item, Node* tree);

int remover(int item, Node* tree);

Node* removerV2(int item, Node** tree);

void imprimirInfix(Node* tree);

void imprimirPrefix(Node* tree);

void imprimirPosfix(Node* tree);

void liberar_arvore(Node* tree);

#endif