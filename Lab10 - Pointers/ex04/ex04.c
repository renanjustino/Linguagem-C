#include <stdio.h>

int main() {
  int val[5] = {2,4,5,8,10};
  int *pval;
  pval = &val;
  int i;
  for(i = 0; i < 5; i++){
    *pval = *pval - 1;
    pval++;
  }
  pval = &val;
  printf("Novo valor do vetor val: \n");
  for( i = 0; i < 5; i++){
    printf("%d ", *pval);
    pval++;
  }
  return 0;
}