#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  int v[8], aux = 0, aux1 = 0;
  int iguais[4]; 
  int repetidos = 0; 
  int contador = 0;
  int i;
  int k;
  int j;
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
  
  printf("Valores repetidos: ");
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < contador; j++){
      if(v[i] == iguais[j]){
        for(k = 0; k < i; k++){
          if(v[i] == v[k]){
            aux++;
          }
        }
        if(aux == 0){
             if(i == 0){
                printf("%d", v[i]);
               }
              else printf(", %d", v[i]);
        }
      }
    }
    aux = 0;
  }
  return 0;
}


/*
Faça um programa que leia um vetor de 8 posições e verifique se existem 
valores iguais e os escreva (cada número repetido deve aparecer somente 
uma vez na resposta)

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


Valores repetidos: 5, 6, -3
*/
