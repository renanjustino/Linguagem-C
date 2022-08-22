#include <stdio.h>
#include <stdlib.h>
#include <math.h>

   int main()
{
    int x, n, s;
    s = 0;
    printf("<<Soma de n valores naturais>>\n");
    printf("Quantos numeros deseja somar?: ");
    scanf("%d", &n);
    x=n;
    do
    {
        s=s+n;
        n--;
    }while(n>=0);

    printf("\nA soma dos %d primeiro(s) numero(s) natural(is) eh: %d", x, s);

    return 0;
}

