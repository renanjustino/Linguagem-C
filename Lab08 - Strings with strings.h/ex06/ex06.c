#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  char nome[50];
  int i;
  printf("<< Separa letras>>\n");
  printf("Digite o nome: ");
  fgets(nome,50,stdin);
  for(i=0;i<strlen(nome)-1;i++){
    printf("%da letra: %c\n", i+1, nome[i]);
  }
  return 0;
}
