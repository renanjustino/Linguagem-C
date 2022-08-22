#include "ex02.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct banco {
    char nome[30];
    float saldo;
    int numConta;
};

banco *cria_conta(char *nome, float saldo, int numConta){
    banco *b;
    b = malloc(1*sizeof(banco));
    strcpy(b->nome,nome);
    b->saldo = saldo;
    b->numConta = numConta;
    return b;
};

int get_conta_info(banco *b, char *nome, float *saldo, int *numConta){
    *saldo = b->saldo;
    strcpy(nome,b->nome);
    *numConta = b->numConta;
    return 0;
}

int destroi_conta(banco *b){
    if (b==NULL)
      return -1;
    else {
      free(b);
      return 0;
    }
}

void imprime_conta(banco *b){
    printf("\nNome: %s\nNumero da Conta: %d\nSaldo: %.2f", b->nome,b->numConta,b->saldo);
}

float altera_saldo(banco *banco, float valor){
    banco->saldo = banco->saldo + valor;
    return 0;
}


