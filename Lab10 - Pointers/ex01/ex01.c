#include <stdio.h>

int main() {
  unsigned long int *pont; 
  int i;
  int val[5] = {2,4,5,8,10};
  pont = &val;
  scanf("%ld", pont + 2);
  for(i = 0; i < 5; i++){
    printf("%d", val[i]);
  }
  return 0;
}

/*
Crie um programa que contenha a seguinte variável
int val[5] = {2,4,5,8,10};
                  ^
Utilizando a função scanf, altere o valor de 5 para 6. 
Não use o operador & no scanf. Utilize uma variável do tipo inteira*
para guardar o endereço da posição do vetor.

*obs:
unsigned int (para programas em 32bit)
unsigned long int (para programas em 64)

*/
  