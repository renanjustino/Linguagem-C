#include <stdio.h>
#include <stdlib.h>
#include"TMat2D.h"

int main()
{
int ncolumns, nrows, i, j, constant;
    TMat2D *mat, *mat2, *mat_sum;
    double valor_set, valor_get, traco, *sum, soma;
    sum = &soma;
    printf("### MATRIZ 2D ###\n\n");
    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%d", &ncolumns);
    getchar();
    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%d", &nrows);
    getchar();
    mat = mat2D_create(nrows, ncolumns);
    mat2D_rand_value(mat, nrows, ncolumns, 100.0, 0.0);
    mat2 = mat2D_create(nrows, ncolumns);
    mat2D_rand_value(mat2, nrows, ncolumns, 100.0, 0.0);
    mat_sum = mat2D_create(nrows, ncolumns);
    printf("Informe o valor que voce deseja adicionar: ");
    scanf("%lf", &valor_set);
    printf("Informe a linha do valor que voce deseja adicionar: ");
    scanf("%d", &i);
    printf("Informe a coluna do valor que voce deseja adicionar: ");
    scanf("%d", &j);
    
    if(mat2D_set_value(mat, i, j, valor_set) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_set_value(mat, i, j, valor_set) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_set_value(mat, i, j, valor_set) == 0){
      printf("Numero escrito com sucesso!\n");
    }
    
    printf("Informe a linha do valor que voce deseja acessar: ");
    scanf("%d", &i);
    printf("Informe a coluna do valor que voce deseja acessar: ");
    scanf("%d", &j);
    
    if(mat2D_get_value(mat, i, j, &valor_get) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_get_value(mat, i, j, &valor_get) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_get_value(mat, i, j, &valor_get) == 0){
      printf("Numero acessado com sucesso!\n");
    }
    printf("O numero acessado foi: %.2lf\n", valor_get);
    
    if(mat2D_sum(mat, mat2, mat_sum, nrows, ncolumns) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_sum(mat, mat2, mat_sum, nrows, ncolumns) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_sum(mat, mat2, mat_sum, nrows, ncolumns) == 0){
      printf("Matrizes somadas com sucesso!\n");
    }
    
    if(mat2D_mat_mult(mat, mat2, mat_sum, nrows, ncolumns) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_mat_mult(mat, mat2, mat_sum, nrows, ncolumns) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_mat_mult(mat, mat2, mat_sum, nrows, ncolumns) == -3){
      printf("Quantidade de linha e colunas diferentes!\n");
    }
    else if(mat2D_mat_mult(mat, mat2, mat_sum, nrows, ncolumns) == 0){
      printf("Matrizes multiplicadas com sucesso!\n");
    }
    printf("Informe a constante para multiplicar a matriz: ");
    scanf("%d", &constant);
    
    if(mat2D_const_mult(mat, nrows, ncolumns, constant) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_const_mult(mat, nrows, ncolumns, constant) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_const_mult(mat, nrows, ncolumns, constant) == 0){
      printf("Matriz multiplicada com sucesso!\n");
    }
    
    if(mat2D_traco(mat, nrows, ncolumns, &traco) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_traco(mat, nrows, ncolumns, &traco) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_traco(mat, nrows, ncolumns, &traco) == -3){
      printf("Quantidade de linha e colunas diferentes!\n");
    }
    else if(mat2D_traco(mat, nrows, ncolumns, &traco) == 0){
      printf("Traço calculado com sucesso, com o valor: %.2lf!\n", traco);
    }
    
    if(mat2D_sum_rows(mat, nrows, ncolumns, sum) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_sum_rows(mat, nrows, ncolumns, sum) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_sum_rows(mat, nrows, ncolumns, sum) == 0){
      printf("Linha calculada com sucesso!\n");
    }
    
    if(mat2D_sum_columns(mat, nrows, ncolumns, sum) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_sum_columns(mat, nrows, ncolumns, sum) == -2){
      printf("Linha e/ou coluna invalida!\n");
    }
    else if(mat2D_sum_columns(mat, nrows, ncolumns, sum) == 0){
      printf("Coluna calculada com sucesso!\n");
    }
    
    if(mat2D_destroy(mat) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_destroy(mat) == -2){
      printf("Matriz com conteudo vazio destruida com sucesso!\n");
    }
    else if(mat2D_destroy(mat) == 0){
      printf("Matriz destruida com sucesso!\n");
    }
    
    if(mat2D_destroy(mat2) == -1){
      printf("Matriz vazia!\n");
    }
    else if(mat2D_destroy(mat2) == -2){
      printf("Matriz com conteudo vazio destruida com sucesso!\n");
    }
    else if(mat2D_destroy(mat2) == 0){
      printf("Matriz destruida com sucesso!\n");
    }
    
    mat2D_destroy(mat_sum);
    
    return 0;
}

