#include <stdio.h>

int main() {
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float media;
    printf("<< Media Aritmetica >>\n");
    printf("Digite a 1a nota: ");
    scanf("%f", &nota1);
    printf("Digite a 2a nota: ");
    scanf("%f", &nota2);
    printf("Digite a 3a nota: ");
    scanf("%f", &nota3);
    printf("Digite a 4a nota: ");
    scanf("%f", &nota4);
    printf("===Notas===");
    printf("Nota1: %.f; Nota2: %.f; Nota3: %.f; Nota4: %.f\n", nota1, nota2, nota3, nota4);
    media = (nota1+nota2+nota3+nota4)/4;
    printf("Media: %.f", media);
}

/*
=> Ler quatro notas e mostrar as notas e a média aritmética obtida.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Media Aritmetica >>
Digite a 1a nota: 30
Digite a 2a nota: 40
Digite a 3a nota: 60
Digite a 4a nota: 30
===Notas===
Nota 1: 30; Nota 2: 40; Nota 3: 60; Nota 4: 30
Media: 40
-------------------------------------------------------------------------------
*/