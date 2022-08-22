#include <stdio.h>
#include <stdlib.h>

/*
- Faça uma função que calcula a altura de uma árvore binária.
- Faça uma função para buscar os números impares em uma arvore binária.
- Faça uma função que apague todos os números pares em uma arvore binária.
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
      printf("%d ",a->info);

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

int main()
{
    NoArv * raiz;
    NoArv * raiz2;
    int i,num = 1;

    raiz = abb_cria();
    raiz2 = abb_cria(); 
  
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
        printf("ABB similares");
    else
        printf("ABB nao similares");
      getchar();
    return 0;
}
