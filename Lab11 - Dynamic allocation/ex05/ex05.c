#include <stdio.h>
#include <stdlib.h>

struct pontos{
  int x, y;
};

int main(void) {
  struct pontos *coordenadas, *esq, *dir, *ac, *ab;
  int qtd;
  do{
    printf("Quantos pontos deseja digitar(maior que 0): ");
    scanf("%d", &qtd);
  }while(qtd <= 0);
  coordenadas = (struct pontos *)malloc(qtd*sizeof(struct pontos));
  for(int i = 0; i < qtd; i++){
    printf("Entre com a coordenada x do ponto %d: ", i + 1);
    scanf("%d", &coordenadas[i].x);
    printf("Entre com a coordenada y do ponto %d: ", i + 1);
    scanf("%d", &coordenadas[i].y);
  }
  esq = &coordenadas[0];
  dir = &coordenadas[0];
  ac = &coordenadas[0];
  ab = &coordenadas[0];
  for(int i = 1; i < qtd; i++){
      if((*esq).x > coordenadas[i].x){
        esq = &coordenadas[i];
      }
      if((*dir).x < coordenadas[i].x){
        dir = &coordenadas[i];
      }
      if((*ab).y > coordenadas[i].y){
        ab = &coordenadas[i];
      }
      if((*ac).y < coordenadas[i].y){
        ac = &coordenadas[i];
      }
  }
  printf("\nPonto mais a esquerda: (%d,%d)", (*esq).x, (*esq).y);
  printf("\nPonto mais a direita: (%d,%d)", (*dir).x, (*dir).y);
  printf("\nPonto mais a acima: (%d,%d)", (*ac).x, (*ac).y);
  printf("\nPonto mais a abaixo: (%d,%d)", (*ab).x, (*ab).y);
  printf("\nPontos digitados: ");
  for(short i = 0; i < qtd; i++){
    printf("(%d,%d) ", coordenadas[i].x, coordenadas[i].y);
  }
  free(coordenadas);
  return 0;
}

/*
5) Modifique o programa anterior incluindo quatro ponteiros, que apontarão para
os seguintes pontos: mais a esquerda, mais a direita, mais acima, mais abaixo.
Mostre quem são esses pontos utilizando esses ponteiros.

Exemplo de saída:
<< Vetor de pontos alocados dinamicamente >>
Digite a quantidade de pontos a serem armazenados: 5

Digite o valor da coordenada x do ponto 1: 2
Digite o valor da coordenada y do ponto 1: 5

Digite o valor da coordenada x do ponto 2: 4
Digite o valor da coordenada y do ponto 2: 8

Digite o valor da coordenada x do ponto 3: 3
Digite o valor da coordenada y do ponto 3: 4

Digite o valor da coordenada x do ponto 4: 6
Digite o valor da coordenada y do ponto 4: 7

Digite o valor da coordenada x do ponto 5: 23
Digite o valor da coordenada y do ponto 5: 25


Os pontos digitados sao: (2,5); (4,8); (3,4); (6,7); (23,25)

Ponto mais a esquerda: (2,5)
Ponto mais a direita: (23,25)
Ponto mais acima: (23,25)
Ponto mais abaixo: (3,4)

*/