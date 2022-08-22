#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int main() {
  char nome [50];
  printf("<< Vetor de Char >>\n");
  printf("Digite um nome: ");
  gets(nome);
  printf("O nome digitado é: %s\n", nome);
  
  return 0;
}