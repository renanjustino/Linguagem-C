#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  char completo[40], nome[20], sobrenome[8];
  int c = 0, teste = 0, c1 = 0;
  printf("<<  Nomes  >>\n");
  printf("Digite um nome e sobrenome: ");
  fgets(completo, 40, stdin);
  while(teste == 0){
    if(completo[c] != ' '){
      nome[c] = completo[c];
      c++;
    }
    else {
      printf("Nome: %s", nome);
      teste++;
      c++;
    }
  }
  while(teste != 0){
    if(completo[c] != '\n' && completo[c] != '\0'){
      sobrenome[c1] = completo[c];
      c++;
      c1++;
    }
    else{
      printf("\nSobrenome: %s", sobrenome);
      teste *= 0;
    }
  }
  return 0;
}
