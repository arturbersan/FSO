#ifndef DINAMIC_VECTOR
#define DINAMIC_VECTOR
typedef struct array{
  int length;
  int last_item_index;
  int *content;
} array;

array push_back(array *collection,int item);
array init_array();
void print_collection(array collection);

#endif
