#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the number of days until a specific date
int days_until_date(const char *input_file) {
    FILE *file = fopen(input_file, "r");
    int year, month, day;
    fscanf(file, "%d-%d-%d", &year, &month, &day);
    fclose(file);

    struct tm target_date = {0};
    target_date.tm_year = year - 1900;
    target_date.tm_mon = month - 1;
    target_date.tm_mday = day;

    time_t target_time = mktime(&target_date);
    time_t current_time = time(NULL);

    double seconds = difftime(target_time, current_time);
    return seconds / (60 * 60 * 24);
}

// Function to create a square matrix filled with random numbers from 0 to 9
void create_matrix(int m, int matrix[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print the matrix
void print_matrix(int m, int matrix[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of elements in a matrix
int matrix_sum(int m, int matrix[m][m]) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Function to find two matrices with the same sum of elements and write them to a file
void find_matching_matrices(int m) {
    srand(time(NULL));
    int matrix1[m][m], matrix2[m][m];
    int sum1, sum2;

    FILE *output = fopen("output.txt", "w");

    do {
        create_matrix(m, matrix1);
        create_matrix(m, matrix2);
        sum1 = matrix_sum(m, matrix1);
        sum2 = matrix_sum(m, matrix2);
    } while (sum1 != sum2);

    fprintf(output, "Matrix 1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(output, "%d ", matrix1[i][j]);
        }
        fprintf(output, "\n");
    }

    fprintf(output, "Matrix 2:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(output, "%d ", matrix2[i][j]);
        }
        fprintf(output, "\n");
    }

    fclose(output);
}

int main() {
    const char *input_file = "input.txt";
    int days_left = days_until_date(input_file);
    printf("Days until target date: %d\n", days_left);

    int m = 4;
    clock_t start_time = clock();
    find_matching_matrices(m);
    clock_t end_time = clock();
    double runtime = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Runtime: %f seconds\n", runtime);

    return 0;
}
