#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  int jose = 50000, carlos = 25000, meses = 0, ano;
  
  do{
    jose = jose + 800;
    carlos = carlos + 3000;
    meses++;
  }while(carlos <= jose);
  
  ano = meses / 12;
  
  printf("%d", ano);
  
  
  return 0;
}

