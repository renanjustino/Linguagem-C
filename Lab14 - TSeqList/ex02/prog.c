#include <stdio.h>
#include <stdlib.h>
#include "TVarSeqList.h"

int main()
{
    struct aluno a[4] = {{2,"Andre",9.5  ,7.8  ,8.5  },{4,"Ricardo",7.5,8.7,6.8},{1,"Bianca",9.7  ,6.7  ,8.4},{3,"Ana",5.7  ,6.1,7.4}};
    struct aluno b = {5,"Renan", 1.0,2.0,3.0};
    Lista *li   = cria_lista(4);
    int i;
    for(i=0; i < 4; i++)
    insere_lista_ordenada(li,a[i]);
    imprime_lista(li);
    insere_lista_ordenada(li, b);
    imprime_lista(li);
    compactar_lista(li);
    libera_lista(li);
    return 0;
}
