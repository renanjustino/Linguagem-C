#include <stdio.h>
#include <string.h>

struct eletrodomesticos{
  char nome[17];
  double potencia, tempo_ativo;
};

int main() {
  struct eletrodomesticos itens[5];
  int dias;
  double cons_total = 0.0, cons_rel[5];
  for(short i = 0; i < 5; i++){
    printf("Informe os dados do %dº eletrodoméstico: \n", i + 1);
    printf("Nome: ");
    fgets(itens[i].nome, 17, stdin);
    printf("Potência: ");
    scanf("%lf", &itens[i].potencia);
    getchar();
    printf("Tempo ativo por dia:  ");
    scanf("%lf", &itens[i].tempo_ativo);
    getchar();
    printf("\n");
  }
  printf("Informe um valor de tempo (em dia): ");
  scanf("%d", &dias);
  getchar();
  for(short i = 0; i < 5; i++){
    cons_total = cons_total + (dias * itens[i].potencia * itens[i].tempo_ativo);
  }
  printf("Consumo total:  %.0lf kW ", cons_total);
  printf("\nConsumo relativo: \n");
  for(short i = 0; i < 5; i++){
    cons_rel[i] = (100 * itens[i].potencia * itens[i].tempo_ativo * dias / cons_total);
    printf("%s: %.1lf%%\n", itens[i].nome, cons_rel[i]);
  }
  return 0;
}

/*
6.Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa.

    • Crie e leia as informações de 5 eletrodomésticos: o nome (máximo 15 letras), 
      potencia (real,  em kW) e tempo ativo por dia (real, em horas).

    • Leia um valor de tempo t (em dias), calcule e mostre o consumo total na casa e
      o consumo relativo de cada eletrodoméstico  (consumo/consumo total) nesse período
      de tempo. Apresente este ultimo dado em porcentagem.

-------------------------------------------------------------------------------
Exemplo de saída:
Informe os dados do 1º eletrodomestico: 
Nome: Geladeira
Potencia: 800
Tempo ativo por dia: 24

Informe os dados do 2º eletrodomestico: 
Nome: Ar Condicionado
Potencia: 1500
Tempo ativo por dia: 8

Informe os dados do 3º eletrodomestico: 
Nome: Chuveiro
Potencia: 4500
Tempo ativo por dia: 1

Informe os dados do 4º eletrodomestico: 
Nome: Radio
Potencia: 100
Tempo ativo por dia: 6

Informe os dados do 5º eletrodomestico: 
Nome: Computador
Potencia: 750
Tempo ativo por dia: 18

Informe um valor de tempo (em dia): 30
Consumo total: 1494000 KW
Consumo relativo: 
Geladeira 38.6%
Ar Condicionado 24.1%
Chuveiro 9.0%
Radio 1.2%
Computador 27.1%
-------------------------------------------------------------------------------
*/