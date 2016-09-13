#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct cell_to_calc {
    int i;
    int j;
    int i_pos;
    int j_pos;
    int *arr;
    int *w;
};

void *check_for_one(void *param)
{
    struct cell_to_calc *item= param;
    int i_cell = item->i;
    int *arr = item->arr;
    int *w = item->w;

    if (w[i_cell]) {
        printf("Maximum = %d\n", arr[i_cell]);
        printf("Location = %d\n", i_cell);
    }

    pthread_exit(0);
}

void *greater_cell(void *param)
{
    struct cell_to_calc *item= param;
    int i_cell = item->i;
    int j_cell = item->j;
    int i_pos= item->i_pos;
    int j_pos= item->j_pos;

    if(i_cell>j_cell) {
        item->arr[j_pos] = 0;
        printf("Thread T(%d,%d) compares x[%d] = %d and x[%d] = %d, and writes 0 into w[%d]\n", i_pos, j_pos, i_pos, i_cell, j_pos, j_cell, j_pos);
    } else {
        item->arr[i_pos] = 0;
        printf("Thread T(%d,%d) compares x[%d] = %d and x[%d] = %d, and writes 0 into w[%d]\n", i_pos, j_pos, i_pos, i_cell, j_pos, j_cell, i_pos);
    }

    pthread_exit(0);
}

int *thread_compare(int *arr, int length)
{
    int *w = malloc(sizeof(int)*length);
    for (int i=0; i < length; ++i)
        w[i] = 1;

    printf("After initialization w =");
    for (int i=0;i<length;++i) {
        printf(" %d", w[i]);
    }
    printf("\n");

    for (int i=0; i < length; ++i) {
        for (int j=i+1; j < length; ++j) {
            if (arr[i] > arr[j])
                w[j] = 0;
            else
                w[i] = 0;
        }
    }

    return w;
}

int main(int argc, char const *argv[])
{
    int length = argc-1;

    int *arr = malloc(sizeof(int)*length);

    for (int i=0;i<length;++i) {
        arr[i] = atoi(argv[i+1]);
    }

    printf("Number of input values = %d\n", length);
    printf("Input values x = ");
    for (int i=0;i<length;++i) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    int *w = thread_compare(arr, length);
    printf("After Step 2\n");
    printf("w = ");
    for (int i=0;i<length;++i) {
        printf("%d ", w[i]);
    }
    printf("\n");


    for (int i=0; i < length; ++i) {
        if (w[i]) {
            printf("Maximum = %d\n", arr[i]);
            printf("Location = %d\n", i);
        }
    }

    free(w);
    free(arr);
    return 0;
}
