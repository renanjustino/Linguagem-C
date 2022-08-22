#include <stdio.h>

int main() {
    printf("<< Sucessor e Antecessor >>\n");
    printf("Digite um numero: \n");
    int n;
    scanf("%d", &n);
    printf("Antecessor: %d\n", n-1);
    printf("Numero: %d\n", n);
    printf("Sucessor: %d\n", n+1);
}

/*
=> Ler um número e retorne seu antecessor e seu sucessor.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Sucessor e Antecessor >>
Digite um numero: 2

Antecessor: 1
Numero: 2
Sucessor: 3
-------------------------------------------------------------------------------
*/