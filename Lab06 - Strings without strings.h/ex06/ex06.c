#include <stdio.h>

int main() {
  char nome[40], sobrenome[40];
  char c;
  int cn = 0, cs = 0;
  int i;
  printf("<<  Nomes  >>");
  printf("\nDigite o primeiro nome e último nome: ");
  c = getchar();
  do{
    nome[cn] = c;
    cn++;
    c = getchar();
  }while(c != ' ');
  c = getchar();
  do{
    sobrenome[cs] = c;
    cs++;
    c = getchar();
  }while(c != '\n');
  printf("Nome: ");
  for(short i = 0; i < cn; i++){
    printf("%c", nome[i]);
  }
  printf("\nSobrenome: ");
  for(i = 0; i < cs; i++){
    printf("%c", sobrenome[i]);
  }
  return 0;
}