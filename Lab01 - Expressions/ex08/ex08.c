#include <stdio.h>

int main() {
    int dias;
    int bruto;
    float liquido;
    float ir;
    float iss;
    float impostos;
    
    printf("<< Pagamento encanador >>\n");
    printf("Digite o numero de dias trabalhados: ");
    scanf("%d", &dias);
    bruto = 30*dias;
    iss = bruto*0.04;
    ir = (bruto-iss)*0.08;
    impostos = ir+iss;
    liquido = bruto-impostos;
    printf("Valor bruto R$: %d\n", bruto);
    printf("Valor liquido R$: %.2f\n", liquido);
    printf("ISS R$: %f\n", iss);
    printf("IR R$: %.2f\n", ir);
}

/*
=> Um contador percebeu que o cálculo de IR do encanador estava errado, pois estava sendo calculado sobre o valor bruto que ele recebeu. 
Refaça o programa anterior, considerando que o IR é sobre o valor bruto após o desconto do ISS.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Pagamento encanador >>
Digite o numero de dias trabalhados: 30
Valor bruto R$: 900
Valor liquido R$: 794.88
ISS R$: 36
IR R$: 68.12
-------------------------------------------------------------------------------
*/