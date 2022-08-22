#include <stdio.h>

int main() {
  int i;
  double vetor[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
  for( i = 9; i >= 0; i--){
    printf("%.2lf ", *(vetor + i));
  }
  return 0;
}