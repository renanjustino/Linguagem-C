#include <stdio.h>

int main() {
  int *plidos, lidos, pares = 0, impares = 0;
  printf("Quantos inteiros serão lidos: ");
  scanf("%d", &lidos);
  plidos = (int *)malloc(lidos*sizeof(int));
  printf("\n");
  for(short i = 0; i < lidos; i++){
    printf("%dº inteiro: ", i + 1);
    scanf("%d", &plidos[i]);
    if(plidos[i] % 2 == 0){
      pares++;
    }
    else impares++;
  }
  printf("\nSão pares: %d dos %d inteiros lidos.\nSão impares: %d dos %d inteiros lidos.", pares, lidos, impares, lidos);
  return 0;
}

/*
3) Faça um programa que leia n inteiros (definidos pelo usuário) 
armazenando-os em uma memória alocada dinamicamente. Em seguida, mostre
quantos dos n números são pares e quantos são ímpares.


Exemplo de saída:
<< Par ou Impar >>
Quantos inteiros serao lidos: 5
1º inteiro: 1
2º inteiro: 2
3º inteiro: 3
4º inteiro: 4
5º inteiro: 5

Sao pares: 2 dos 5 inteiros lidos.
Sao impares: 3 dos 5 inteiros lidos.

*/