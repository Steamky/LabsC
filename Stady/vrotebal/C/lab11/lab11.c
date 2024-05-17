#include <stdio.h>
#include "lab11func.h"

int main() {
    printf("Sum: %d\n", sum(5, 5, 2, 8, 9, 3));
    printf("Max: %d\n", max(5, 5, 2, 8, 9, 3));
    printf("Min: %d\n", min(5, 5, 2, 8, 9, 3));
    printf("Average: %f\n", avg(5, 5.0, 2.0, 8.0, 9.0, 3.0));  // Типы аргументов соответствуют double

    return 0;
}
