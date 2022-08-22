#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  int fatorial = 1;
  
  printf("<< Fatorial >>\n");
  for(short i = 1; i <= 15; i++){
    fatorial = fatorial * i;
    if(i > 10)
      printf("%d! = %d\n", i, fatorial);
  }
  return 0;
}

// quando chega 13, o valor maximo possivel em um int comum é atingido ai para isso precisa de long int

