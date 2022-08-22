// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n[5], i=0;
    int maior=0, media=0, menor=0;
    for(i=0;i<5;i++){
        printf("Entre com o número %d: ", i+1);
        scanf("%d", &n[i]);
        menor=n[0];
        media = (media + n[i]);
        if(n[i] > maior)
        maior = n[i];
        if(n[i] < menor)
        menor = n[i];
    }
    media = media/5;
    printf("Os numeros digitados são: %d %d %d %d %d \n", n[0],n[1],n[2],n[3],n[4]);
    printf("O maior valor é: %d\n", maior);
    printf("O menor valor é: %d\n", menor);
    printf("A média é: %d\n", media);
    return 0;
}

/*
Fazer um programa para ler 5 valores, e, em seguida, mostrar todos os valores
lidos juntamente com o maior (Max), o menor (Min) e a média (Mean) dos valores

Exemplo de saída:
<< Five Values >>
Input #1: 5
Input #2: 6
Input #3: 4
Input #4: 0
Input #5: 3

The numbers entered are: 5 6 4 0 3
Max. Value: 6
Min. Value: 0
Mean: 3.6
*/
