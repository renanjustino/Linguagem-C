#include <stdio.h>
#include <math.h>

int main() {
    int bit1, bit2, bit3, bit4, res1,res2,res3,res4;
    int decimal;
    printf("== Conversor de numeros binarios ==\n");
    printf("Digite o 1o. bit: ");
    scanf("%d", &bit1);
    printf("Digite o 2o. bit: ");
    scanf("%d", &bit2);
    printf("Digite o 3o. bit: ");
    scanf("%d", &bit3);
    printf("Digite o 4o. bit: ");
    scanf("%d", &bit4);
    if (bit1==1)
    res1 = pow(2,3);
    else 
    res1=0;
    if (bit2==1)
    res2 = pow(2,2);
    else
    res2=0;
    if (bit3==1)
    res3 = pow(2,1);
    else
    res3=0;
    if (bit4==1)
    res4 = pow(2,0);
    else
    res4=0;
decimal = res1+res2+res3+res4;
printf("O numero binario %d%d%d%d corresponde ao numero decimal %d", bit1,bit2,bit3,bit4,decimal);
}

/*
=> Faça um conversor de número binário para decimal (inteiro). 
O número deve ter 4 bits, sendo o bit mais significativo digitado primeiro. 
Mostrar na resposta o número binário e o número decimal.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Conversor de numeros binarios >>
Digite o 1o. bit: 1
Digite o 2o. bit: 0
Digite o 3o. bit: 1
Digite o 4o. bit: 1
O numero binario 1011 corresponde ao numero decimal 11
-------------------------------------------------------------------------------
*/