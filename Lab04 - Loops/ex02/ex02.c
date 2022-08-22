#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    int main()
{
    int n;
    n = 10;
    printf("<<Contagem regressiva>>\n");
    do
    {
        printf("%d..", n);
        n=n-1;
    }while(n>=0);

    printf("FIM!");

    return 0;
}

