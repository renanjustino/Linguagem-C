#include <stdio.h>

int main() {
    int dias;
    int bruto;
    int liquido;
    int ir;
    int iss;
    int impostos;
    
    printf("<< Pagamento encanador >>\n");
    printf("Digite o numero de dias trabalhados: ");
    scanf("%d", &dias);
    bruto = 30*dias;
    ir = bruto*0.08;
    iss = bruto*0.04;
    impostos = ir+iss;
    liquido = bruto-impostos;
    printf("Valor bruto R$: %d\n", bruto);
    printf("Valor liquido R$: %d\n", liquido);
    printf("ISS R$: %d\n", iss);
    printf("IR R$: %d\n", ir);
    
}

/*
=> Uma empresa contrata um encanador a R$ 30,00 por dia. Crie um programa que solicite o número de dias trabalhados pelo encanador 
e imprima o valor bruto, o imposto, e a quantia líquida que deverá ser paga ao encanador, sabendo-se que são descontados 8% para 
imposto de renda e 4% de ISS. 

-------------------------------------------------------------------------------
Exemplo de saída:

<< Pagamento encanador >>
Digite o numero de dias trabalhados: 30
Valor bruto R$: 900
Valor liquido R$: 792
ISS R$: 36
IR R$: 72
-------------------------------------------------------------------------------
*/