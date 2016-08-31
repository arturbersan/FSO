#ifndef MAX_WITH_THREADS
#define MAX_WITH_THREADS

int *  init_array_w(int argc);
int * thread_compare(int argc,char **argv);
void get_bigger_number(int argc, char ** argv);

void * thread_w_body(void * param);
void * thread_compare_body(void * param);
void * bigger_number_body(void * param);

struct w_struct {
  int *result;
  int i_cell;
  int j_cell;
  int i_position;
  int j_position;
};

#endif
