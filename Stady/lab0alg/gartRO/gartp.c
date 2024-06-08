#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to create a square matrix filled with random numbers from 0 to 9
void create_matrix(int m, int matrix[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to create input file with two random matrices
void create_input_file(int m, const char *filename) {
    FILE *file = fopen(filename, "w");
    int matrix1[m][m], matrix2[m][m];

    srand(time(NULL));
    create_matrix(m, matrix1);
    create_matrix(m, matrix2);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix1[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix2[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to read matrices from input file
void read_matrices(int m, const char *filename, int matrix1[m][m], int matrix2[m][m]) {
    FILE *file = fopen(filename, "r");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &matrix2[i][j]);
        }
    }

    fclose(file);
}

// Function to add two matrices
void add_matrices(int m, int matrix1[m][m], int matrix2[m][m], int result[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int m, int matrix1[m][m], int matrix2[m][m], int result[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to perform operations on matrices and write results to output file
void perform_operations(int m) {
    int matrix1[m][m], matrix2[m][m], sum_matrix[m][m], product_matrix[m][m];
    read_matrices(m, "input.txt", matrix1, matrix2);
    add_matrices(m, matrix1, matrix2, sum_matrix);
    multiply_matrices(m, matrix1, matrix2, product_matrix);

    FILE *output = fopen("output.txt", "w");

    fprintf(output, "Sum Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(output, "%d ", sum_matrix[i][j]);
        }
        fprintf(output, "\n");
    }

    fprintf(output, "Product Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(output, "%d ", product_matrix[i][j]);
        }
        fprintf(output, "\n");
    }

    fclose(output);
}

// Function to find the minimum odd number in a matrix
int find_min_odd(int m, int matrix[m][m]) {
    int min_odd = __INT_MAX__;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 != 0 && matrix[i][j] < min_odd) {
                min_odd = matrix[i][j];
            }
        }
    }
    return min_odd;
}

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to count rows and columns with only prime numbers in a matrix
void count_prime_rows_cols(int m, int matrix[m][m], int *row_count, int *col_count) {
    *row_count = 0;
    *col_count = 0;
    bool is_prime_row, is_prime_col;

    for (int i = 0; i < m; i++) {
        is_prime_row = true;
        is_prime_col = true;

        for (int j = 0; j < m; j++) {
            if (!is_prime(matrix[i][j])) is_prime_row = false;
            if (!is_prime(matrix[j][i])) is_prime_col = false;
        }

        if (is_prime_row) (*row_count)++;
        if (is_prime_col) (*col_count)++;
    }
}

int main() {
    int m = 4;
    create_input_file(m, "input.txt");

    clock_t start_time = clock();
    perform_operations(m);

    int matrix1[m][m], matrix2[m][m];
    read_matrices(m, "input.txt", matrix1, matrix2);

    int min_odd = find_min_odd(m, matrix1);
    printf("Minimum odd number in matrix1: %d\n", min_odd);

    int row_count, col_count;
    count_prime_rows_cols(m, matrix1, &row_count, &col_count);
    printf("Number of rows with all primes: %d\n", row_count);
    printf("Number of columns with all primes: %d\n", col_count);

    clock_t end_time = clock();
    double runtime = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Runtime: %f seconds\n", runtime);

    return 0;
}
