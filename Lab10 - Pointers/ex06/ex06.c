06)
#include <stdio.h>

int main() {
  printf("Hello World\n");
  /* Pois cada variavel possui uma quantidade
  exata de bytes, então quando pulamos um
  valor inteiro na posiçao guardada pelo
  ponteiro, esse valor inteiro ira multi-
  plicar a quantidade de bytes de cada va-
  riavel e pular o conteudo resultante na 
  quantidade de memoria. Por exemplo, tendo
  um inteiro que é 4 bytes, ao somar +1 
  irá pular 4 na memória, pois o tipo int é 4 bytes,
  ex endereço 1 + 4 bytes = 5.
  */
  return 0;
}