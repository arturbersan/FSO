#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int length = argc-2;

    int *arr = malloc(sizeof(int)*length);

    for (int i=0;i<length;++i) {
        arr[i] = atoi(argv[i+2]);
    }
    int max = arr[0];
    for (int i=0;i<length;++i) {
        if(arr[i] > max)
            max = arr[i];
    }
    printf("Maximum = %d\n", max);

    free(arr);
    return 0;
}
