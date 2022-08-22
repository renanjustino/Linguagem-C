#include <stdlib.h>
#include <stdio.h>
#include "TMat2D.h"

struct TMat2D
{
  int nrows; // número de linhas
  int ncolumns; // número de colunas
  double *data; // ponteiro para os dados da matriz
};

// mat = mat2D_create(4,3);

TMat2D *mat2D_create(int nrows, int ncolumns){
    TMat2D *mat;
    mat = malloc(sizeof(TMat2D));
    if (mat != NULL){
        mat->data = malloc(nrows*ncolumns*sizeof(double));
        if (mat->data != NULL){
            mat->ncolumns = ncolumns;
            mat->nrows = nrows;
        } else {
            free(mat);
            return NULL;
        }
    }
    return mat;
}

int mat2D_destroy(TMat2D *mat){
    if(mat == NULL){
        return -1;
    }
    else if(mat->data == NULL){
        free(mat);
        return -2;
    }
    else{
        free(mat->data);
        free(mat);
        return 0;
    }
}

int mat2D_set_value(TMat2D *mat, int nrows, int ncolumns, double val){
    if(mat == NULL){
        return -1;
    }
    else if(nrows <= 0 || nrows > mat->nrows || ncolumns <= 0 || ncolumns > mat->ncolumns){
        return -2;
    }
    else{
        mat->data[(nrows - 1) + ((ncolumns - 1) * mat->nrows)] = val;
        return 0;
    }
}

int mat2D_get_value(TMat2D *mat, int nrows, int ncolumns, double *val){
    double valor;
    if(mat == NULL){
        return -1;
    }
    
    else if(nrows <= 0 || nrows > mat->nrows || ncolumns <= 0 || ncolumns > mat->ncolumns){
        return -2;
    }
    else{
       valor = mat->data[(nrows - 1) + ((ncolumns - 1) * mat->nrows)];
       *val = valor;
       return 0;
    }
}

int mat2D_rand_value(TMat2D *mat, int nrows, int ncolumns, double max_value, double min_value){
  int count;
  srand(time(NULL));
  if(nrows <= 0 || nrows != mat->nrows || ncolumns <= 0 || ncolumns != mat->ncolumns){
   return -1;
  }
  else if(mat == NULL){
       return -2;
  }
  else{
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
        count = 0;
        while(count != 1){
          if(((rand()/(double)RAND_MAX)*100) > min_value && ((rand()/(double)RAND_MAX)*100) < max_value){
            mat->data[i + (j * mat->nrows)] = (rand()/(double)RAND_MAX)*100;
            count = 1;
          }
        }
      }
    }
    return 0;
  }
}

int mat2D_sum(TMat2D *mat, TMat2D *mat2, TMat2D *mat_sum, int nrows, int ncolumns){
  if(nrows <= 0 || nrows != mat->nrows || ncolumns <= 0 || ncolumns != mat->ncolumns || nrows != mat2->nrows || ncolumns != mat2->ncolumns || nrows != mat_sum->nrows || ncolumns != mat_sum->ncolumns){
    return -2;
  }
  else if(mat == NULL || mat2 == NULL ||mat_sum == NULL){
        return -1;
  }
  else{
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
         mat_sum->data[i + (j * mat_sum->nrows)] =  mat->data[i + (j * mat->nrows)] +  mat2->data[i + (j * mat2->nrows)];
      }
    }
    return 0;
  }
}

int mat2D_const_mult(TMat2D *mat, int nrows, int ncolumns, int constant){
  if(nrows <= 0 || nrows != mat->nrows || ncolumns <= 0 || ncolumns != mat->ncolumns){
    return -2;
  }
  else if(mat == NULL){
        return -1;
  }
  else{
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
        mat->data[i + (j * mat->nrows)] = mat->data[i + (j * mat->nrows)] * constant;
      }
    }
    return 0;
  }
}

int mat2D_mat_mult(TMat2D *mat, TMat2D *mat2, TMat2D *mat_sum, int nrows, int ncolumns){
  int  aux;
  if(mat->ncolumns != mat2->nrows){
    return -3;
  }
  else if(nrows <= 0 || nrows != mat->nrows || ncolumns <= 0 || ncolumns != mat->ncolumns || nrows != mat2->nrows || ncolumns != mat2->ncolumns || nrows != mat_sum->nrows || ncolumns != mat_sum->ncolumns){
    return -1;
  }
  else if(mat == NULL || mat2 == NULL ||mat_sum == NULL){
        return -2;
  }
  else{
    aux = mat->ncolumns;
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
        mat_sum->data[i + (j * mat->nrows)] = 0.0;
        for(int k = 0; k < aux; k++){
          if(i + k < aux && j + k < aux){
            mat_sum->data[i + (j * mat->nrows)] = mat_sum->data[i + (j * mat->nrows)] + (mat->data[i + ((j + k) * mat->nrows)] * mat2->data[(i + k) + (j * mat->nrows)]);
          }
        }
      }
    }
    return 0;
  }
}

int mat2D_traco(TMat2D *mat, int nrows, int ncolumns, double *traco){
  double valor = 0.0;
  if(mat == NULL){
    return -1;
  }
  else if(nrows <= 0 || nrows > mat->nrows || ncolumns <= 0 || ncolumns > mat->ncolumns){
    return -2;
  }
  else if(ncolumns != nrows){
    return -3;
  }
  else{
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
        if(i == j){
          valor = valor + mat->data[i + (j * mat->nrows)];
        }
      }
    }
    *traco = valor;
    return 0;
  }
    
}

int mat2D_sum_rows(TMat2D *mat, int nrows, int ncolumns, double *sum){
  double *vet;
  vet = (double *)malloc(nrows * sizeof(double));
  if(mat == NULL){
    free(vet);
    return -1;
  }
  else if(nrows <= 0 || nrows > mat->nrows || ncolumns <= 0 || ncolumns > mat->ncolumns){
    free(vet);
    return -2;
  }
  else{
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
        vet[i] = vet[i] + mat->data[i + (j * mat->nrows)];
      }
    }
    sum = vet;
    return 0;
  }
}

int mat2D_sum_columns(TMat2D *mat, int nrows, int ncolumns, double *sum){
  double *vet;
  vet = (double *)malloc(ncolumns * sizeof(double));
  if(mat == NULL){
    free(vet);
    return  -1;
  }
  else if(nrows <= 0 || nrows > mat->nrows || ncolumns <= 0 || ncolumns > mat->ncolumns){
    free(vet);
    return  -2;
  }
  else{
    for(int i = 0; i < nrows; i++){
      for(int j = 0; j < ncolumns; j++){
        vet[j] = vet[j] + mat->data[i + (j * mat->nrows)];
      }
    }
    sum = vet;
    return 0;
  }
}