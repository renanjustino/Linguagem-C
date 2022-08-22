typedef struct banco banco;
banco *cria_conta(char *nome, float saldo, int numConta);
int destroi_conta(banco *b);
void imprime_conta(banco *b);
int get_banco_info(banco *b, char *nome, float *saldo, int *numConta);
float altera_saldo(banco *banco, float valor);
