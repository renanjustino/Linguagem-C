#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  int fatorial = 1;
  
  printf("<< Fatorial >>\n");
  for(short i = 1;i <= 10; i++){
    fatorial = fatorial * i;
    printf("%d! = %d\n", i, fatorial);
  }
  return 0;
}



