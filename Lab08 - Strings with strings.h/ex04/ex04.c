#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  char nome[50], nome2[50];
  printf("<< Compara nomes>>\n");
  printf("Digite o nome 1: ");
  gets(nome);
  printf("Digite o nome 2: ");
  gets(nome2);
  int resultado = strcmpi(nome, nome2);
  if(resultado == 0)
  printf("Os nomes digitados são iguais");
  else
  printf("Os nomes digitados são diferentes");
  return 0;
}