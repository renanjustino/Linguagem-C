#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex02.h"

int main()
{
  char nome[100];
  float saldo_ant, saldo_at;
  int numConta;
  printf("\nInforme o nome, o numero da conta e o saldo: \n");
  scanf("%s", nome);
  scanf("%d", &numConta);
  scanf("%f", &saldo_ant);
  banco *b;
  b = cria_conta(nome,saldo_ant,numConta);
  altera_saldo(b, 100);
  get_conta_info(b,nome, &saldo_at, &numConta);
  imprime_conta(b);
  printf("\n\nSaldo antes: %.2f, Saldo depois: %.2f\n", saldo_ant, saldo_at);
  free(b);
}
