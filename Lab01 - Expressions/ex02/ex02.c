#include <stdio.h>

int main() {
    float temperaturaCelsius;
    float fahrenheit;
    printf("<< Conversor Temperatura >>\n");
    printf("Digite a temperatura (em Celsius):");
    scanf("%f", &temperaturaCelsius);
    fahrenheit = temperaturaCelsius * (9.0/5.0) + 32.0;
    printf("%f graus Celsius correspondem a %f Fahrenheit", temperaturaCelsius, fahrenheit);
}

/*
=> Ler uma temperatura em graus Celsius e apresentá-la convertida em graus Fahrenheit. A fórmula de 
conversão é : F = C ∗ (9.0/5.0)+ 32.0, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Conversor Temperatura >>
Digite a temperatura (em Celsius): 2.5O 
30 graus Celsius correspondem a 86 Fahrenheit
-------------------------------------------------------------------------------
*/