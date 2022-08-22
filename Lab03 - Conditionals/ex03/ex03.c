#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor;
    char codigo;
	printf("<<  Valor do Produto com imposto >>\n");
    printf("Digite o valor do produto R$: ");
    scanf("%f", &valor);
    printf("Digite a unidade da federação: ");
    scanf(" %c", &codigo);
    if(codigo=='1'){
    valor= valor*0.07 + valor;
    printf("Valor final com impostos R$: %.2f \n", valor);
    }
    else if(codigo=='2'){
    valor= valor*0.12 + valor;
    printf("Valor final com impostos R$: %.2f \n", valor);
    }
    else if(codigo=='3'){
    valor= valor*0.15 + valor;
    printf("Valor final com impostos R$: %.2f \n", valor);
    }
    else if(codigo=='4'){
    valor= valor*0.08 + valor;
    printf("Valor final com impostos R$: %.2f \n", valor);
    }
    else
    printf("Código do estado inválido!");
}


