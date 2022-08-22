#include <stdio.h>
#include <stdlib.h>

int main()
{
    float imc;
    float massa;
    float altura;
	printf("<< IMC >>\n");
	printf("Entre com a massa: ");
	scanf("%f", &massa);
    printf("Entre com a altura: ");
	scanf("%f", &altura);
    imc = massa/(altura*altura);
    if (imc < 18.5)
    printf("Magreza");
    else if (imc >=18.5 && imc <=24.9)
    printf("Saudável");
    else if (imc >=25.0 && imc <=29.9)
    printf("Sobrepeso");
    else if (imc >=30.0 && imc <=34.9)
    printf("Obesidade Grau I");
    else if (imc >=35.0 && imc <=39.9)
    printf("Obesidade Grau II (severa)");
    else if (imc >=40.0)
    printf("Obesidade Grau III (morbida)");
}


