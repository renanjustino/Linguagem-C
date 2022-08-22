#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct endereco{
  char rua[50], complemento[50], cidade[20], estado[4], cep[11];
  int numero;
};

int main() {
  struct endereco enderecos[3];
  short teste = 0;
  short i,j;
	
  for(i = 0; i < 3; i++){
    printf("Rua: ");
    fgets(enderecos[i].rua, 50, stdin);
    printf("Número:  ");
    scanf("%d", &enderecos[i].numero, stdin);
    getchar();
    printf("Complemento:  ");
    fgets(enderecos[i].complemento, 50, stdin);
    printf("Cidade: ");
    fgets(enderecos[i].cidade, 20, stdin);
    printf("Estado: ");
    fgets(enderecos[i].estado, 4, stdin);
    printf("CEP: ");
    fgets(enderecos[i].cep, 11, stdin);
	printf("\n");
  }
  
  printf("Endereços cadastrados que são de “MG”: \n");
  for(i = 0; i < 3; i++){
    for(j = 0; j < 2; j++){
      if(j == 0 && enderecos[i].estado[j] != 'M'){
        teste++;
      }
      else if(j == 1 && enderecos[i].estado[j] != 'G'){
        teste++;
      }
    }
    if(teste == 0){
      printf("%s, %d. %s. %s-%s, %s. ", enderecos[i].rua, enderecos[i].numero, enderecos[i].complemento, enderecos[i].cidade, enderecos[i].estado, enderecos[i].cep);
    }
    teste = 0;
  }
  return 0;
}
/*
3) Crie uma estrutura chamada endereco, que armazena Rua, Número, Complemento,
Cidade, Estado e CEP (ilustração abaixo).  
Cadastre 3 endereços. Mostre ao final, todos os dados dos endereços cadastrados que são do estado “MG”

Endereco*
+------------+------------+---------------+
| Rua        | Número     |  Complemento  |    
+------------+------------+---------------+
| Cidade     | Estado     |     CEP       | 
+------------+------------+---------------+


-------------------------------------------------------------------------------
Exemplo de saída:
Rua: Joao
Numero: 32
Complemento: casa A
Cidade: Uberlandia
Estado: MG
CEP: 38400034


Rua: Almeida
Numero: 43
Complemento: Sem
Cidade: Araguari
Estado: MG
CEP: 38400045


Rua: Coronel Pedro
Numero: 25
Complemento: apto 40
Cidade: Caldas Novas
Estado: GO
CEP: 75780023


Enderecos cadastrados que sao de "MG":
Joao, 32. casa A. Uberlandia-MG, 38400034.
Almeida, 43. Sem. Araguari-MG, 38400045.
-------------------------------------------------------------------------------
*/