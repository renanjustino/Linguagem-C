#include "banco.h"

float altera_saldo(banco *banco, float valor){
    banco->saldo = banco->saldo + valor;
    return 0;
}

