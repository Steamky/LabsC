#include "matrix_operations.h"

void add_matrices(double matrix1[100][100], double matrix2[100][100], double matrix_sum[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiply_matrices(double matrix1[100][100], double matrix2[100][100], double matrix_product[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_product[i][j] = 0;
            for (int k = 0; k < m; k++) {
                matrix_product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
