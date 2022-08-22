#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int n;
int i;
printf("<< Universidade X >>\n");
printf("Quantos alunos serão cadastrados: ");
scanf("%d", &n);
if(n>10000){
    printf("Não pode ser maior que 10.000 \n");
    return 0;
}
int matricula[n];
char classe[n];
float cra[n];
  for(i=0;i<n;i++){
      printf("Entre com o número do aluno: ");
      scanf("%d", &matricula[i]);
      printf("Entre com a classe social do aluno %d: ", matricula[i]);
      scanf(" %c", &classe[i]);
      printf("Entre com o CRA do aluno %d: ", matricula[i]);
      scanf("%f", &cra[i]);
  }
printf("\n==== Alunos Cadastrados ====");
  for(i = 0; i < n; i++){
    printf("\nNúmero: %d Classe Social: %c CRA: %.2f", matricula[i], classe[i], cra[i]);
  }
  return 0;
}


/*
Faça um programa que armazene informações sobre os alunos de uma universidade. 
O número máximo de alunos que o sistema pode cadastrar é 10000. Os dados a 
serem armazenados são: número de matrícula (inteiro); 
classe social (A, B, C, D ou E); CRA (real). Ao iniciar o programa, informe 
quantos usuários serão cadastrados. Depois de realizado o cadastro, mostre 
todos os dados lidos. A saída do programa deve ser como o exemplo abaixo.
* Proibido o uso de structs

Exemplo de saída:
<< Universidade X >>
Quantos alunos serão cadastrados: 2

Entre com o número do aluno: 5
Entre com a classe social do aluno 5: B
Entre com o CRA do aluno 5: 70

Entre com o número do aluno: 7
Entre com a classe social do aluno 7: B
Entre com o CRA do aluno 7: 60

==== Alunos Cadastrados ====
Número: 5 Classe Social: B CRA: 70.00
Número: 7 Classe Social: B CRA: 60.00
*/
