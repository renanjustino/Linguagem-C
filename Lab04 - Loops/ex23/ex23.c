#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  int termos;
  double e = 1.0, soma = 0.0, fatorial = 1.0;
  
  printf("<< Número neperiano >>\n");
  printf("Entre com o número de termos: ");
  scanf("%d", &termos);
  
  for(short i = 1; i <= termos; i++){
    fatorial = fatorial * i;
    e = e + (1 / fatorial);
  }
  
  printf("e ~ %.14lf", e);
  return 0;
}

