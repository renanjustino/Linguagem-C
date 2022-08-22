#include <stdio.h>
#include <stdlib.h>
#include <math.h>

   int main()
{
    int n, contador, i;
    contador=0;
    printf("<<Numeros Primos>>");
    printf("\nEntre com o valor: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
            contador=contador+1;
    }
    if(contador<=2)
        printf("O numero %d eh primo", n);
    else
        printf("O numero %d nao eh primo", n);

    return 0;
}

