#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"dinamicVector.h"
#include"maxWithThreads.h"

void *init_vector_w(int argc){
  /* int *w = malloc(sizeof(int)*(argc-1*argc-2)/2); */
  int j,i;
  pthread_t *w = (pthread_t *) malloc(sizeof(pthread_t)*argc-1);
  for(i=0;i<argc-1;i++){
    int *arg = malloc(sizeof(*arg));
    if ( arg == NULL ) {
      fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
      exit(EXIT_FAILURE);
    }

    *arg = i;
    pthread_create(&w[i], NULL,init_with_i, arg);

  }
  for(j=0;j<argc-1;j++){
    pthread_join(w[j], NULL);
  }

}

void * init_with_i(void *args){
  int a = *((int *) args);
  printf("argc = %d\n", *((int *)args) );
  free(args);
}

int main(int argc, char** argv){

  init_vector_w(argc);
  /* if(argc>1){ */
  /*   array collection = parse_string_to_int(argc,argv); */
  /*   print_collection(collection); */
  /* } else { */
  /*   printf("This program needs more parameters\n"); */
  /* } */

  return 0;
}
