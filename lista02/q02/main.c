#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *reset_position(void *param)
{
    int *cell = param;
    *cell = 1;
    pthread_exit(0);
}

int *reset_results(int length)
{
    int *w = malloc(sizeof(int)*length);
    pthread_t *threads_vector = (pthread_t *) malloc(sizeof(pthread_t)*length);
    for (int i=0;i<length;++i) {
        pthread_create(&threads_vector[i], NULL, &reset_position, &w[i]);
    }

    for (int i=0;i<length;i++){
        pthread_join(threads_vector[i], NULL);
    }
    free(threads_vector);

    return w;
}

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
    int *w = reset_results(length);
    printf("After initialization w =");
    for (int i=0;i<length;++i) {
        printf(" %d", w[i]);
    }
    printf("\n");

    int m = length*(length-1)/2;
    pthread_t *threads_vector = (pthread_t *)malloc(sizeof(pthread_t)*m);

    struct cell_to_calc *cells = malloc(sizeof(struct cell_to_calc)*(m));
    int ptr = 0;

    for (int i=0; i < length; ++i) {
        for (int j=i+1; j < length; ++j) {
            cells[ptr].i = arr[i];
            cells[ptr].j = arr[j];
            cells[ptr].i_pos = i;
            cells[ptr].j_pos = j;
            cells[ptr].arr = w;
            pthread_create(&threads_vector[ptr], NULL, greater_cell, (void *)&cells[ptr]);
            ptr++;
        }
    }

    for (int i=0; i < m; ++i) {
        pthread_join(threads_vector[i], NULL);
    }

    free(cells);
    free(threads_vector);
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


    pthread_t *threads_vector = (pthread_t *)malloc(sizeof(pthread_t)*length);
    struct cell_to_calc *cells = malloc(sizeof(struct cell_to_calc)*(length));

    int *num_to_calc = malloc(sizeof(int)*length);
    for (int i=0; i < length; ++i) {
        num_to_calc[i] = i;
    }

    for (int i=0; i < length; ++i) {
        cells[i].arr = arr;
        cells[i].w = w;
        cells[i].i = num_to_calc[i];
        pthread_create(&threads_vector[i], NULL, check_for_one, (void *)&cells[i]);
    }

    for (int i=0; i < length; ++i) {
        pthread_join(threads_vector[i], NULL);
    }

    free(num_to_calc);
    free(threads_vector);
    free(cells);

    free(w);
    free(arr);
    return 0;
}
