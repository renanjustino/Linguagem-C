#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  int v[8], aux = 0, aux1[4], aux2=0;
  int iguais[4]; 
  int repetidos = 0; 
  int contador = 0;
  int auxvetor =0;
  int i;
  int k;
  int j;
  int l;
  printf("<< Valores iguais >>\n");
  for(i = 0; i < 8; i++){
    printf("Entre com o número %d: ", i + 1);
    scanf("%d", &v[i]);
    for(j = 0; j < i; j++){
      if(i != j){
        if(v[i] == v[j]){
          for(k = 0; k < repetidos; k++){
            if(v[i] == iguais[k]){
              aux++;
            }
          }
          if(aux == 0){
            iguais[repetidos] = v[i];
              contador++;
              repetidos++;
          }
        }
      }
    }
    aux = 0;
  }
  
  printf("Valores repetidos: \n");
  
 for(i = 0; i < 8; i++){
    aux1[auxvetor] = 0;
    for(j = 0; j < i; j++){
      if(v[i] == v[j]){
        aux2++;
      }
    }
    if(aux2 == 0){
      for(l = 0; l < 8; l++){
        if(v[i] == v[l]){
          aux1[auxvetor]++;
        }
      }
    }
    if(aux1[auxvetor] > 1){
      printf("%d aparece %d vezes\n", v[i], aux1[auxvetor]);
    }
    auxvetor++;
    aux2 = 0;
  } 
  return 0;
}


/*

Faça um programa que leia um vetor de 8 posições e verifique se existem 
valores iguais e os escreva a quantidade de vezes que eles aparecem na lista

Exemplo de saída:
<< Valores iguais >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 5
Entre com o numero 5: -3 
Entre com o numero 6: -3
Entre com o numero 7: -3
Entre com o numero 8: 6


Valores repetidos: 
5 aparece 2 vezes
6 aparece 2 vezes
-3 aparece 3 vezes

*/
