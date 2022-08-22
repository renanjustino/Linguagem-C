#include <stdio.h>

int main(){
    float nota1;
    float nota2;
    printf("<< Calculo da Media >>\n");
    printf("Digite a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota da prova 2: ");
    scanf("%f", &nota2);
    float media = (nota1+nota2)/2;
    printf("A nota media eh %.f\n", media);
}

/*
=> Faça um algoritmo que calcula a média das notas de 2 provas.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Calculo da Media >>
Digite a nota da prova 1: 80
Digite a nota da prova 2: 90
A nota media eh 85
-------------------------------------------------------------------------------
*/