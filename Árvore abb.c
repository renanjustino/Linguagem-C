//Renan Justino Rezende Silva - 11921BSI223
/* Programa funcionando corretamente, deixei um exemplo pronto de execucao e também a execucao em tempo real para inserir os nos da arvore. Digitar 0 para de inserir como de costume igual nas aulas.
*/

#include <stdio.h>
#include <stdlib.h>

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
      printf("Esq:%p - No:%p - Dir:%p\n\n", a->esq,a,a->dir);
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

//funcao calculo lca menor ancestral comum de dois nos
NoArv *abb_lca(NoArv* raiz, int n1, int n2)
{
    if (raiz == NULL) return NULL;
 
    if (raiz->info > n1 && raiz->info > n2)
        return abb_lca(raiz->esq, n1, n2);
 

    if (raiz->info < n1 && raiz->info < n2)
        return abb_lca(raiz->dir, n1, n2);
 
    return raiz;
}

int main()
{
    NoArv * raiz;
    NoArv * raizExemplo;
    NoArv *lca;
    NoArv *lcaExemplo;
    int i,num = 1;
    raiz = abb_cria();
    raizExemplo = abb_cria();
    lcaExemplo = abb_cria();
    int no1,no2;
    printf("\nCalculo menor ancestral comum - LCA Exemplo pronto\n");
    printf("\nNumeros inseridos na ordem: 20 8 22 4 12 10 14\n");
    raizExemplo = abb_insere(raizExemplo,20);
    raizExemplo = abb_insere(raizExemplo,8);
    raizExemplo = abb_insere(raizExemplo,22);
    raizExemplo = abb_insere(raizExemplo,4);
    raizExemplo = abb_insere(raizExemplo,12);
    raizExemplo = abb_insere(raizExemplo,10);
    raizExemplo = abb_insere(raizExemplo,14);
    lcaExemplo = abb_lca(raizExemplo,10,14);
    printf("\nArvore PreOrder\n");
    abb_imprime(raizExemplo);
    printf("\nLCA de %d e %d eh %d \n", 10, 14, lcaExemplo->info);
    printf("\nCalculo menor ancestral comum - LCA Tempo Real\n");
    do
    {
     printf("\nDigite o valor do no: ");
     scanf("%d",&num);
     if (num != 0)
        raiz = abb_insere(raiz,num);
    }while (num != 0);
    printf("\nDigite no1 para o calculo do LCA: ");
    scanf("%d", &no1);
    printf("Digite no2 para o calculo do LCA: ");
    scanf("%d", &no2);
    lca = abb_lca(raiz, no1, no2);
    printf("\nArvore PreOrder\n");
    abb_imprime(raiz);
    printf("\nLCA de %d e %d eh %d \n", no1, no2, lca->info);
      getchar();
     
    return 0;
}