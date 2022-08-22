#include <stdio.h>
#include <stdlib.h>
#include <math.h>

   int main()
{
    int n, i;
    printf("<<Contagem progressiva ate 0>>\n");
    printf("Qual eh o numero inicial?: ");
    scanf("%d", &n);
    printf("\n");
    for(i=n; i<=0; i++)
    {
        printf("%d..", i);
    }

    printf("FIM!");

    return 0;
}

