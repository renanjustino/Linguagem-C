#include <stdio.h>

int main(){
    float n;
    printf("<< Calculo do Quadrado de n >>\n");
    printf("Digite um número: ");
    scanf("%f", &n);
    float quadrado = n*n;
    printf("O valor de %.1f ao quadrado é %.2f", n, quadrado);
}

/*
=> Efetuar a leitura de um número real e apresentar o resultado do quadrado desse número.

-------------------------------------------------------------------------------
Exemplo de saída: 
<< Calculo do Quadrado de n>>
Digite um número: 2.5O 
O valor de 2.5 ao quadrado é 6.25
-------------------------------------------------------------------------------
*/