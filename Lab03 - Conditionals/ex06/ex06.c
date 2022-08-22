#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1, nota2, nota3, media;
    char c;
	printf("<< Calculo da media >>\n");
    printf("Digite a inicial do nome do aluno: ");
    scanf(" %c", &c);
    printf("Digite a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota da prova 2: ");
    scanf("%f", &nota2);
    printf("Digite a nota da prova 3: ");
    scanf("%f", &nota3);
    media = ((nota1*1) + (nota2*1) + (nota3*2))/4;
    if(media>=60)
    printf("A nota media do aluno %c eh %1.f => APROVADO!", c, media);
}
