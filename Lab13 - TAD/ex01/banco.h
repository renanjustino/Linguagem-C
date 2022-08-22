typedef struct banco banco;

struct banco {
    char nome[30];
    float saldo;
    int numConta;
};

float altera_saldo(banco *banco, float valor);
