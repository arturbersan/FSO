#include<stdio.h>
#include<math.h>
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
  struct w_struct node = node;
  int i_cell = node.i_cell;
  int j_cell = node.j_cell;
  int i_position = node.j_position;
  int j_position = node.j_position;

  if(i_cell>j_cell)
    node.result[j_position] = 0;
  else
    node.result[i_position] = 0;

  free(param);
  pthread_exit(0);
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

  free(thread);

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
      printf("PAssouz2222222\n");
      struct w_struct *cell = malloc(sizeof(struct w_struct));
      printf("PAssouz\n");
      cell->result = w;
      cell->i_cell = collection.content[i];
      cell->j_cell = collection.content[j];
      cell->j_position = i;
      cell->j_position = j;
      printf("PAssouz2222222\n");
      pthread_create(&thread[j], NULL, thread_compare_body, (void *)cell);
    }
  }
  printf("w depois\n");
  for(i=0;i<argc-1;i++){
    printf("%d\n",w[i]);
  }
  for(i=0;i<size_array_compare;i++){
    pthread_join (thread[i], NULL);
  }

  free(thread);

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

  free(thread);
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

