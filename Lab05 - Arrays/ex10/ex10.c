// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a[3], b[3];
    int c[3];
    int i;
    printf("<< Subtração de vetores >> \n");
    for(i=0;i<3;i++){
    printf("Digite o valor %d de A: ", i+1);
    scanf("%d", &a[i]);
}
    printf("\n");
    for(i=0;i<3;i++){
    printf("Digite o valor %d de B: ", i+1);
    scanf("%d", &b[i]);
}
    for(i=0;i<3;i++){
    c[i] = a[i] - b[i];
}
printf("O vetor C, definido como C = A-B: (%d %d %d)", c[0], c[1], c[2]);
}

/*
Faça um programa que receba do usuário dois arrays  A e B, com 3 números inteiros cada. Crie um novo array C calculando C = A - B. Mostre na tela os dados do array C.

Exemplo de saída:
<< Subtracao de vetores >>
Digite o valor 1 de A: 50
Digite o valor 2 de A: 60
Digite o valor 3 de A: 70

Digite o valor 1 de B: 30
Digite o valor 2 de B: 0
Digite o valor 3 de B: -10

O vetor C, definido como C = A-B:  (20, 60, 80) 
*/

