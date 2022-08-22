#include <stdio.h>

struct pontos{
  int x, y;
};

int main() {
  struct pontos *coordenadas;
  int qtd, i;
  printf("Quantos pontos deseja digitar: ");
  scanf("%d", &qtd);
  coordenadas = (struct pontos *)malloc(qtd*sizeof(struct pontos));
  for( i = 0; i < qtd; i++){
    printf("Entre com a coordenada x do ponto %d: ", i + 1);
    scanf("%d", &coordenadas[i].x);
    printf("Entre com a coordenada y do ponto %d: ", i + 1);
    scanf("%d", &coordenadas[i].y);
  }
  printf("\nPontos digitados: ");
  for(i = 0; i < qtd; i++){
    printf("(%d,%d) ", coordenadas[i].x, coordenadas[i].y);
  }
  free(coordenadas);
  return 0;
}

/*
4)Crie uma struct que armazene pontos inteiros (coordenadas x e y – valores inteiros). 
Crie dinamicamente um  vetor de tamanho n (informado pelo usuário) e indique as 
coordenadas x e y de cada ponto. Ao final, mostrar todos os números digitados.


Exemplo de saída:
Quantos pontos deseja digitar: 5
Entre com a coordenada x do ponto 1: 3
Entre com a coordenada y do ponto 1: 5

Entre com a coordenada x do ponto 2: 4
Entre com a coordenada y do ponto 2: 8

Entre com a coordenada x do ponto 3: 3
Entre com a coordenada y do ponto 3: 4

Entre com a coordenada x do ponto 4: 6
Entre com a coordenada y do ponto 4: 7

Entre com a coordenada x do ponto 5: 23
Entre com a coordenada y do ponto 5: 25

Pontos digitados: (3,5); (4,8); (3,4); (6,7); (23,25)

*/