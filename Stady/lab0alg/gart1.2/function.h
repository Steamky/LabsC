#ifndef FUNCTION_H
#define FUNCTION_H

void generate_matrix(int rows, int cols, double **matrix);
void write_matrix_to_file(FILE *file, int rows, int cols, double **matrix);
void read_matrix_from_file(const char *filename, int rows, int cols, double **matrix);
void add_matrices(int rows, int cols, double **matrix1, double **matrix2, double **result);
void multiply_matrices(int rows1, int cols1, int rows2, int cols2, double **matrix1, double **matrix2, double **result);
void print_matrix_to_file(FILE *file, int rows, int cols, double **matrix);

#endif // FUNCTION_H
