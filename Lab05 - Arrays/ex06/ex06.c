// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n[5], i=0;
    int maior=0, menor=0, posmenor=0, posmaior=0;
    float media;
    for(i=0;i<5;i++){
        printf("Entre com o número %d: ", i+1);
        scanf("%d", &n[i]);
        menor=n[0];
        media = (media + n[i]);
if(i == 0){
      maior = n[i];
      menor = n[i];
      posmaior = i;
      posmenor = i;
    }
    else if(n[i] > maior){
      maior = n[i];
      posmaior = i;
    }
    else if(n[i] < menor){
      menor = n[i];
      posmenor = i;
    }
    }
    media = media/5;
    printf("Os numeros digitados são: %d %d %d %d %d \n", n[0],n[1],n[2],n[3],n[4]);
    printf("O maior valor é: %d, localizado na posição %d do vetor\n", maior, posmaior);
    printf("O menor valor é: %d, localizado na posição %d do vetor\n", menor, posmenor);
    printf("A média é: %.1f\n", media);
    return 0;
}

/*
Fazer um programa para ler 5 valores, e, em seguida, mostrar todos os valores
lidos juntamente com o maior (Max), o menor (Min) e a média (Mean) dos valores
Mostrar o índice (index) do vetor associado ao maior número e ao menor número 

Exemplo de saída:
<< Five Values with index >>
Input #1: 5
Input #2: 6
Input #3: 4
Input #4: 0
Input #5: 3

The numbers entered are: 5 6 4 0 3
Max. Value: 6, index 1 of the array
Min. Value: 0, index 3 of the array
Mean: 3.6
*/
