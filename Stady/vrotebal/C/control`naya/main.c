#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

double **allocate_matrix(int rows, int cols) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows1, cols1, rows2, cols2;
    clock_t start, end;
    double time_used;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    start = clock();

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible with the given dimensions.\n");
        return -1;
    }

    srand(time(NULL));

    double **matrix1 = allocate_matrix(rows1, cols1);
    double **matrix2 = allocate_matrix(rows2, cols2);
    double **sum = allocate_matrix(rows1, cols1);
    double **product = allocate_matrix(rows1, cols2);

    generate_matrix(rows1, cols1, matrix1);
    generate_matrix(rows2, cols2, matrix2);

    printf("Matrix1:\n");
    for (int i=0; i < rows1; i++) {
        for (int k=0; k < cols1; k++){
            printf("%d ", (int)matrix1[i][k]);
        }
        printf("\n");
    }
    printf("Matrix2:\n");
     for (int i=0; i < rows2; i++) {
        for (int k=0; k < cols2; k++){
            printf("%d ", (int)matrix2[i][k]);
        }
        printf("\n");
    }

    FILE *input = fopen("input.txt", "w");
    write_matrix_to_file(input, rows1, cols1, matrix1);
    fprintf(input, "\n"); 
    write_matrix_to_file(input, rows2, cols2, matrix2);
    fclose(input);

    FILE *output = fopen("output.txt", "w");

    add_matrices(rows1, cols1, matrix1, matrix2, sum);
    multiply_matrices(rows1, cols1, rows2, cols2, matrix1, matrix2, product);
    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    fprintf(output, "Sum matrix:\n");
    print_matrix_to_file(output, rows1, cols1, sum);

    fprintf(output, "Multiplication matrix:\n");
    print_matrix_to_file(output, rows1, cols2, product);

    fprintf(output, "Time taken for matrix operations: %f seconds\n", time_used);

    fclose(output);

    free_matrix(matrix1, rows1);
    free_matrix(matrix2, rows2);
    free_matrix(sum, rows1);
    free_matrix(product, rows1);

    printf("Matrix operations completed and written to output.txt.\n");
    printf("Time taken for matrix operations: %f seconds\n", time_used);

    return 0;
}
