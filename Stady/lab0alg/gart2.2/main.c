#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t prog_start = time(NULL);
    srand(prog_start); 

    int total_numbers;
    printf("Insert number of random numbers: ");
    scanf("%d", &total_numbers);

    int random_numbers[total_numbers];

    for (int index = 0; index < total_numbers; index++) {
        random_numbers[index] = rand() % 101; 
    }

    FILE *file_ptr = fopen("input.txt", "w");

    for (int index = 0; index < total_numbers; index++) {
        fprintf(file_ptr, "%d\n", random_numbers[index]);
    }

    fclose(file_ptr);

    for (int index = 0; index < total_numbers; index++) {
        random_numbers[index] = 0; 
    }

    FILE *input_fp = fopen("input.txt", "r");
    FILE *output_fp = fopen("output.txt", "w");

    int num;
    while (fscanf(input_fp, "%d", &num) != EOF) {
        if (num % 35 == 0) {
            fprintf(output_fp, "ПЯТЬСЕМЬ ");
        } else if (num % 5 == 0) {
            fprintf(output_fp, "ПЯТЬ ");
        } else if (num % 7 == 0) {
            fprintf(output_fp, "СЕМЬ ");
        } else {
            fprintf(output_fp, "%d ", num);
        }
    }

    fclose(input_fp);
    fclose(output_fp);

    input_fp = fopen("input.txt", "r");
    int M;
    printf("Enter the number of M: ");
    scanf("%d", &M);

    int rows = total_numbers / M;
    int matrix[rows][M];
    int row_index = 0, col_index = 0;

    while (fscanf(input_fp, "%d", &num) != EOF) {
        matrix[row_index][col_index] = num;
        if (++col_index == M) {
            col_index = 0;
            row_index++;
        }
    }

    fclose(input_fp);

    int row_totals[rows], column_totals[M];
    for (int i = 0; i < rows; i++) {
        row_totals[i] = 0;
        for (int j = 0; j < M; j++) {
            row_totals[i] += matrix[i][j];
        }
    }

    for (int j = 0; j < M; j++) {
        column_totals[j] = 0;
        for (int i = 0; i < rows; i++) {
            column_totals[j] += matrix[i][j];
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Sum of rows: ");
    for (int i = 0; i < rows; i++) {
        printf("%d ", row_totals[i]);
    }
    printf("\n");

    printf("Sum of columns: ");
    for (int j = 0; j < M; j++) {
        printf("%d ", column_totals[j]);
    }
    printf("\n");

    double execution_time = difftime(time(NULL), prog_start);
    printf("Time running program: %f seconds\n", execution_time);

    return 0;
}
