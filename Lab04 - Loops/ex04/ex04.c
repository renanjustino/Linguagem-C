#include <stdio.h>
#include <stdlib.h>
#include <math.h>

  int main()
{
    int n;
    printf("<<Contagem regressiva>>\n");
    printf("Qual eh o numero inicial? ");
    scanf("%d", &n);
    printf("\n");
    while(n>=0)
    {
        printf("%d..", n);
        n--;
    }

    printf("FIM!");

    return 0;
}

