#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fyn.h"

int main() {
    clock_t start_time = clock();
    srand(time(NULL));
    int n1, n2;

    printf("dimension1: ");
    scanf("%d", &n1);

    int **matrix1 = (int **)malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        matrix1[i] = (int *)malloc(n1 * sizeof(int));
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            matrix1[i][j] = rand() % 101;
        }
    }

    printf("dimension2: ");
    scanf("%d", &n2);
    if (n1 != n2) {
        printf("The matrices must be the same size for multiplication!\n");
        for (int i = 0; i < n1; i++) {
            free(matrix1[i]);
        }
        free(matrix1);
        return 1;
    }

    int **matrix2 = (int **)malloc(n2 * sizeof(int *));
    for (int i = 0; i < n2; i++) {
        matrix2[i] = (int *)malloc(n2 * sizeof(int));
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            matrix2[i][j] = rand() % 101;
        }
    }

    FILE *fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening file input.txt for writing\n");
        return 1;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            fprintf(fp, "%d ", matrix1[i][j]);
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "\n");

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            fprintf(fp, "%d ", matrix2[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    int **read_matrix1 = (int **)malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        read_matrix1[i] = (int *)malloc(n1 * sizeof(int));
    }

    int **read_matrix2 = (int **)malloc(n2 * sizeof(int *));
    for (int i = 0; i < n2; i++) {
        read_matrix2[i] = (int *)malloc(n2 * sizeof(int));
    }

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file input.txt for reading\n");
        return 1;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            fscanf(fp, "%d", &read_matrix1[i][j]);
        }
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            fscanf(fp, "%d", &read_matrix2[i][j]);
        }
    }

    fclose(fp);

    int **result = (int **)malloc(n1 * sizeof(int *));
    for (int i = 0; i < n1; i++) {
        result[i] = (int *)malloc(n1 * sizeof(int));
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening file output.txt for writing\n");
        return 1;
    }

    // Сложение
    fprintf(output, "Sum matrix:\n");
    add_matrices(result, read_matrix1, read_matrix2, n1);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            fprintf(output, "%d ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    // Умножение
    fprintf(output, "\nMultiplication matrix:\n");
    multiply_matrices(result, read_matrix1, read_matrix2, n1);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            fprintf(output, "%d ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    fclose(output);

    
    for (int i = 0; i < n1; i++) {
        free(matrix1[i]);
        free(read_matrix1[i]);
        free(result[i]);
    }
    free(matrix1);
    free(read_matrix1);
    free(result);

    for (int i = 0; i < n2; i++) {
        free(matrix2[i]);
        free(read_matrix2[i]);
    }
    free(matrix2);
    free(read_matrix2);

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time running program: %f seconds\n", elapsed_time);

    return 0;
}
