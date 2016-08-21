#include "ordenate.h"
#include <stdio.h>
#include <stdlib.h>

void sort(int vector[], int vector_size){
  int i, j, temporary;

  for (i=0;i<(vector_size-1);++i){
    for (j=0;j<vector_size-1-i;++j){
      if (vector[j]>vector[j+1]){
        temporary = vector[j+1];
        vector[j+1] = vector[j];
        vector[j] = temporary;
      }
    }
  }
}

void reverse(int vector[], int vector_size){
  int i, j, temporary;

  for (i=0;i<(vector_size-1);++i){
    for (j=0;j<vector_size-1-i;++j){
      if (vector[j]<vector[j+1]){
        temporary = vector[j+1];
        vector[j+1] = vector[j];
        vector[j] = temporary;
      }
    }
  }
}


int main(int argc, char **argv){
  int vector[] = {4,1,2,4,9,1,12};
  int vector1[] = {4,1,2,4,9,1,12};
  int i;
  int arguments, flag = -1;


  while((arguments = getopt(argc,argv,"rd")) !=-1){
    switch(arguments){
      case 'r':
        flag = 1;
        break;
      case 'd':
        flag = 2;
        break;
      default:
        fprintf(stderr, "Usage: %s accepts the parameters '-r' and '-d'\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  if(flag==1){
    reverse(vector, 7);
    for(i=0;i<7;i++)
      printf("%d, %d\n",i,vector[i]);
  } else {
    sort(vector1, 7);
    for(i=0;i<7;i++)
      printf("%d, %d\n",i,vector1[i]);
  }

  return 0;
}
