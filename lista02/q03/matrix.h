#ifndef MATRIX_H
#define MATRIX_H

struct matrix_multiply_member {
    int rows;
    int cols;
    int **content;
    int i;
    int j;
    int **A;
    int **B;
};

struct matrix {
    int cols;
    int rows;
    int **content;
};

void clear_matrix(struct matrix *mtrx);
void alloc_matrix(struct matrix *mtrx);
void print_matrix(int rows, int cols, int **mtrx);

#endif
