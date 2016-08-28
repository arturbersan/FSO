#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char const *argv[])
{
    int **A, **B, **AxB;
    int rows_A, rows_B, cols_A, cols_B;
    printf("Input is: rows of A matrix, cols of A matrix, rows of B matrix, cols of B matrix\n\n");
    while (scanf("%d%d%d%d", &rows_A, &cols_A, &rows_B, &cols_B) == 4) {
        /* allocates A matrix */
        int *cel;
        cel = (int*)malloc(cols_A*sizeof(int));
        A = (int**)malloc(rows_A*sizeof(cel));
        memset(A, 0, sizeof(A));
        for (int i=0;i<rows_A;i++) {
            A[i] = (int*)malloc(rows_A*sizeof(cel));
        }
        free(cel);

        /* allocates B matrix */
        cel = (int*)malloc(cols_B*sizeof(int));
        B = (int**)malloc(rows_B*sizeof(cel));
        memset(B, 0, sizeof (B));
        for (int i=0;i<rows_B;++i) {
            B[i] = (int*)malloc(rows_B*sizeof(cel));
        }
        free(cel);

        /* allocates AxB matrix */
        cel = (int*)malloc(cols_B*sizeof(int));
        AxB = (int**)malloc(rows_A*sizeof(int));
        memset(AxB, 0, sizeof AxB);
        for (int i=0;i<rows_A;++i) {
            AxB[i] = (int*)malloc(rows_A*sizeof(cel));
        }
        free(cel);

        /* get A matrix from IO */
        for (int i=0;i<rows_A;++i) {
            for (int j=0;j<cols_A;++j) {
                scanf("%d", &A[i][j]);
            }
        }

        /* get B matrix from IO */
        for (int i=0;i<rows_B;++i) {
            for (int j=0;j<cols_B;++j) {
                scanf("%d", &B[i][j]);
            }
        }

        /* calculates AxB */
        for (int i=0; i < rows_A; ++i) {
            for (int j=0; j < cols_B; ++j) {
                for (int k=0; k < cols_A; ++k) {
                    AxB[i][j] += A[i][k]*B[k][j];
                }
            }
        }

        printf("A:\n");
        print_matrix(rows_A, cols_A, A);
        printf("B:\n");
        print_matrix(rows_B, cols_B, B);
        printf("AxB:\n");
        print_matrix(rows_A, cols_B, AxB);

        free(A);
        free(B);
    }
    return 0;
}
