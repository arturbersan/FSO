#include "matrix.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_matrix(struct matrix *mtrx)
{
    for (int i=0;i<mtrx->rows;++i)
        free(mtrx->content[i]);
    free(mtrx->content);
}

void alloc_matrix(struct matrix *mtrx)
{

    int *cel = (int*)malloc(mtrx->cols*sizeof(int));
    mtrx->content = (int**)malloc(mtrx->rows*sizeof(cel));
    memset(mtrx->content, 0, sizeof(mtrx->content));
    for (int i=0;i<mtrx->rows;i++) {
        mtrx->content[i] = (int*)malloc(mtrx->rows*sizeof(cel));
    }
    free(cel);
}

void print_matrix(int rows, int cols, int **mtrx)
{
    for (int i=0;i<rows;++i) {
        for (int j=0;j<cols;++j) {
            printf(" %d ", mtrx[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
