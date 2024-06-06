#include <stdio.h>
#include <time.h>
#include "numbers_io.h"

void replace_numbers();
void create_matrix_from_file();

int main() {
    clock_t start_time = clock();

    create_random_numbers_file();
    replace_numbers();
    create_matrix_from_file();

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("time running program: %f second\n", elapsed_time);

    return 0;
}
