#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  char nome[50];
  printf("<< Vetor de char>>\n");
  printf("Digite um nome: ");
  gets(nome);
  printf("O nome digitado é: %s", strupr(nome));
  return 0;
}
