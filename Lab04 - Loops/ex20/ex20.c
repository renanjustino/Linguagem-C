#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
  
  int n, cont = 0;
  printf("Digite qtd de linhas: ");
  scanf("%d", &n);
    
  for(short i = 0; i < n; i++){
    for(short j = 0; j <= i; j++){
      cont ++;
      printf("%d ", cont);
    }
    printf("\n");
  }  

  return 0;
}



