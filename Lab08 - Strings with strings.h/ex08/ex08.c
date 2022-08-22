#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
  char nome[30], cpf[14], estado[5], cidade[20], rg[14], endereco[50], cep[15];
  printf("Digite seu nome: ");
  fgets(nome, 30, stdin);
  printf("Digite seu CPF: ");
  fgets(cpf, 14, stdin);
  printf("Digite seu RG: ");
  fgets(rg, 14, stdin);
  printf("Digite seu endereco: ");
  fgets(endereco, 50, stdin);
  printf("Digite a cidade: ");
  fgets(cidade, 20, stdin);
  printf("Digite o estado: ");
  fgets(estado, 5, stdin);
  printf("Digite o CEP: ");
  fgets(cep, 15, stdin);
  printf("\n");
  printf("          Declaração          \n");
  printf("Eu, %s,RG %s,CPF %s,residente a %s,%s-%s,CEP %s venho por meio desta declarar que vou estudar para a prova", nome, rg, cpf, endereco, cidade, estado, cep);
  return 0;
}
