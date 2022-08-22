#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro{
  char mat[13], nome[30];
  int faltas;
  double notas[3];
};

int main() {
  struct cadastro alunos[3];
  double maior_nota = 0.0, media_ger[3], aux_maior = 0.0, aux_menor = 100.0;
  char maior_nota_aluno[30];
  int maior_media = 0, menor_media = 0;
  for(short i = 0; i < 3; i++){
    printf("Entre com os dados do %dº aluno: ", i + 1);
    printf("\nMatricula: ");
    fgets(alunos[i].mat, 13, stdin);
    printf("Nome: ");
    fgets(alunos[i].nome, 30, stdin);
    media_ger[i] = 0.0;
    for(short j = 0; j < 3; j++){
      printf("Nota da %dº prova: ", j + 1);
      scanf("%lf", &alunos[i].notas[j]);
      getchar();
      if(j == 0 && alunos[i].notas[j] > maior_nota){
        maior_nota = alunos[i].notas[j];
        strcpy(maior_nota_aluno, alunos[i].nome);
      }
      media_ger[i] = media_ger[i] + alunos[i].notas[j];
    }
    media_ger[i] = media_ger[i] / 3;
    if(aux_maior < media_ger[i]){
        maior_media = i;
        aux_maior = media_ger[i];
    }
    if(aux_menor > media_ger[i]){
        menor_media = i;
        aux_menor = media_ger[i];
    }
    printf("Número de faltas: ");
    scanf("%d", &alunos[i].faltas);
    getchar();
    printf("\n");
  }
  printf("Aluno com maior nota na 1º prova foi %s com %.1f pontos.", maior_nota_aluno, maior_nota);
  printf("Aluno com maior média geral foi %s com %.1f pontos.", alunos[maior_media].nome, media_ger[maior_media]);
  printf("Aluno com menor média geral foi %s com %.1f pontos. \n", alunos[menor_media].nome, media_ger[menor_media]);
  printf("\nSituação dos Alunos: \n");
  for(short i = 0; i < 3; i++){
    if(media_ger[i] >= 60.0 && alunos[i].faltas <= 18){
      printf("%s, %s. Aprovado. ", alunos[i].mat, alunos[i].nome);
    }else if(media_ger[i] < 60.0 && alunos[i].faltas <= 18){
      printf("%s, %s. Reprovado por nota. ", alunos[i].mat, alunos[i].nome);
    }
    else printf("%s, %s. Reprovado por falta. ", alunos[i].mat, alunos[i].nome);
  }
  return 0;
}

/*
5.Crie uma estrutura representando os alunos de um curso de graduação. 
A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, 
nota da segunda prova, nota da terceira prova, média e número de faltas.

    (a) Permita ao usuário entrar com os dados de 3 alunos. 
    (b) Encontre o aluno com maior nota da primeira prova.
    (c) Encontre o aluno com maior média geral.
    (d) Encontre o aluno com menor média geral.
    (e) Mostre a situação final do aluno. Para ser aprovado o aluno precisa ter nota média final 
        maior ou igual a 60 e ter presença maior ou igual a 75% (considere um total de 72 aulas). 
        No caso de reprovação, mostrar o motivo da mesma, isto é, caso o aluno foi reprovado por 
        falta, mostrar “Reprovado por falta”. Caso tenha sido reprovado por nota, mostrar “Reprovado por nota”. 
        Se um aluno foi reprovado por falta e por nota, prevalece, como motivo para reprovação, as faltas. Assim,
        mostrar a mensagem “Reprovado por falta”. 


-------------------------------------------------------------------------------
Exemplo de saída:
Entre com os dados do 1º aluno: 
Matricula: 1
Nome: Paulo
Nota da prova 1: 50
Nota da prova 2: 70
Nota da prova 3: 60
Numero de faltas: 12

Entre com os dados do 2º aluno: 
Matricula: 2
Nome: Gustavo
Nota da prova 1: 95
Nota da prova 2: 90
Nota da prova 3: 100
Numero de faltas: 19

Entre com os dados do 3º aluno: 
Matricula: 3
Nome: Luis
Nota da prova 1: 50
Nota da prova 2: 60
Nota da prova 3: 58
Numero de faltas: 2

Aluno com maior nota na prova 1 foi Gustavo com 95,0 pontos.
Aluno com maior media geral foi Gustavo com 95,0 pontos.
Aluno com menor media geral foi Luis com 56,0 pontos.

Situacao dos Alunos: 
1- Paulo. Aprovado.
2- Gustavo. Reprovado por falta.
3- Luis. Reprovado por nota.
-------------------------------------------------------------------------------
*/