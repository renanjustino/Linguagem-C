#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aluno: Renan Justino Rezende Silva

struct servico{
int cod;
char desc[50];
};

int mostra(struct servico *s)
{
    int i;
    for(i=0;i<4;i++){
    printf("\nCod: %d\n", s[i].cod);
    printf("Desc: %s\n", s[i].desc);
}
return 1;
}



struct registro{
int numNotaFiscal;
float valor;
char data[50];
int codServ;
int codCliente;
};

int contaServicoDia(struct registro *r, char data[50]){
int conta=0;
int i;
for(i=0;i<100;i++){
    if(strcmp(r[i].data, data)==0)
    conta++;
}
    return conta;
}

void printaTipoServico(int cod){
    if(cod==1)
printf("\nTipo de servico PINTURA cadastrado! \n");
if(cod==2)
    printf("\nTipo de servico JARDINAGEM cadastrado! \n");
if(cod==3)
    printf("\nTipo de servico FAXINA cadastrado! \n");
if(cod==4)
    printf("\nTipo de servico REFORMA EM GERAL cadastrado! \n");
}

int cadastraServico(struct servico *s, int cod){
if(cod == 1){
s[0].cod = 1;
strcpy(s[0].desc,"pintura");
}
if(cod == 2){
s[1].cod = 2;
strcpy(s[1].desc,"jardinagem");
}
if(cod == 3){
s[2].cod = 3;
strcpy(s[2].desc,"faxina");
}
if(cod == 4){
s[3].cod = 4;
strcpy(s[3].desc,"reforma em geral");
}
return 1;
}

int cadastraRegistro(struct registro *r, int codServ, int numNotaFiscal, float valor, char data[50], int codCliente){
r->codCliente = codCliente;
r->codServ = codServ;
strcpy (r->data,data);
r->valor = valor;
r->numNotaFiscal = numNotaFiscal;
return 1;
}

int mostraServicoDia(struct registro *r, int dia)
{
    int i;
    for(i=0;i<100;i++){
    if(strcmp(r[i].data, dia)==0){
    printf("\nNum da nota: %d\n", r[i].numNotaFiscal);
    printf("Valor: %f\n", r[i].valor);
    printf("Dia: %s\n", r[i].data);
    printf("Cod cliente: %d\n", r[i].codCliente);
    printf("Cod servico: %d\n", r[i].codServ);
    printf("\n");
}
    }
return 1;
}

int mostraServico(struct registro *r){
{
    printf("\nNum da nota: %d\n", r->numNotaFiscal);
    printf("Valor: %f\n", r->valor);
    printf("Dia: %s\n", r->data);
    printf("Cod cliente: %d\n", r->codCliente);
    printf("Cod servico: %d\n", r->codServ);
    printf("\n");
}
return 1;
}

int mostraServicoMinMax(struct registro *r, float min, float max){
    int i;
    for(i=0;i<100;i++){
    if(r[i].valor>=min && r[i].valor <=max){
    printf("\nNum da nota: %d\n", r[i].numNotaFiscal);
    printf("Valor: %f\n", r[i].valor);
    printf("Dia: %s\n", r[i].data);
    printf("Cod cliente: %d\n", r[i].codCliente);
    printf("Cod servico: %d\n", r[i].codServ);
    printf("\n");
    }
    }
    return 1;
}

int main()
{
struct servico s[4];
struct registro r[100];
char dia[50];
char desc[50];
int i=0;
int j=0;
int contador=0;
int exit = 0;
int op;
float min;
float max;
int cod;
   while (!exit) {
      MENU:
      printf("\n- Menu Servicos -\n"
         "1:Cadastrar tipos de servicos\n"
         "2:Cadastrar servicos prestados\n"
         "3:Mostrar os servicos prestados em determinado dia.\n"
         "4:Mostrar os servicos prestados dentro de um intervalo de valor. \n"
         "5:Sair\n -> ");

      scanf("%d", &op);

      switch (op) {

      case 1:
        printf("\nDigite 1 para pintura, 2 para jardinagem, 3 para faxina ou 4 para reforma em geral\n");
        printf("-> ");
        scanf("%d", &cod);
        if(cod>4 || cod<=0){
        printf("\nValor inválido!");
        printf("Digite 1 para pintura, 2 para jardinagem, 3 para faxina ou 4 para reforma em geral\n");
        printf(" -> ");
        scanf("%d", &cod);
        }
        cadastraServico(s,cod);
        printaTipoServico(cod);
         break;
      case 2:
        printf("\nDigite o codigo do servico: ");
        scanf("%d", &r[j].codServ);
        for(i=0;i<4;i++)
        if(s[i].cod == r[j].codServ){
        printf("Digite o num da nota fiscal: ");
        scanf("%d", &r[j].numNotaFiscal);
        printf("Digite o valor: ");
        scanf("%f", &r[j].valor);
        printf("Digite o dia, obs(somente o dia ex: 10, 11, 12, etc): ");
        scanf("%s[^\n]",r[j].data);
        if (contaServicoDia(r,r[j].data)>3){
                printf("\nLimite de 3 servicos atingidos! Digite outro dia!\n");
          scanf("%s[^\n]",r[j].data);
        }
        printf("Digite o codigo do cliente: ");
        scanf("%d", &r[j].codCliente);
        cadastraRegistro(&r[j],r[j].codServ,r[j].numNotaFiscal,r[j].valor,r[j].data,r[j].codCliente);
        printf("Servico prestado cadastrado!\n");
        j++;
        goto MENU;
        }
        printf("\nTIPO DE SERVICO NAO CADASTRADO! CADASTRE o TIPO DE SERVICO ANTES NA OPCAO 1 do MENU INICIAL!\n");

         break;
      case 3:
        printf("\nDigite o dia, obs(somente o dia ex: 10, 11, 12, etc): ");
        scanf("%s[^\n]",dia);
        mostraServicoDia(r,dia);
        printf("\nTem %d servicos cadastrados neste dia!\n ", contaServicoDia(r,dia));
         break;
      case 4:
        printf("\nDigite o valor minimo: ");
        scanf("%f", &min);
        printf("Digite o valor maximo: ");
        scanf("%f", &max);
        mostraServicoMinMax(r, min, max);
         break;

      case 5:
         exit = 1;

         break;
      default:
         printf("\nOpcao invalida.\n");
      }
   }
return 0;
}
