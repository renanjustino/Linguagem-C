// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n[6], i;
    printf("<< Listando um vetor em ordem inversa >>\n");
    for(i=0;i<6;i++){
    printf("Entre com o número %d: ", i+1);
        scanf("%d", &n[i]);
    }
    printf("A ordem inversa dos números é: %d %d %d %d %d %d \n", n[5],n[4],n[3],n[2],n[1],n[0]);
    return 0;
}

/*
Faça um algoritmo em que o usuário digite 6 números e o algoritmo mostra na tela os 6 números digitados na ordem inversa
 
Exemplo de saída:
<< Listando um vetor ordem inversa >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 0
Entre com o numero 5: 3
Entre com o numero 6: 6

A ordem inversa dos números é: 6 3 0 4 6 5
*/