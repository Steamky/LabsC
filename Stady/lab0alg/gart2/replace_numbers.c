#include <stdio.h>
#include "numbers_io.h"

void replace_numbers() {
    double numbers[100];
    int n;
    read_numbers_from_file(numbers, &n);

    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        int num = (int)numbers[i];
        if (num % 35 == 0) {
            fprintf(file, "ПЯТЬСЕМЬ\n");
        } else if (num % 5 == 0) {
            fprintf(file, "ПЯТЬ\n");
        } else if (num % 7 == 0) {
            fprintf(file, "СЕМЬ\n");
        } else {
            fprintf(file, "%f\n", numbers[i]);
        }
    }

    fclose(file);
}
