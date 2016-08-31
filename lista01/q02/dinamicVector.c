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

/* int main(){ */
/*   array collection = init_array(); */
/*   collection = push_back(&collection,1); */
/*   collection = push_back(&collection,2); */
/*   collection = push_back(&collection,3); */
/*   print_collection(collection); */
/* } */
