
#include <stdio.h>
#include <stdlib.h>

int main() {
    char pessoa[50]; 
    char c;
    int i, posicao; 
    printf("<< Vetor de char>>\n");
    printf("Digite um nome: ");
    posicao = 0;
    c = getchar(); 
    while (c != '\n') {  
        pessoa[posicao] = c;
        posicao++;
        c = getchar(); 
    }
    printf("O nome digitado é: ");
    for (i=0; i < posicao; i++){
        if(pessoa[i] >=65 && pessoa[i] <= 90){
        printf("%c", pessoa[i]);
        }
        else printf("%c", pessoa[i] - 32);
    }
    return 0;
}