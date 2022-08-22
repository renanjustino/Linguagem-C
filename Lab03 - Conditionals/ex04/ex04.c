#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1, nota2, nota3;
    float maior=0, menor=0;
    char alunoMaior, alunoMenor;
    char a1, a2, a3;
	printf("<< Notas da Turma >>\n");
	printf("Entre com a nome do aluno #1: ");
	scanf(" %c", &a1);
    printf("Entre com a nota do aluno #1: ");
	scanf("%f", &nota1);
	printf("Entre com a nome do aluno #2: ");
	scanf(" %c", &a2);
	printf("Entre com a nota do aluno #2: ");
	scanf("%f", &nota2);
	printf("Entre com a nome do aluno #3: ");
	scanf(" %c", &a3);
	printf("Entre com a nota do aluno #3: ");
	scanf("%f", &nota3);
	if(nota1>nota2 && nota1>nota3){
	maior = nota1;
	alunoMaior = a1;}
	else if(nota2>nota1 && nota2>nota3){
	maior = nota2;
	alunoMaior = a2;}
	else{
	maior = nota3;
	alunoMaior = a3;}
    if(nota1<nota2 && nota1<nota3){
    menor = nota1;
    alunoMenor = a1;}
    else if(nota1<nota2 && nota1>nota3){
    menor = nota3;
    alunoMenor = a3;}
    else {
    menor = nota2;
    alunoMenor = a2;}
    printf("%c. tem a maior nota (%1.f) e %c. a menor (%1.f)", alunoMaior, maior, alunoMenor, menor);
}


