#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperatura;
    float conversor;
    char unidade;
	printf("<< Conversor de Temperatura >>\n");
    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);
    printf("Digite a unidade: ");
    scanf(" %c", &unidade);
    if(unidade=='c'){
    conversor = (temperatura *9/5) + 32;
    printf("%1.f graus Celsius equivale a %1.f graus Fahrenheit", temperatura, conversor);
    }
       if(unidade=='f'){
    conversor = (temperatura-32)*5/9;
    printf("%1.f graus Celsius equivale a %1.f graus Fahrenheit", temperatura, conversor);
    }
    else
    printf("Erro na unidade informada!");
    }


