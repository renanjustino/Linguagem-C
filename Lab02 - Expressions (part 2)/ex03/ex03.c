#include <stdio.h>

int main(){
    char c;
    float nota1;
    float nota2;
    float nota3;
    printf("<< Calculo da Media >>\n");
    printf("Digite o nome do aluno: ");
    scanf("%c", &c);
    printf("Digite a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota da prova 2: ");
    scanf("%f", &nota2);
    printf("Digite a nota da prova 3: ");
    scanf("%f", &nota3);
    float media = (nota1*1+nota2*1+nota3*2)/4;
    printf("A nota media do aluno %c eh %.f\n", c,media);
}

/*
=> Faça um algoritmo que calcule a média ponderada das notas de 3 provas. 
A primeira e a segunda prova têm peso 1 e a terceira tem peso 2. Antes de o usuário 
entrar com as notas do aluno ele deve informar a letra inicial do nome do aluno. 
Ao final, mostrar o a letra inicial do nome do aluno juntamente com a sua média.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Calculo da Media >>
Digite o nome do aluno: T
Digite a nota da prova 1: 40
Digite a nota da prova 2: 40
Digite a nota da prova 3: 80
A nota media do aluno C. eh 60
-------------------------------------------------------------------------------
*/