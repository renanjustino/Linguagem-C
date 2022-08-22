#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 int main()
{
    int n, i, j, h, g, f;
    g=0;
    printf("<<Multiplos>>");
    printf("\nEntre com o valor de n: ");
    scanf("%d", &n);
    printf("\nEntre com o valor de i: ");
    scanf("%d", &i);
    printf("\nEntre com o valor de j: ");
    scanf("%d", &j);
    printf("\nOs multiplos de i ou j sao: ");
    for(h=0; h<n; h++)
        {
            f=0;
            while(f==0)
            {
                if(g%i==0)
                {
                    printf("%d,", g);
                    f=1;
                }
                else if(g%j==0)
                    {
                        printf("%d", g);
                        f=1;
                    }
                g++;
            }

        }

    return 0;
}

