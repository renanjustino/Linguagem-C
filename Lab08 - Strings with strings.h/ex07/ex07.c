#include <string.h>
#include <ctype.h>


int main() {
  char str[50];
  short i;
  printf("<<Sem vogais>>\n");
  printf("Digite a string: ");
  fgets(str, 50, stdin);
  printf("Saída sem vogais: ");
  while(str[i] != '\n' && str[i] != '\0'){
    if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
      printf("%c", str[i]);
      i++;
    }
    else i++;
  }
  return 0;
}