#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  
  int bits = 2;
  
  for(short i = 0; i < 7; i++){
    if(i<5){
      printf("\nCom %d bits é possível endereçar %.0f posições de memória", bits, pow(2,bits));
      bits = bits * 2;
    }else{
      printf("\nCom %d bits é possível endereçar %.14E posições de memória", bits, pow(2,bits));
      bits = bits * 2;  
    }
  }
  return 0;
}

