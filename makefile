# Variáveis para o compilador e as flags
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99
LDFLAGS=

# Diretórios
SRCDIR=./
OBJDIR=./obj
BINDIR=./bin

# Arquivos fonte
FRACAO_EGIPICA=$(SRCDIR)/Algoritmo_Guloso/Fracao_Egipcia_Adaptado/fracao_egipcia_adaptado.c
TEMPO_MINIMO=$(SRCDIR)/Algoritmo_Guloso/Tempo_Minimo/tempo_minimo.c
SOMATORIA_EM_ARRANJO=$(SRCDIR)/Divisao_e_Conquista/somatoria_em_arranjo.c
MAIOR_PALINDROMO_FB=$(SRCDIR)/Forca_Bruta/maior_palindromo_forca_bruta.c
PROBLEMA_DO_TROCO=$(SRCDIR)/Programacao_Dinamica/problema_do_troco.c
REMOVER_NOS_NUMERO_IMPAR=$(SRCDIR)/Arvores_Binarias_de_Busca/Remover_nos_Numero_Impar/remover_numero_impar.c
SOMA_NOS_NOS=$(SRCDIR)/Arvores_Binarias_de_Busca/Soma_nos_Nos/soma_nos_nos.c
IMPRIMIR_NOS_NAO_FOLHA=$(SRCDIR)/Arvore_AVL/imprimir_nos_nao_folha.c
CONTAR_NOS_VERMELHOS=$(SRCDIR)/Arvore_Rubro_Negra/contar_nos_vermelhos.c
#MAIOR_PALINDROMO_BKT=$(SRCDIR)/Backtracking_Branch_And_Bound/maior_palindromo_bkt.c

# Arquivos objeto
FRACAO_EGIPICA_OBJ=$(OBJDIR)/fracao_egipcia_adaptado.o
TEMPO_MINIMO_OBJ=$(OBJDIR)/tempo_minimo.o
SOMATORIA_EM_ARRANJO_OBJ=$(OBJDIR)/somatoria_em_arranjo.o
MAIOR_PALINDROMO_FB_OBJ=$(OBJDIR)/maior_palindromo_forca_bruta.o
PROBLEMA_DO_TROCO_OBJ=$(OBJDIR)/problema_do_troco.o
REMOVER_NOS_NUMERO_IMPAR_OBJ=$(OBJDIR)/remover_numero_impar.o
SOMA_NOS_NOS_OBJ=$(OBJDIR)/soma_nos_nos.o
IMPRIMIR_NOS_NAO_FOLHA_OBJ=$(OBJDIR)/imprimir_nos_nao_folha.o
CONTAR_NOS_VERMELHOS_OBJ=$(OBJDIR)/contar_nos_vermelhos.o
#MAIOR_PALINDROMO_BKT_OBJ=$(OBJDIR)/maior_palindromo_bkt.o

# Nomes dos executáveis
FRACAO_EGIPICA_EXE=$(BINDIR)/fracao_egipcia_adaptado
TEMPO_MINIMO_EXE=$(BINDIR)/tempo_minimo
SOMATORIA_EM_ARRANJO_EXE=$(BINDIR)/somatoria_em_arranjo
MAIOR_PALINDROMO_FB_EXE=$(BINDIR)/maior_palindromo_forca_bruta
PROBLEMA_DO_TROCO_EXE=$(BINDIR)/problema_do_troco
REMOVER_NOS_NUMERO_IMPAR_EXE=$(BINDIR)/remover_numero_impar
SOMA_NOS_NOS_EXE=$(BINDIR)/soma_nos_nos
IMPRIMIR_NOS_NAO_FOLHA_EXE=$(BINDIR)/imprimir_nos_nao_folha
CONTAR_NOS_VERMELHOS_EXE=$(BINDIR)/contar_nos_vermelhos
#MAIOR_PALINDROMO_BKT_EXE=$(BINDIR)/maior_palindromo_bkt

# Regras de compilação
all: $(FRACAO_EGIPICA_EXE) $(TEMPO_MINIMO_EXE) $(SOMATORIA_EM_ARRANJO_EXE) $(MAIOR_PALINDROMO_FB_EXE) $(PROBLEMA_DO_TROCO_EXE) $(REMOVER_NOS_NUMERO_IMPAR_EXE) $(SOMA_NOS_NOS_EXE) $(IMPRIMIR_NOS_NAO_FOLHA_EXE) $(CONTAR_NOS_VERMELHOS_EXE) #$(MAIOR_PALINDROMO_BKT_EXE)

$(FRACAO_EGIPICA_EXE): $(FRACAO_EGIPICA_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TEMPO_MINIMO_EXE): $(TEMPO_MINIMO_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(SOMATORIA_EM_ARRANJO_EXE): $(SOMATORIA_EM_ARRANJO_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(MAIOR_PALINDROMO_FB_EXE): $(MAIOR_PALINDROMO_FB_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(PROBLEMA_DO_TROCO_EXE): $(PROBLEMA_DO_TROCO_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(REMOVER_NOS_NUMERO_IMPAR_EXE): $(REMOVER_NOS_NUMERO_IMPAR_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(SOMA_NOS_NOS_EXE): $(SOMA_NOS_NOS_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(IMPRIMIR_NOS_NAO_FOLHA_EXE): $(IMPRIMIR_NOS_NAO_FOLHA_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(CONTAR_NOS_VERMELHOS_EXE): $(CONTAR_NOS_VERMELHOS_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

#$(MAIOR_PALINDROMO_BKT_EXE): $(MAIOR_PALINDROMO_BKT_OBJ)
#
$(FRACAO_EGIPICA_OBJ): $(FRACAO_EGIPICA)
	$(CC) $(CFLAGS) -c -o $@ $^

$(TEMPO_MINIMO_OBJ): $(TEMPO_MINIMO)
	$(CC) $(CFLAGS) -c -o $@ $^

$(SOMATORIA_EM_ARRANJO_OBJ): $(SOMATORIA_EM_ARRANJO)
	$(CC) $(CFLAGS) -c -o $@ $^

$(MAIOR_PALINDROMO_FB_OBJ): $(MAIOR_PALINDROMO_FB)
	$(CC) $(CFLAGS) -c -o $@ $^

$(PROBLEMA_DO_TROCO_OBJ): $(PROBLEMA_DO_TROCO)
	$(CC) $(CFLAGS) -c -o $@ $^

$(REMOVER_NOS_NUMERO_IMPAR_OBJ): $(REMOVER_NOS_NUMERO_IMPAR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(SOMA_NOS_NOS_OBJ): $(SOMA_NOS_NOS)
	$(CC) $(CFLAGS) -c -o $@ $^

$(IMPRIMIR_NOS_NAO_FOLHA_OBJ): $(IMPRIMIR_NOS_NAO_FOLHA)
	$(CC) $(CFLAGS) -c -o $@ $^

$(CONTAR_NOS_VERMELHOS_OBJ): $(CONTAR_NOS_VERMELHOS)
	$(CC) $(CFLAGS) -c -o $@ $^

#$(MAIOR_PALINDROMO_BKT_OBJ): $(MAIOR_PALINDROMO_BKT)

.PHONY: clean

clean:
	rm ./obj/*.o
	rm ./bin/*
	