// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int notas[5]; 
    int i;
    int maior, posmaior;
    int proporcao;
    printf("<< Normalizando as notas >> \n");
    for(i=0;i<5;i++){
    printf("Entre com a nota do aluno %d: ", i+1);
    scanf("%d", &notas[i]);
    if(i==0){
    maior = notas[i];
    posmaior = i;
    }
    else if(notas[i] > maior){
    maior = notas[i];
    posmaior = i;
    }
    }
    notas[posmaior] = maior;
    proporcao = 100/maior;
    printf("\n");
    printf("Notas normalizadas\n\n");
    for(i=0;i<5;i++){
    notas[i] = notas[i]*proporcao;
    printf("A nota do aluno %d é %d \n", i+1, notas[i]);
    }
    return 0;
}

/*
Elabore um algoritmo para normalizar as notas de uma turma de 5 alunos.
A maior nota deve virar 100 e as demais devem ser modificadas 
proporcionalmente (pense em regra de três).

Exemplo de Saída
<< Normalizando as notas >>
Entre com a nota do aluno 1: 16
Entre com a nota do aluno 2: 20
Entre com a nota do aluno 3: 30
Entre com a nota do aluno 4: 45
Entre com a nota do aluno 5: 50

Notas normalizadas

A nota do aluno 1 é 32
A nota do aluno 2 é 40
A nota do aluno 3 é 60
A nota do aluno 4 é 90
A nota do aluno 5 é 100
*/
