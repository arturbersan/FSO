#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"dinamicVector.h"
#include"maxWithThreads.h"

void * thread_body (void * param)
{
  int *prm = (int*)param;
  *prm=1;
}

int main(int argc,char **argv){
  if(argc>1){
    int size_array_w = ((argc-1)*(argc-2))/2;

    int *w = malloc(sizeof(int)*size_array_w);
    pthread_t *thread = (pthread_t *) malloc(sizeof(pthread_t)*10);

    int i;
    for(i=0;i<size_array_w;i++){
      pthread_create(&thread[i], NULL, thread_body, &w[i]);
    }
    for(i=0;i<size_array_w;i++){
      pthread_join (thread[i], NULL);
    }
    for(i=0;i<size_array_w;i++){
      printf("%d\n",w[i]);
    }
    array collection = parse_string_to_int(argc,argv);
    print_collection(collection);
  } else {
    printf("This program needs more parameters\n");
  }
  return 0;
}

