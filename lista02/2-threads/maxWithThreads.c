#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"dinamicVector.h"
#include"maxWithThreads.h"

void * thread_w_body(void * param)
{
  int *prm = (int*)param;
  *prm=1;
}

void * thread_compare_body(void * param)
{
  int *prm = (int*)param;
  *prm=0;
}

void * bigger_number_body(void * param)
{
  int prm = *((int*)param);
  printf("Bigest number is =  %d\n",prm);
}

int * init_array_w(int argc)
{
  int size_array_w = argc-1;
  int *w = malloc(sizeof(int)*size_array_w);
  pthread_t *thread = (pthread_t *) malloc(sizeof(pthread_t)*size_array_w);
  int i;
  for(i=0;i<size_array_w;i++){
    pthread_create(&thread[i], NULL, thread_w_body, &w[i]);
  }
  for(i=0;i<size_array_w;i++){
    pthread_join (thread[i], NULL);
  }

  return w;
}

int * thread_compare(int argc,char **argv)
{
  int size_array_compare = ((argc-1)*(argc-2))/2;
  pthread_t *thread = (pthread_t *) malloc(sizeof(pthread_t)*size_array_compare);
  int *w = init_array_w(argc);
  int i,j;
  printf("w antes\n");
  for(i=0;i<argc-1;i++){
    printf("%d\n",w[i]);
  }
  array collection = parse_string_to_int(argc,argv);
  print_collection(collection);
  for(i=0;i<argc-1;i++){
    for(j=i+1;j<argc-1;j++){
      if(collection.content[i]>collection.content[j])
        pthread_create(&thread[j], NULL, thread_compare_body, &w[j]);
      else
        pthread_create(&thread[i], NULL, thread_compare_body, &w[i]);
    }
  }
  printf("w depois\n");
  for(i=0;i<argc-1;i++){
    printf("%d\n",w[i]);
  }
  for(i=0;i<size_array_compare;i++){
    pthread_join (thread[i], NULL);
  }

  return w;
}

void get_bigger_number(int argc, char ** argv)
{
  int size_of_thread = argc-1;
  array collection = parse_string_to_int(argc,argv);
  int *w = thread_compare(argc,argv);
  int i;
  pthread_t *thread = (pthread_t *) malloc(sizeof(pthread_t)*size_of_thread);
  for(i=0;i<size_of_thread;i++){
    if(w[i])
      pthread_create(&thread[i], NULL, bigger_number_body, &collection.content[i]);
  }

}

int main(int argc,char **argv)
{
  if(argc>1){
    get_bigger_number(argc,argv);
  } else {
    printf("This program needs more parameters\n");
  }
  return 0;
}

