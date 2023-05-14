#ifndef CONTAR_NOS_VERMELHOS_H
#define CONTAR_NOS_VERMELHOS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeVP NodeVP;

NodeVP* criar_AVP(int key);

NodeVP* pesquisar(NodeVP *tree, int key);

NodeVP* inserir(NodeVP *tree, int key);

int quant_ver(NodeVP *tree);

#endif