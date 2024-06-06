#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numbers_io.h"

void create_random_numbers_file() {
    int n;
    printf("Insert number of random numbers: ");
    scanf("%d", &n);

    double numbers[n];
    printf("Insert numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &numbers[i]);
    }

    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%f\n", numbers[i]);
    }

    fclose(file);
}

void read_numbers_from_file(double numbers[100], int *n) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    *n = 0;
    while (fscanf(file, "%lf", &numbers[*n]) != EOF) {
        (*n)++;
    }

    fclose(file);
}

void write_numbers_to_file(const char *filename, const double numbers[100], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%f\n", numbers[i]);
    }

    fclose(file);
}
