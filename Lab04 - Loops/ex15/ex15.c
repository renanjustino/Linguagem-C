#include <stdio.h>
#include <stdlib.h>
#include <math.h>

   int main()
{
    int n, s, s1, i, a, b, c, d;
    a=b=c=d=s=s1=0;
    printf("<<Conversor binario-decimal>>");
    printf("\nEntre com o numero de bits: ");
    scanf("%d", &n);
    if(n>4)
        printf("Calculadora exclusiva para 4 bits apenas");
    else if(n==4)
    {
        printf("\nDigite o bit #1: ");
        scanf("%d", &a);
        printf("\nDigite o bit #2: ");
        scanf("%d", &b);
        printf("\nDigite o bit #3: ");
        scanf("%d", &c);
        printf("\nDigite o bit #4: ");
        scanf("%d", &d);
    }
    else if(n==3)
    {
        printf("\nDigite o bit #1: ");
        scanf("%d", &b);
        printf("\nDigite o bit #2: ");
        scanf("%d", &c);
        printf("\nDigite o bit #3: ");
        scanf("%d", &d);
    }
    else if(n==2)
    {
        printf("\nDigite o bit #1: ");
        scanf("%d", &c);
        printf("\nDigite o bit #2: ");
        scanf("%d", &d);
    }
    else
    {
        printf("\nDigite o bit #1: ");
        scanf("%d", &d);
    }
    s1=(a*pow(10, 3))+(b*pow(10, 2))+(c*pow(10, 1))+(d*pow(10, 0));
    s=(a*8)+(b*4)+(c*2)+(d*1);
    printf("O numero binario %d em decimal eh %d", s1, s);

    return 0;
}

