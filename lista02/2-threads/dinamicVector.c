#include<stdio.h>
#include<stdlib.h>
#include"dinamicVector.h"

array push_back(array *collection,int item)
{
  if(collection->last_item_index+1 == collection->length){
    int *new_collection = malloc(sizeof(int)*(collection->length)*2);
    collection->length*=2;
    int i;
    for(i=0;i<collection->last_item_index;i++){
      new_collection[i] = collection->content[i];
    }
    int *aux = collection->content;
    collection->content = new_collection;
    free(aux);
  }
  collection->content[collection->last_item_index] = item;
  collection->last_item_index++;

  return *collection;
}

array init_array(){
  array collection;
  collection.length = 1;
  collection.last_item_index = 0;
  collection.content = (int*)malloc(sizeof(int));

  return collection;
}

void print_collection(array collection){
  int i;
  for(i=0;i<collection.last_item_index;i++){
    printf("%d = %d\n",i,collection.content[i]);
  }
}

array parse_string_to_int(int argc, char **argv){
  array collection = init_array();
  int i;

  for(i=1;i<argc;i++){
    collection = push_back(&collection, atoi(argv[i]));
  }

  return collection;
}

/* int main(int argc, char** argv){ */
/*   if(argc>1){ */
/*     array collection = parse_string_to_int(argc,argv); */
/*     print_collection(collection); */
/*   } else { */
/*     printf("This program needs more parameters\n"); */
/*   } */
/*  */
/*   return 0; */
/* } */
