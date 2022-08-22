#include <stdio.h>
#include <stdlib.h>

int main()
{
float a, b, c;
printf("Digite o lado1 do triângulo: ");
scanf("%f", &a);
printf("Digite o lado2 do triângulo: ");
scanf("%f", &b);
printf("Digite o lado3 do triângulo: ");
scanf("%f", &c);
if(a>b+c)
printf("Nenhum triângulo formado!\n");
else if(b>a+c)
printf("Nenhum triângulo formado!\n");
else if(c>a+b)
printf("Nenhum triângulo formado!\n");
else{
if(a*a == (b*b) + (c*c))
printf("Triângulo Retângulo\n");
else if(a*a > (b*b) + (c*c))
printf("Triângulo Obtusângulo\n");
else if(a*a < (b*b) + (c*c))
printf("Triângulo Acutângulo\n");
if(a<0 || b <0 || c<0)
printf("Valor inválido!\n");
}
}


