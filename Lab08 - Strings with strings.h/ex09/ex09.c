#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  char palavra[30];
  printf("<<invertendo>> \n");
  printf("Digite a string: ");
  gets(palavra);
  printf("Saída invertida: %s", strrev(palavra));
  return 0;
}
