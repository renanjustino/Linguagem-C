#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, i;
    n = 10;
    printf("<<Contagem regressiva>>\n");
    for(i=0; i<10;i++)
    {
        printf("%d..", n);
        n=n-1;
    }

    printf("FIM!");

    return 0;
}

