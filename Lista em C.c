// Renan Justino Rezende Silva - 11921BSI223

//OBS: CONSIDEREI COMO BAIXA QUANTIDADE NO ESTOQUE 3 UNIDADES, OU SEJA, SE TIVER 3 DE QUANTIDADE OU MENOS, O CÓDIGO DO PRODUTO SERÁ LISTADO COMO BAIXA QUANTIDADE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hortifruti {
  char nome[20];
  int cod;
  float preco;
  int qtd;
  struct hortifruti *prox;
}hfno;

//=====================================================================================
hfno *insere_lista(hfno *lista,hfno *novo, int aux2, float auxpreco, int auxqtd, char auxnome[20])
{
    novo ->cod = aux2;
    novo ->qtd = auxqtd;
    novo ->preco = auxpreco;
    strcpy(novo->nome, auxnome);
    if(lista==NULL)
       novo->prox = NULL;
    else
       novo->prox=lista;
    lista = novo;
    return lista;
}

//=====================================================================================
float maiorPreco(hfno* p)
{
    float maior = p->preco;
    char nomeMaior[20];
    strcpy(nomeMaior, p->nome);
    while(p != NULL)
    {
        if(p->preco> maior){
            maior = p->preco;
            strcpy(nomeMaior, p->nome);
          }
            p= p->prox; 
      }
    printf("\nAlimento %s possui o maior preco por kg: %.2f\n", nomeMaior, maior);
    return maior;
}
//=====================================================================================

float menorPreco(hfno* lista)
{
  hfno *p;
  p = lista;
    float menor = p->preco;
    char nomeMenor[20];
  strcpy(nomeMenor, p->nome);
    while(p != NULL)
    {
        if(p->preco< menor){
            menor = p->preco;
            strcpy(nomeMenor, p->nome);
          }
            p= p->prox; 
      }
  printf("\nAlimento %s possui o menor preco por kg: %.2f\n", nomeMenor, menor);
    return menor;
}
//=====================================================================================

void lista_todos(hfno *lista)
{
  if(lista==NULL) {
     printf("\nLista Vazia!!!");
     return;
  }
  hfno *p;
  p = lista;
  while(p) {
    
      printf("\n\n Cod: %d",p->cod);
        printf("\n Nome: %s",p->nome);
                printf("\n Preco: %.2f",p->preco);
                        printf("\n Qtd: %d",p->qtd);
      p = p->prox;
  }
  printf("\n");
}

//=====================================================================================

float altera_Preco(hfno* p, int cod, float valor)
{
    while(p != NULL)
    {
        if(p->cod == cod){
            p->preco = valor;
              return 1;
          }
            p= p->prox; 
      }
    return 0;
}

//=====================================================================================
void lista_cod(hfno *lista)
{
  if(lista==NULL) {
     printf("\nLista Vazia!!!");
     return;
  }
  hfno *p;
  p = lista;
  while(p) {
      if(p->qtd<=3){
      printf("\n\n Cod: %d\n",p->cod);
      printf(" Qtd: %d", p->qtd);
        }
      p = p->prox;
  
    }
  printf("\n");
}

//=====================================================================================
int main()
{
    int recebe;
    char ch;
    int cod;
    int qtd;
    int flag=0;
    char nomeaux[20];
    float preco;
    hfno *lista1;

    lista1 = NULL;
    hfno *info;

    do{

        printf("\n1 - Inserir um produto. ");
        printf("\n2 - Mostrar todos produtos.");
        printf("\n3 - Mostrar maior e menor preço por kg.");
        printf("\n4 - Alterar preço em alimentos cadastrados");
        printf("\n5 - Listagem cod dos produtos com baixa quantidade em estoque.");
        printf("\n0 - Sair.");
        printf("\n\n Digite uma opcao: ");
        scanf("%d",&recebe);
        printf("\n\n");
        switch(recebe){
        case 1:
            info=(struct hortifruti *) malloc(sizeof(hfno));
            if(!info){
                printf("\nSem Memoria!!!");
                return 0;}

            printf("\n Digite o cod: ");
            scanf("%d",&cod);
            printf("\n Digite a quantidade em estoque: ");
            scanf("%d",&qtd);
            printf("\n Digite o preco por kg: ");
            scanf("%f",&preco);
            printf("\n Digite o nome: ");
            scanf("%s[^\n]",nomeaux);
            lista1 = insere_lista(lista1,info,cod,preco,qtd,nomeaux);
            break;
        case 2:
            lista_todos(lista1);
            break;
          case 3:
            maiorPreco(lista1);
            menorPreco(lista1);
            break;
                    case 4:
            printf("\nDigite o cod do produto que deseja alterar: ");
            scanf("%d", &cod);
                        printf("\nDigite o novo preco do produto: ");
            scanf("%f", &preco);
            altera_Preco(lista1, cod, preco);
                      if(            altera_Preco(lista1, cod, preco) == 1)
                        printf("\n Preco alterado com sucesso!");
                      else
                        printf("\nPreco não alterado! Digite um cod de produto valido!");
            break;
          case 5:
            lista_cod(lista1);
            break;
         default: recebe = 0;
        }
     printf("\n\n TECLE UMA TECLA .....");
     setbuf(stdin, NULL);
     ch = fgetc(stdin);
     printf("\e[H\e[2J");

    }while(recebe!=0);

    return 0;
}

  