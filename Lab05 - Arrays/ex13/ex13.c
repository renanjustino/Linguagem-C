#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int v[5];
  int i;
	printf("<< Zerando negativos >> \n");
  for(i=0;i<5;i++){
      printf("Entre com o número %d: ", i+1);
      scanf("%d", &v[i]);
      if(v[i] <0)
      v[i] = 0;
  }
  printf("\nNegativo zerados:");
  for( i = 0; i < 5; i++){
    printf(" %d", v[i]);
  }
  return 0;
}


/*
Leia um vetor de 5 posições e atribua valor 0 para todos os elementos
que possuírem valores negativos. Mostre o vetor final.

Exemplo de saída:
<< Zerando negativos >>
Entre com o numero 1: 5
Entre com o numero 2: -6
Entre com o numero 3: 4
Entre com o numero 4: 0
Entre com o numero 5: -3

Negativo zerados: 5 0 4 0 0 
*/
