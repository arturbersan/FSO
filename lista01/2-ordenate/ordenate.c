#include "ordenate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dinamicVector.h"

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

int position_argv_array(char **string){
  if(string[1][0] == '-')
    return 2;
  else
    return 1;
}

array parse_string_to_int(int argc, char **argv){
  array collection = init_array();
  int i;

  for(i=position_argv_array(argv);i<argc;i++){
    collection = push_back(&collection, atoi(argv[i]));
  }

  return collection;
}

int decide_flag(int argc, char **argv){
  int flag = 0, arguments;
  while((arguments = getopt(argc,argv,"rd")) !=-1){
    switch(arguments){
      case 'r':
        flag = 1;
        break;
      case 'd':
        flag = 0;
        break;
      default:
        fprintf(stderr, "Usage: %s accepts the parameters '-r' and '-d'\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  return flag;
}

int main(int argc, char **argv){
  int vector[] = {4,1,2,4,9,1,12};
  int i;
  int flag = 0;
  if(argc>1){
    array collection = parse_string_to_int(argc,argv);
    printf("Array before: \n");
    print_collection(collection);
    flag = decide_flag(argc,argv);

    printf("Array after: \n");
    if(flag){
      reverse(collection.content, collection.last_item_index);
      print_collection(collection);
    } else {
      sort(collection.content, collection.last_item_index);
      print_collection(collection);
    }
  }else
    printf("This program needs more parameters\n");

  return 0;
}
