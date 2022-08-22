#include <stdio.h>
#include <stdlib.h>

int main()
{
float valor, comissao;
printf("Digite o valor da venda: ");
scanf("%f", &valor);
if(valor >= 100000){
comissao = 700+ (valor*0.16);
printf("Comissão a ser paga: %.2f \n", comissao);
}
else if(valor < 100000 && valor >= 80000){
comissao = 650+ (valor*0.14);
printf("Comissão a ser paga: %.2f \n", comissao);
}
else if(valor <80000 && valor >=60000){
comissao = 600+ (valor*0.14);
printf("Comissão a ser paga: %.2f \n", comissao);
}
else if(valor <60000 && valor >=40000){
comissao = 550+ (valor*0.14);
printf("Comissão a ser paga: %.2f \n", comissao);
}
else if(valor <40000 && valor >=20000){
comissao = 500+ (valor*0.14);
printf("Comissão a ser paga: %.2f \n", comissao);
}
else if(valor <20000){
comissao = 400+ (valor*0.14);
printf("Comissão a ser paga: %.2f \n", comissao);
}
}



