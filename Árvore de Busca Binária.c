#include <stdio.h>
#include <stdlib.h>

/*
Aluno: Renan Justino Rezende Silva
Matricula: 11921BSI223

LEIA: Coloquei dois exemplos prontos de teste e uma execucao em tempo real também.

Exemplo para inserir: vai digitando os nos da arvore e aperta 0 para parar de inserir.

Ex: se apertar 0 duas vezes (nao inserindo na arvore 1 e 2) ou seja fica NULL, retorna ABB similares, pois são vazias.

Codigo funcionando corretamente para todos exemplos.

*/

struct noArv {
   struct noArv* esq;
   int info;
   struct noArv* dir;
};

typedef struct noArv NoArv;

/*============================================================*/
NoArv* abb_cria (void)
{
return NULL;
}

/*============================================================*/
void abb_imprime (NoArv* a)
{
   if (a != NULL) {
      printf("%d \n",a->info);

      abb_imprime(a->esq);

      abb_imprime(a->dir);
   }
}

/*============================================================*/
NoArv* abb_insere (NoArv* a, int v)
{
  if (a==NULL) {
    a =(NoArv*)malloc(sizeof(NoArv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
          a->esq = abb_insere(a->esq,v);
       else if (v > a->info)
               a->dir = abb_insere(a->dir,v);
return a;
}

/*============================================================*/

int abb_compara(struct noArv* a, struct noArv* b)
{

    if (a==NULL && b==NULL)
        return 1;

    if (a!=NULL && b!=NULL)
    {
        return
        (
            abb_compara(a->esq, b->esq) &&
            abb_compara(a->dir, b->dir)
        );
    }

    return 0;
}

void liberaTree(NoArv* node) {
   if (node == NULL) return;
   liberaTree(node->esq);
   liberaTree(node->dir);
   //printf("\n Node deleted, value is %d", node->info);
   free(node);
}

int main()
{
    NoArv * raiz;
    NoArv * raiz2;

    int i,num = 1;
    int cod=0, opt=1;
    raiz = abb_cria();
    raiz2 = abb_cria();

  do {
        printf("\n\n\t=== MENU ===\n");
        printf("\n 1 = Insercao de 2 arvores e resultado se eh ABB similar ou nao");
        printf("\n 2 = Exemplo pronto ABB similar");
        printf("\n 3 = Exemplo pronto ABB nao similar");
        printf("\n 0 = Sair");
        printf("\n\n OPCAO = ");
        scanf("%d",&opt);

    switch (opt) {
  case 0:
      printf("\nFim do programa!\n");
      return 0;
  case 1:
 
    printf("\nDigite o valor para ser inserido ou 0 para terminar de inserir na arvore!\n ");
 
    do
    {
     printf("\n Digite o novo valor arvore 1: ");
     scanf("%d",&num);
     if (num != 0)
        raiz = abb_insere(raiz,num);
    }while (num != 0);

      do
    {
     printf("\n Digite o novo valor arvore 2: ");
     scanf("%d",&num);
     if (num != 0)
        raiz2 = abb_insere(raiz2,num);
    }while (num != 0);

    printf("\nÁrvore 1.\n");
    abb_imprime(raiz);
    printf("\nÁrvore 2.\n");
    abb_imprime(raiz2);
      if(abb_compara(raiz, raiz2))
        printf("\nABB similares!\n");
    else
        printf("\nABB nao similares!\n");
        liberaTree(raiz);
        liberaTree(raiz2);
        raiz = abb_cria();
        raiz2 = abb_cria();
    break;
     
  //exemplo de árvore pronta abb similar.
  //ambas a construcao é igual
      case 2:
  raiz = abb_insere(raiz, 2);
  raiz = abb_insere(raiz, 4);
  raiz = abb_insere(raiz, 3);
  raiz = abb_insere(raiz, 1);

  raiz2= abb_insere(raiz2, 2);
  raiz2= abb_insere(raiz2, 1);
  raiz2= abb_insere(raiz2, 4);
  raiz2 = abb_insere(raiz2, 3);

    printf("\nÁrvore com elementos inseridos na seguinte ordem -> 2431\n");
    abb_imprime(raiz);
    printf("\nÁrvore com elementos inseridos na seguinte ordem -> 2143\n");
    abb_imprime(raiz2);

  if(abb_compara(raiz, raiz2))
        printf("\nABB similares!\n");
    else
        printf("\nABB nao similares!\n");
        liberaTree(raiz);
        liberaTree(raiz2);
        raiz = abb_cria();
        raiz2 = abb_cria();
  break;

      case 3:
  raiz = abb_insere(raiz, 2);
  raiz = abb_insere(raiz, 5);
  raiz = abb_insere(raiz, 1);
  raiz = abb_insere(raiz, 9);

  raiz2 = abb_insere(raiz2, 2);
  raiz2 = abb_insere(raiz2, 1);
  raiz2 = abb_insere(raiz2, 4);
  raiz2 = abb_insere(raiz2, 3);

  printf("\nÁrvore com elementos inseridos na seguinte ordem -> 2519\n");
    abb_imprime(raiz);
    printf("\nÁrvore com elementos inseridos na seguinte ordem -> 2143\n");
    abb_imprime(raiz2);

  if(abb_compara(raiz, raiz2))
        printf("\nABB similares!\n");
    else
        printf("\nABB nao similares!\n");
        liberaTree(raiz);
        liberaTree(raiz2);
        raiz = abb_cria();
        raiz2 = abb_cria();
  break;
      default:
            printf("\nOpcao invalida! Tente novamente!");
        break;
        }
    } while (opt != 0);
      getchar();
    return 0;
}