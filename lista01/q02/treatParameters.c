#include "ordenate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dinamicVector.h"
#include"treatParameters.h"

int position_argv_array(char **argv){
  if(argv[1][0] == '-')
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
