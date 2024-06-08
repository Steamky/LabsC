#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void generate_matrix(int rows, int cols, double **matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; // Генератор
        }
    }
}

void write_matrix_to_file(FILE *file, int rows, int cols, double **matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%d ", (int)matrix[i][j]); 
        }
        fprintf(file, "\n");
    }
}

void read_matrix_from_file(const char *filename, int rows, int cols, double **matrix) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }
    fclose(file);
}

void add_matrices(int rows, int cols, double **matrix1, double **matrix2, double **result) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiply_matrices(int rows1, int cols1, int rows2, int cols2, double **matrix1, double **matrix2, double **result) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void print_matrix_to_file(FILE *file, int rows, int cols, double **matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%d ", (int)matrix[i][j]); 
        }
        fprintf(file, "\n");
    }
}
