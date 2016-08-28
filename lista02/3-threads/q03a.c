#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(int argc, char const *argv[])
{
    struct matrix A, B, AxB;
    int rows_A, rows_B, cols_A, cols_B;
    printf("Input is: rows of A matrix, cols of A matrix, rows of B matrix, cols of B matrix\n\n");
    while (scanf("%d%d%d%d", &rows_A, &cols_A, &rows_B, &cols_B) == 4) {
        A.rows = rows_A;
        A.cols = cols_A;
        B.rows = rows_B;
        B.cols = cols_B;
        AxB.cols = cols_B;
        AxB.rows = rows_A;

        int *cel;
        alloc_matrix(&A);
        alloc_matrix(&B);
        alloc_matrix(&AxB);

        /* get A matrix from IO */
        for (int i=0;i<rows_A;++i) {
            for (int j=0;j<cols_A;++j) {
                scanf("%d", &A.content[i][j]);
            }
        }

        /* get B matrix from IO */
        for (int i=0;i<rows_B;++i) {
            for (int j=0;j<cols_B;++j) {
                scanf("%d", &B.content[i][j]);
            }
        }


        /* calculates AxB */

        int ptr=0;
        for (int i=0; i < rows_A; ++i) {
            for (int j=0; j < cols_B; ++j) {
                for (int k=0; k < rows_B; ++k) {
                    AxB.content[i][j] += A.content[i][k]*B.content[k][j];
                }
            }
        }

        printf("A:\n");
        print_matrix(rows_A, cols_A, A.content);
        printf("B:\n");
        print_matrix(rows_B, cols_B, B.content);
        printf("AxB:\n");
        print_matrix(rows_A, cols_B, AxB.content);

        /* free stuff */
        clear_matrix(&A);
        clear_matrix(&B);
        clear_matrix(&AxB);

    }
    return 0;
}
