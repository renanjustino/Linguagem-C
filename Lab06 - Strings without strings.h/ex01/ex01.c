#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned char c = 32;
  int cont = 0;
  
  while(c < 127){
    if(cont < 7){
      printf("%d %c\t", c, c);
      c++;
      cont++;
    }
    else{
      printf("\n%d %c\t", c, c);
      c++;
      cont = 1;
    }
  }
  return 0;
}