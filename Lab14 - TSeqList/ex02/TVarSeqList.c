#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TVarSeqList.h"

typedef struct lista{
    int qtd;
    struct aluno *dados;
    int tamanhoInicial;
};

Lista *cria_lista(int qtd){
Lista *li;
li = (Lista*) malloc(sizeof(struct lista));
li->dados = malloc(sizeof(struct aluno)*qtd);
if (li != NULL){
    li->qtd = 0;
    li->tamanhoInicial = qtd;
    return li;
}
}

int compactar_lista(Lista *li){
    if (li == NULL)
    return -1;
    int novaQtd = 0;
    novaQtd = ((li->qtd/100)*100) + 100;
    li->dados = realloc(li->dados, novaQtd*sizeof(struct aluno));
    printf("Lista compactada para %d elementos! \n", novaQtd);
    return 0;
}

void libera_lista(Lista* li){
    free(li);
}

int insere_lista_inicio(Lista* li, struct aluno al){
     if(li == NULL)
        return -1;
     if(li->qtd  == MAX)
        return -1;
        int i;
     for(i=li->qtd-1;i>=0; i--)
        li->dados[i+1] = li->dados[i];
        li->dados[0] = al;
        li->qtd++;
        return 0;
        }


int insere_lista_final(Lista *li, struct aluno al){
     if(li == NULL)
        return -1;
     if(li->qtd  == MAX)
        return -1;
    li->dados[li->qtd] = al;
    li->qtd++;
return 0;
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al){
    if(li ==   NULL || pos  <=   0 ||  pos > li->qtd)
        return -1;
    *al= li->dados[pos-1];
    return 0;
}

 int consulta_lista_mat(Lista* li, int mat, struct aluno*al){
    if(li ==   NULL)
        return -1;
    int i = 0  ;
    while(i<li->qtd && li->dados[i].matricula !=  mat) i++;
          if(i== li->qtd)
            return -1;
          *al= li->dados[i];
          return 0;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
          int novaQtd=0;
          if(li ==   NULL)
            return -1;
          if(li->qtd  ==  li->tamanhoInicial){
            novaQtd = ((li->tamanhoInicial/100)*100) + 100;
            li->dados = realloc(li->dados, novaQtd*sizeof(struct aluno));
            li->tamanhoInicial = novaQtd;
            printf("Aumentado tamanho da lista para %d\n",novaQtd);
          }
          int k,i = 0;
        while(i<li->qtd && li->dados[i].matricula < al.matricula)i++;
             for(k=li->qtd-1; k >= i;  k--)
            li->dados[k+1] = li->dados[k];
            li->dados[i] = al;
            li->qtd++;
            return 0;
    }

int remove_lista_inicio(Lista* li){
        if(li ==   NULL)
        return -1;
        if(li->qtd == 0)
        return -1;
        int k = 0;
        for(k=0; k< li->qtd-1; k ++)
        li->dados[k] = li->dados[k+1];
        li->qtd--;
        return 0;
}

    int remove_lista_final(Lista* li){
    if(li == NULL)
    return -1;
    if(li->qtd ==0)
    return -1;
    li->qtd--;
    return 0;
}

int remove_lista(Lista* li, int mat){
          if(li ==   NULL)
          return -1;
          if(li->qtd  ==   0)
          return -1;
          int k,i = 0;
          while(i<li->qtd && li->dados[i].matricula !=  mat)i++;
          if(i== li->qtd)
          return 0;
          for(k=i; k<li->qtd-1; k++)
          li->dados[k] = li->dados[k+1];
          li->qtd--;
          return 0;
}

int remove_lista_otimizado(Lista* li, int mat){
          if(li ==   NULL)
          return -1;
          if(li->qtd  ==  0)
          return -1;
          int i = 0;
          while(i<li->qtd && li->dados[i].matricula !=  mat)i++;
          if(i== li->qtd)
          return 0;
          li->qtd--;
          li->dados[i] = li-> dados[li->qtd];
          return 0;
}

 int tamanho_lista(Lista* li){
           if(li ==   NULL)
            return -1;
           else
          return li->qtd;
}

int lista_cheia(Lista* li){
          if(li ==   NULL)
        return -1;
    return (li->qtd  ==   MAX);
}

int lista_vazia(Lista* li){
          if(li ==   NULL)
        return -1;
        return (li->qtd==0);
}

int imprime_lista(Lista *li){
    if(li == NULL)
    return -1;
    int i;
    for(i=0; i<li->qtd; i++){
    printf("Matricula: %d\n",li->dados[i].matricula);
    printf("Nome: %s\n",li->dados[i].nome);
    printf("Notas: %f %f %f\n",li->dados[i].n1, li->dados[i].n2,li->dados[i].n3);
    printf("-------------------------------\n");
    }
    return 0;
    }

