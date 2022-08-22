#include <stdio.h>

int main() {
    int a;
    int b;
    int ab;
    int aorb;
    int nota;
    int axorb;
    printf("== Operadores Booleanos ==\n");
    printf("Digite 0 para falso e nao 0 para verdadeiro\n");
    printf("Entre com o primeiro valor (A): ");
    scanf("%d", &a);
    printf("Entre com o segundo valor (B): ");
    scanf("%d", &b);
    if (a ==0 & b==0)
    ab = 0;
    else
    ab=1;
    if(a!=0 || b!=0)
    aorb = 1;
    else
    aorb=0;
    if(a==0)
    nota = 1;
    else 
    nota = 0;
    if(a!=0 || b!=0 && !(a ==0 & b==0))
    axorb = 0;
    else
    axorb=1;
    printf("A and B: %d\n", ab);
    printf("A or B: %d\n", aorb);
    printf("A XOR B: %d\n", axorb);
    printf("not A: %d\n", nota);
    
}

