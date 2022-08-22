#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct TMat2D TMat2D;

int rand(void);
TMat2D *mat2D_create(int nrows, int columns);
int mat2D_destroy(TMat2D *mat);
int mat2D_set_value(TMat2D *mat, int nrows, int ncolumns, double val);
int mat2D_get_value(TMat2D *mat, int nrows, int ncolumns, double *val);
int mat2D_rand_value(TMat2D *mat, int nrows, int ncolumns, double max_value, double min_value);
int mat2D_sum(TMat2D *mat, TMat2D *mat2, TMat2D *mat_sum, int nrows, int ncolumns);
int mat2D_mat_mult(TMat2D *mat, TMat2D *mat2, TMat2D *mat_sum, int nrows, int ncolumns);
int mat2D_traco(TMat2D *mat, int nrows, int ncolumns, double *traco);
int mat2D_sum_columns(TMat2D *mat, int nrows, int ncolumns, double *sum);
int mat2D_const_mult(TMat2D *mat, int nrows, int ncolumns, int constant);
int mat2D_sum_rows(TMat2D *mat, int nrows, int ncolumns, double *sum);
