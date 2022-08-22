// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n[6], i;
    printf("<< Listando um vetor - com loops >>\n");
    for(i=0;i<6;i++){
    printf("Entre com o número %d: ", i+1);
        scanf("%d", &n[i]);
    }
    printf("Os valores lidos são: %d %d %d %d %d %d \n", n[0],n[1],n[2],n[3],n[4],n[5]);
    return 0;
}

/*
Crie um programa que lê 6 valores inteiros e em seguida mostra na tela os 
valores lidos. Utilize loops e utilize vetores para armazenar os números.
(pense qual o melhor loop: for, while ou do-while)
 
Exemplo de saída:
<< Listando um vetor - com loops >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 0
Entre com o numero 5: 3
Entre com o numero 6: 6

Valores lidos: 5 6 4 0 3 6
*/