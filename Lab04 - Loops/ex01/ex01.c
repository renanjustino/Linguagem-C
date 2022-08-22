#include <stdio.h>
#include <stdlib.h>
#include <math.h>

   int main()
{
    int n;
    n = 10;
    printf("<<Contagem regressiva>>\n");
    while(n>=0)
    {
        printf("%d..", n);
        n=n-1;
    }

    printf("FIM!");

    return 0;
}

