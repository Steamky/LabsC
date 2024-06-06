#include <stdio.h>
#include <time.h>
#include "matrix_io.h"
#include "matrix_operations.h"

int main() {
    double matrix1[100][100], matrix2[100][100];
    double matrix_sum[100][100], matrix_product[100][100];
    int n, m;

    clock_t start_time = clock();

    create_matrices_file();
    read_matrices_from_file(matrix1, matrix2, &n, &m);

    add_matrices(matrix1, matrix2, matrix_sum, n, m);
    multiply_matrices(matrix1, matrix2, matrix_product, n, m);

    write_matrices_to_file(matrix_sum, matrix_product, n, m);

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("time running program: %f second\n", elapsed_time);

    return 0;
}
