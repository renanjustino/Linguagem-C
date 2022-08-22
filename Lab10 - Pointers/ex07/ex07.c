#include <stdio.h>
#include <string.h>

int main() {
  char nome[] = "José Augusto";
  char *pontnome;
  pontnome = &nome[0];
  int i;
  for(i = 0; i < 14; i++){
    printf("%c", *pontnome);
    pontnome++;
  }
  return 0;
}