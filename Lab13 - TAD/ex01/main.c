#include <stdio.h>
#include "banco.h"

int main()
{
    banco b[2];
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("\nInforme o nome, o num da conta e o saldo da conta bancaria %d:\n",i+1);
        scanf("%s", b[i].nome);
        scanf("%d", &b[i].numConta);
        scanf("%f", &b[i].saldo);
    }

   printf("\nAlterando o saldo adicionando um novo valor da conta 1 e 2\n");
   altera_saldo(&b[0],500);
   altera_saldo(&b[1],200);

   printf("\Alterando novamente saldo da conta 2");
   if (altera_saldo(&b[1],300)==0)
     printf("\n\nSucesso: Preco alterado com sucesso\n");
   else printf("\n\n Erro: Preco nao alterado");

   printf("\nContas Cadastrados:\n");
   for (i = 0; i < 2; i++){
     printf("\nNome: %s\nSaldo: %.2f\nNumero da Conta: %d", b[i].nome,b[i].saldo,b[i].numConta);
   }

}
