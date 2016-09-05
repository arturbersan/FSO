#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include <pthread.h>

void* calc_cell(void * arg)
{
    struct matrix_multiply_member* member = arg;

    int i = member->i;
    int j = member->j;

    for (int k=0; k < member->cols; ++k) {
        member->content[i][j] += member->A[i][k]*member->B[k][j];
    }

    pthread_exit(0);
}

int main(int argc, char const *argv[])
{
    /* get num of threads to be used */
    char buf[256];
    snprintf(buf, sizeof(buf), "cat < /proc/cpuinfo | grep -c processor > num_of_threads");
    system(buf);
    FILE *fp = fopen("num_of_threads", "r");
    int proc_num = 1;
    fscanf(fp, "%d", &proc_num);
    fclose(fp);
    printf("Num of threads to be used: %d\n", proc_num);

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
        pthread_t *threads_vector = malloc(rows_A*cols_B*sizeof(pthread_t*));

        struct matrix_multiply_member **cells = malloc(rows_A*cols_B*sizeof(struct matrix_multiply_member*));;
        int ptr=0;
        int threads_supervisor = 0;
        for (int i=0; i < rows_A; ++i) {
            for (int j=0; j < cols_B; ++j) {
                if (threads_supervisor == proc_num) {
                    for (int w=ptr-1; w>=ptr-4; w--) {
                        pthread_join(threads_vector[i], NULL);
                    }
                    threads_supervisor = 0;
                }
                cells[ptr] = malloc(sizeof(struct matrix_multiply_member));
                cells[ptr]->cols = cols_A;
                cells[ptr]->rows = rows_B;
                cells[ptr]->content = AxB.content;
                cells[ptr]->A = A.content;
                cells[ptr]->B = B.content;
                cells[ptr]->i = i;
                cells[ptr]->j = j;
                pthread_create(&threads_vector[ptr], NULL, &calc_cell, (void *)cells[ptr]);
                threads_supervisor++;
                ptr++;
            }
        }

        /* wait for threads to finish */
        int last_thread_index = ptr-threads_supervisor;
        for (int w=ptr-1; w>=last_thread_index; w--) {
            pthread_join(threads_vector[w], NULL);
        }
        for (int i=0; i < ptr; ++i) {
            free(cells[i]);
        }

        printf("A:\n");
        print_matrix(rows_A, cols_A, A.content);
        printf("B:\n");
        print_matrix(rows_B, cols_B, B.content);
        printf("AxB:\n");
        print_matrix(rows_A, cols_B, AxB.content);

        /* free stuff */
        free(cells);
        free(threads_vector);
        clear_matrix(&A);
        clear_matrix(&B);
        clear_matrix(&AxB);

    }
    return 0;
}
