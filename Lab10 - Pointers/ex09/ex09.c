#include <stdio.h>

int main() {
  double vetor[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
  int i;
  for(i = 0; i < 10; i++){
    printf("%.2lf ", *(vetor + i));
  }
  return 0;
}