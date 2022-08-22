#include <stdio.h>

int main() {
  char n1[50], n2[50];
  char c;
  int c1 = 0, c2 = 0, iguais = 0;
  int i;
  printf("<< Compara nomes>>");
  printf("\nDigite o nome 1: ");
  c = getchar();
  do{
    n1[c1] = c;
    c1++;
    c = getchar();
  }while(c != '\n');
  printf("Digite o nome 2: ");
  c = getchar();
  do{
    n2[c2] = c;
    c2++;
    c = getchar();
  }while(c != '\n');
  if(c1 != c2){
    iguais++;
  }
  else{
    for( i = 0; i <c1; i++){
        
      if(n1[i] != n2[i] && n1[i] != n2[i] + 32 && n1[i] != n2[i] - 32){
        iguais++;
      }
    }
  }
  
  if(iguais == 0){
    printf("Os nomes digitados são iguais");
  }
  else printf("Os nomes digitados são diferentes");
  return 0;
}