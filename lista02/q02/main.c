#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "dinamicVector.h"

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

int *thread_compare(int argc, char **argv)
{
    int length = argc-1;
    int *w = reset_results(length);
    int m = length*(length-1)/2;
    pthread_t *threads_vector = (pthread_t *)malloc(sizeof(pthread_t)*m);
    array collection = parse_string_to_int(argc,argv);

    struct cell_to_calc *cells = malloc(sizeof(struct cell_to_calc)*(m));
    int ptr = 0;

    for (int i=0; i < length; ++i) {
        for (int j=i+1; j < length; ++j) {
            cells[ptr].i = collection.content[i];
            cells[ptr].j = collection.content[j];
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

int main(int argc, char **argv)
{
    int length = argc-1;

    int *w = thread_compare(argc, argv);
   array collection = parse_string_to_int(argc,argv);

    for (int i=0; i < length; ++i) {
        if (w[i])
            printf("Greatest number: %d\n", collection.content[i]);
    }

    free(w);
    return 0;
}
