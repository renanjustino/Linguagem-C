#include <stdio.h>

int main() {
  int a;
  double b;
  void *pgen;
  printf("Digite os valores inteiros e flutuantes\n");
  pgen = &a;
  scanf("%d", (int *)pgen);
  pgen = &b;
  scanf("%lf", (double *)pgen);
  printf("Numeros lidos:\n");
  pgen = &a;
  printf("%d\n", *(int *)pgen);
  pgen = &b;
  printf("%.2lf", *(double *)pgen);
  return 0;
}