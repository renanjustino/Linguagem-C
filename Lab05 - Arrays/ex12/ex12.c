// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  float maior;
  float bolinhas[4];
  float total;
  total = 0.0;
  printf("<< Probabilidades >>\n");
  printf("\n");
  printf("Digite a quantidade de bolinhas\n");
  printf("Verde: ");
  scanf("%f", &bolinhas[0]);
  maior = bolinhas[0];
  total = total + bolinhas[0];
   printf("Azul: ");
  scanf("%f", &bolinhas[1]);
  if(bolinhas[1] > maior){
    maior = bolinhas[1];
  }
  total = total + bolinhas[1];
   printf("Amarela: ");
  scanf("%f", &bolinhas[2]);
  if(bolinhas[2] > maior){
    maior = bolinhas[2];
  }
  total = total + bolinhas[2];
   printf("Vermelha: ");
  scanf("%f", &bolinhas[3]);
  if(bolinhas[3] > maior){
    maior = bolinhas[3];
  }
  total = total + bolinhas[3];
  printf("\nProbabilidades\n");
  if(maior == bolinhas[0]){
    printf("Verde: %.1f%% << Maior probabilidade\n", bolinhas[0] / total * 100.0);
  }
  else printf("Verde: %.1f%%\n", bolinhas[0] / total * 100.0);
  if(maior == bolinhas[1]){
    printf("Azul: %.1f%% << Maior probabilidade\n", bolinhas[1] / total * 100.0);
  }
  else printf("Azul: %.1f%%\n", bolinhas[1] / total * 100.0);
  if(maior == bolinhas[2]){
    printf("Amarela: %.1f%% << Maior probabilidade\n", bolinhas[2] / total * 100.0);
  }
  else printf("Amarela: %.1f%%\n", bolinhas[2] / total * 100.0);
  if(maior == bolinhas[3]){
    printf("Vermelha: %.1f%% << Maior probabilidade\n", bolinhas[3] / total * 100.0);
  }
  else printf("Vermelha: %.1f%%\n", bolinhas[3] / total * 100.0);
  
  return 0;
}


/*
Uma piscina de bolinhas possui bolas azuis, verdes, amarelas e vermelhas. 
Faça um programa em que o usuário digita a quantidade de bolinhas de cada
cor existente em uma piscina e mostra a probabilidade de ocorrência de cada 
cor, indicando qual possui a maior probabilidade

Exemplo de saída:
<< Probabilidades >>

Digite a quantidade de bolinhas
Verde: 51
Azul: 60
Amarela: 70
Vermelha: 80

Probabilidades
Verde: 19.5%
Azul: 22.9%
Amarela: 26.8%
Vermelha: 30.6% << Maior probabilidade
*/

