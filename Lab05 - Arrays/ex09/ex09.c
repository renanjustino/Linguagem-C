// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    float media;
    printf("Entre com o número de alunos: ");
    scanf("%d", &n);
    if(n>100){
    printf("Erro! O número máximo de alunos permitido é 100. \n");
    return 0;
    }
    float alunos[n]; 
    int i;
    printf("<< Media de n alunos. Maximo 100 alunos >> \n");
    for(i=0;i<n;i++){
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i]);
        media = media+alunos[i];
    }
    media = media/n;
    printf("Relatório de notas \n");
    for(i=0;i<n;i++){
        printf("A nota do aluno %d é: %.1f\n", i+1, alunos[i]);
    }
        printf("A média da turma é: %.1f\n", media);
    return 0;
}

/*
Faça um programa que calcula a média das notas dos alunos de uma turma. Note 
que uma turma pode ter no máximo 100 alunos (mostrar uma mensagem de erro 
caso o número escolhido seja maior que 100). Peça para o usuário entrar com 
o número de alunos e ao final mostre a nota de todos os alunos.

Exemplo de Saída
<< Media de n alunos. Maximo 100 alunos >>
Entre com o numero de alunos: 4
Digite a nota do aluno 1: 6
Digite a nota do aluno 2: 7
Digite a nota do aluno 3: 5
Digite a nota do aluno 4: 4

Relatorio de Notas
Nota do aluno 0: 6
Nota do aluno 1: 7
Nota do aluno 2: 5
Nota do aluno 3: 4
Media da turma:  5.5

------------------------------------
Exemplo de Saída 2
<< Media de n alunos. Maximo 100 alunos >>
Entre com o numero de alunos: 400
Erro! O numero maximo de alunos permitido eh 100.
*/

