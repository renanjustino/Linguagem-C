#include <stdio.h>

int main() {
  int val[5] = {2,4,5,8,10};
  int *pval;
  pval = &val;
  int i;
  printf("Valores no vetor val: %d, %d, %d, %d, %d.\n", *pval, *pval + 1, *pval + 2, *pval + 3, *pval + 4);
  printf("\nMapa de memoria:\n");
  for( i = 0; i < 5; i++){
    printf("Posiçao %d do vetor; Valor: %d; Posiçao de memoria: %d\n", i + 1, *pval, pval);
    pval++;
  }
  return 0;
}