#include <stdio.h>
#include "numbers_io.h"

void create_matrix_from_file() {
    double numbers[100];
    int n;
    read_numbers_from_file(numbers, &n);

    int M;
    printf("Insert nubmers column: ");
    scanf("%d", &M);

    if (n % M != 0) {
        n = n - (n % M); 
    }

    int rows = n / M;

    FILE *file = fopen("output.txt", "a");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    fprintf(file, "\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            fprintf(file, "%f ", numbers[i * M + j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            printf("%f ", numbers[i * M + j]);
        }
        printf("\n");
    }
}
