#ifndef MATRIX_IO_H
#define MATRIX_IO_H

void create_matrices_file();
void read_matrices_from_file(double matrix1[100][100], double matrix2[100][100], int *n, int *m);
void write_matrices_to_file(double matrix_sum[100][100], double matrix_product[100][100], int n, int m);

#endif
