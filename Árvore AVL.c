//Renan Justino Rezende Silva - 11921BSI223

/* Codigo funcionando corretamente, foi demonstrado um exemplo pronto da soma dos nos em niveis impares e outro em tempo real. Na de tempo real, digitar 0 termina a insercao de nos, como de costume das aulas.

ARVORE DO EXEMPLO INSERIDA OS ELEMENTOS NA SEGUINTE ORDEM: 6,4,8,3,9.

ARVORE RESULTANTE DA INSERCAO

              6 - NIVEL 1
           4    8 - NIVEL 2
         3        9 - NIVEL 3

PORTANTO, A SOMA PARA OS NOS EM NIVEIS IMPARES = 6 + 3 + 9 = 18.

OBS: TOMADO O PRIMEIRO NIVEL COMO 1 e assim em diante.
*/

#include <stdio.h>
#include <stdlib.h>


struct noAVL {
  int dado;
int bal;
struct noAVL *esq;
struct noAVL *dir;
};

typedef struct noAVL* AVL;

//===========================================================================

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

AVL* cria_ArvAvl(){
    AVL* raiz = (AVL*) malloc(sizeof(AVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct noAVL* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(AVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO(struct noAVL* no){
    if(no == NULL)
        return -1;
    else
      return no->bal;
}

void RotacaoSimplesADireita(AVL *raiz)
{

struct noAVL *ne = (*raiz)->esq;
(*raiz)->esq = ne->dir;
ne->dir = (*raiz);
(*raiz)->bal = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
    ne->bal = maior(altura_NO(ne->esq),(*raiz)->bal) + 1;
*raiz = ne;
}

void RotacaoSimplesAEsquerda(AVL *raiz)
{

struct noAVL *nd = (*raiz)->dir;
(*raiz)->dir = nd->esq;
nd->esq = (*raiz);
(*raiz)->bal = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
    nd->bal = maior(altura_NO(nd->dir),(*raiz)->bal) + 1;
(*raiz) = nd;
}

void RotacaoLR(AVL *A){//LR

    RotacaoSimplesAEsquerda(&(*A)->esq);
    RotacaoSimplesADireita(A);
}

void RotacaoRL(AVL *A){//RL

    RotacaoSimplesADireita(&(*A)->dir);
    RotacaoSimplesAEsquerda(A);
}

int fatorBalanceamento_NO(struct noAVL* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

/*=======================================================================*/
AVL procuraMenor(struct noAVL* atual){
    struct noAVL *no1 = atual;
    struct noAVL *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(AVL *raiz, int valor){
if(*raiz == NULL){// valor não existe
   printf("valor não existe!!\n");
   return 0;
}

    int res;
if(valor < (*raiz)->dado){
   if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
       if ((*raiz)->esq == NULL)
                (*raiz)->bal = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoSimplesAEsquerda(raiz);
                else
                    RotacaoRL(raiz); //RotacaoDuplaEsquerda
            }
   }
}

if((*raiz)->dado < valor){
   if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
        if ((*raiz)->dir == NULL)
                (*raiz)->bal = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoSimplesADireita(raiz);
                else
                    RotacaoLR(raiz); //RotacaoDuplaDireita
            }
   }
}

if((*raiz)->dado == valor){
   if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nó tem 1 filho ou nenhum
struct noAVL* oldNode = (*raiz);
if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else if((*raiz)->dir!=NULL)
                *raiz = (*raiz)->dir;
            else *raiz = NULL;
free(oldNode);
}else { // nó tem 2 filhos
struct noAVL* temp = procuraMenor((*raiz)->dir);
(*raiz)->dado = temp->dado;
remove_ArvAVL(&(*raiz)->dir, (*raiz)->dado);
            if(fatorBalanceamento_NO(*raiz) >= 2){
if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
RotacaoSimplesADireita(raiz);
else
RotacaoLR(raiz);  //RotacaoDuplaDireita
}
}
if (*raiz != NULL)
            (*raiz)->bal = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
return 1;
}

(*raiz)->bal = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

return res;
}

/*===============================================================================*/
int Inserir(int val, AVL *raiz)
{
       if (*raiz == NULL){
  struct noAVL *novo;
  novo = (AVL) malloc(sizeof(struct noAVL));
  novo->dado = val;
  novo->bal = 0;
  novo->esq = NULL;
  novo->dir = NULL;
  *raiz=novo;
  return 0;
}
         struct noAVL *atual = *raiz;
         if (val < atual->dado){
            if (Inserir(val, &(atual->esq))==0){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if(val < (*raiz)->esq->dado){
                        RotacaoSimplesADireita(raiz);
                    }else{
                        RotacaoLR(raiz);
                    }
                }
             } }

        else if (val > atual->dado){
               if (Inserir(val, &(atual->dir))==0){
                  if(fatorBalanceamento_NO(atual) >= 2){
                    if(val > (*raiz)->dir->dado){
                        RotacaoSimplesAEsquerda(raiz);
                    }else{
                       RotacaoRL(raiz); }
                } //Se do fatordebalanceamento
               }
             }
     atual->bal = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;
     return 0;
}


