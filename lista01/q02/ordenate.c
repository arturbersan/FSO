#include "ordenate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dinamicVector.h"
#include"treatParameters.h"

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
