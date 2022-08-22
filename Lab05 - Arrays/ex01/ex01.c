// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n[6];
	printf("<< Listando um vetor >> \n");
    printf("Entre com o número 1: ");
    scanf("%d", &n[0]);
    printf("Entre com o número 2: ");
    scanf("%d", &n[1]);
    printf("Entre com o número 3: ");
    scanf("%d", &n[2]);
    printf("Entre com o número 4: ");
    scanf("%d", &n[3]);
    printf("Entre com o número 5: ");
    scanf("%d", &n[4]);
    printf("Entre com o número 6: ");
    scanf("%d", &n[5]);
    printf("Os valores lidos são: %d %d %d %d %d %d", n[0],n[1],n[2],n[3],n[4],n[5]);
    return 0;
}