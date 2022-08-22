#include <stdio.h>
#include <string.h>
int main(void){ char buff[5];     int pass = 0;     printf("\n Entre com a senha : \n"); gets(buff);     if (strcmp(buff, "1234"))  { printf ("\n Senha Errada \n");     }  else   {        printf ("\n Senha Correta \n");         pass = 1;     }    if (pass) {        /* O usuário acertou a senha, poderá continuar*/        printf ("\n Acesso liberado \n");     } else {         printf ("\n Acesso negado \n");     }    return 0; }

/* A - Função do programa é verificar se o usuário digita a senha de buff correta, que é 1234. se não é exibido senha errada. */

/* B - Senha correta, acesso liberado*/

/* C - a - 123 = senha errada acesso negado. b - 12345 = senha errada acesso negado. c - 123456 = senha errada acesso liberado.*/

/* D - para alternativa c, último caso, 123456, pois o buff estava reservado 5 posições na memória e foi digitado 6 no caso, mesmo não sendo a senha correta, houve violação da memoria e liberou o acesso pelo tamanho do array char 5 ser menor que o digitado 6*/