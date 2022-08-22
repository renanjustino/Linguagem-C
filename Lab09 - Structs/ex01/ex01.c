#include <stdio.h>

struct telefone {
char ddd[3];
char telefone[9];
};

int main(){
	int i;
	struct telefone tel[3];
    printf("Telefone **\n");
	for(i=0;i<3;i++){
		printf("Digite o DDD: ");
		scanf("%s", tel[i].ddd);
		printf("Digite o telefone: ");
		scanf("%s", tel[i].telefone);
	}
	printf("Telefones Cadastrados: \n");
	for(i=0;i<3;i++){
		printf("%s %s \n", tel[i].ddd, tel[i].telefone);
	}
    return 0;
}

/*
1) Crie uma estrutura chamada telefone, que armazena o DDD e o telefone (ilustração abaixo).  
Cadastre 3 telefones e mostre na tela os telefones cadastrados. 

Telefone**
+------------+------------+
| DDD        | Telefone   |  
+------------+------------+

-------------------------------------------------------------------------------
Exemplo de saída:
Digite o DDD: 34
Digite o telefone: 991501111
Digite o DDD: 31
Digite o telefone: 991502222
Digite o DDD: 64
Digite o telefone: 991503333

Telefones cadastrados: 
34 991501111
31 991502222
64 991503333
-------------------------------------------------------------------------------
*/