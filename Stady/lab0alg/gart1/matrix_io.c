#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_io.h"

void create_matrices_file() {
    int n, m;
    printf("insert number row: ");
    scanf("%d", &n);
    printf("Insert nubmer column: ");
    scanf("%d", &m);

    double matrix1[n][m], matrix2[n][m];
    printf("Insert 1-st matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Insert 2-nd martix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    fprintf(file, "matrix 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%f ", matrix1[i][j]);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "\nmatrix 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%f ", matrix2[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void read_matrices_from_file(double matrix1[100][100], double matrix2[100][100], int *n, int *m) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    int row = 0;
    int col = 0;
    fscanf(file, "matrix 1:\n");
    while (fscanf(file, "%lf", &matrix1[row][col]) == 1) {
        col++;
        if (fgetc(file) == '\n') {
            row++;
            col = 0;
        }
        if (fgetc(file) == '\n') break;
    }
    *n = row;
    *m = col;

    row = col = 0;
    fscanf(file, "\nmatrix 2:\n");
    while (fscanf(file, "%lf", &matrix2[row][col]) == 1) {
        col++;
        if (fgetc(file) == '\n') {
            row++;
            col = 0;
        }
        if (fgetc(file) == '\n') break;
    }

    fclose(file);
}

void write_matrices_to_file(double matrix_sum[100][100], double matrix_product[100][100], int n, int m) {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    fprintf(file, "Summ matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%f ", matrix_sum[i][j]);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "\nProizvedenie matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%f ", matrix_product[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