/*========================================================================*/
void mostraPre(AVL *raiz)
{
  if(raiz==NULL)
   return;
  if (*raiz != NULL){
  (*raiz)->bal = fatorBalanceamento_NO(*raiz);
  printf("valor do no: %d\n",(*raiz)->dado);
  printf("End Esq:%p - End. no:%p - End dir:%p\n\n", (*raiz)->esq,(*raiz),(*raiz)->dir);
  mostraPre(&((*raiz)->esq));
  mostraPre(&((*raiz)->dir));
  }
}

void mostraPos(AVL *raiz)
{
  if(raiz==NULL)
   return;
  if (*raiz != NULL){
  mostraPos(&((*raiz)->esq));
  mostraPos(&((*raiz)->dir));
  printf("valor do no: %d ( Bal: %d )\n",(*raiz)->dado,fatorBalanceamento_NO(*raiz));
  printf("End Esq:%p - End. no:%p - End dir:%p\n\n", (*raiz)->esq,(*raiz),(*raiz)->dir);

  }
}

int altura(AVL *N)
{
    if (*N == NULL)
        return 0;
    return 1+maior(altura(&(*N)->esq), altura(&(*N)->dir));
}

//funcao que soma os nos da arvore AVL
int soma(AVL* raiz)
{
    if (*raiz == NULL)
        return 0;
    return ((*raiz)->dado + soma(&(*raiz)->esq) + soma(&(*raiz)->dir));
}

//funcao que encontra os nos em niveis impares
void NosNivelImpar(AVL* raiz, int levelatual, int level, AVL*raiz2) {
  if(*raiz == NULL) {
      return;  
  }  
  if(levelatual == level) {
     printf(" %d ", (*raiz)->dado);
     Inserir((*raiz)->dado, raiz2);
     return;
  }
  NosNivelImpar(&(*raiz)->esq, levelatual+1, level,raiz2);
  NosNivelImpar(&(*raiz)->dir, levelatual+1, level,raiz2);
}

/*========================================================================*/
int main()
{
  AVL* raiz1;
  AVL* raiz2;
  AVL* raizExemplo;
  AVL* raizExemplo2;
  int base=0;
  int i;
 
  raiz1 = cria_ArvAvl(); //cria_ArvAvl
  raiz2 = cria_ArvAvl(); //cria_ArvAvl
  raizExemplo = cria_ArvAvl(); //cria_ArvAvl
  raizExemplo2 = cria_ArvAvl(); //cria_ArvAvl
 
  Inserir(6,raizExemplo);
  Inserir(4,raizExemplo);
  Inserir(8,raizExemplo);
  Inserir(3,raizExemplo);
  Inserir(9,raizExemplo);

  printf("\nSOMA dos nos em niveis impares - Exemplo pronto\n");
  printf("\nAVL tree - PreOrder\n");
  mostraPre(raizExemplo);
  printf("\nObs: Considerado o primeiro nivel como 1.\nNos altura impares: ");
   for(i=0;i<altura(raizExemplo);i+=2)
  NosNivelImpar(raizExemplo,base,i,raizExemplo2);
  printf("\n");
  printf("\nSOMA=%d\n", soma(raizExemplo2));
  libera_ArvAVL(raizExemplo);
  libera_ArvAVL(raizExemplo2);
 
  printf("\nSOMA dos nos em niveis impares - Tempo Real\n");
int valor=0;
do{
  printf("\nDigite um numero : ");
  scanf("%d",&valor);
  if(valor!=0)
  Inserir(valor,raiz1);
}while(valor!=0);  
  printf("\n");
  printf("\nAltura: %d\n", altura(raiz1));
  printf("\nAVL tree - PreOrder\n");
  mostraPre(raiz1);
  printf("\nObs: Considerado o primeiro nivel como 1.\nNos altura impares: ");
   for(i=0;i<altura(raiz1);i+=2)
  NosNivelImpar(raiz1,base,i,raiz2);
  printf("\n");
  printf("\nSOMA=%d\n", soma(raiz2));
  libera_ArvAVL(raiz1);
  libera_ArvAVL(raiz2);
return 0;
}
/*========================================================================*/
