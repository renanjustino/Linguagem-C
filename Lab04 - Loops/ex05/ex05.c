#include <stdio.h>
#include <stdlib.h>
#include <math.h>

   int main()
{
    int n;
    printf("<<Contagem regressiva>>\n");
    printf("Qual eh o numero inicial?: \n");
    scanf("%d", &n);
    printf("\n");
    do
    {
        printf("%d..", n);
        n--;
    }while(n>=0);

    printf("FIM!");

    return 0;
}

