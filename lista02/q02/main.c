#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

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
};

void *greater_cell(void *param)
{
    struct cell_to_calc *item= param;
    int i_cell = item->i;
    int j_cell = item->j;
    int i_pos= item->i_pos;
    int j_pos= item->j_pos;

    if(i_cell>j_cell)
        item->arr[j_pos] = 0;
    else
        item->arr[i_pos] = 0;

    pthread_exit(0);
}

int *thread_compare(int *arr, int length)
{
    int *w = reset_results(length);
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
    int length;

    while (scanf("%d", &length)==1) {
        int *arr = malloc(sizeof(int)*length);
        for (int i=0;i<length;++i) {
            scanf("%d", &arr[i]);
        }

        int *w = thread_compare(arr, length);

        for (int i=0; i < length; ++i) {
            if (w[i])
                printf("Greatest number: %d\n", arr[i]);
        }

        free(w);
        free(arr);
    }
    return 0;
}
