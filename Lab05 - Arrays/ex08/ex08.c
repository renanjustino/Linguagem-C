// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float n[5]; 
    int i;
    float desvio=0;
    float media=0;
    float somatorio=0;
    printf("<< Média e desvio-padrão >> \n");
    for(i=0;i<5;i++){
    printf("Digite o valor %d: ", i+1);
    scanf("%f", &n[i]);
    media = media + n[i];
}
    media = media/5;
    for(i=0;i<5;i++){
    somatorio = somatorio + ((n[i] - media) * (n[i] - media));
    }
    desvio = sqrt(somatorio/4);
    printf("A média é %f e o desvio-padrão é %.2f\n", media, desvio);
    return 0;
}

/*
Calcular a média e o desvio padrão amostral de 5 números informados pelo usuário.
obs: desvio-padrão (amostral, normalizado por N-1)

Exemplo de saída:
<< Media e desvio-padrao >>
Digite o valor 1: 50
Digite o valor 2: 60
Digite o valor 3: 70
Digite o valor 4: 80
Digite o valor 5: 60
A media eh 64 e o desvio-padrao eh 11.40
*/

