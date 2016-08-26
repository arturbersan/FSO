#include "ordenate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dinamicVector.h"
#include"treatParameters.h"

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
