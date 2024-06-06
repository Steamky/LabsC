#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct people {
    char name[50], surname[50];
    int year;
    char gender;
    float height; 
};

// функция сравнения для сортировки
int sravnenie(const void *a, const void *b, const char *field1, const char *field2) {
    const struct people *people1 = (const struct people *)a;
    const struct people *people2 = (const struct people *)b;

    int result;
    if (strcmp(field1, "year") == 0) {
        result = people1->year - people2->year;
    } else if (strcmp(field1, "name") == 0) {
        result = strcmp(people1->name, people2->name);
    } else if (strcmp(field1, "surname") == 0) {
        result = strcmp(people1->surname, people2->surname);
    } else if (strcmp(field1, "gender") == 0) {
        result = people1->gender - people2->gender;
    } else if (strcmp(field1, "height") == 0) {
        result = (people1->height > people2->height) - (people1->height < people2->height);
    } else {
        printf("Unknown field: %s\n", field1);
        return 0;
    }

    // Если первые поля равны, используем вторые поля для сравнения
    if (result == 0) {
        if (strcmp(field2, "year") == 0) {
            result = people1->year - people2->year;
        } else if (strcmp(field2, "name") == 0) {
            result = strcmp(people1->name, people2->name);
        } else if (strcmp(field2, "surname") == 0) {
            result = strcmp(people1->surname, people2->surname);
        } else if (strcmp(field2, "gender") == 0) {
            result = people1->gender - people2->gender;
        } else if (strcmp(field2, "height") == 0) {
            result = (people1->height > people2->height) - (people1->height < people2->height);
        } else {
            printf("Unknown field: %s\n", field2);
            return 0;
        }
    }

    return result;
}

// функция сортировки пузырьком
void bubbleSort(struct people arr[], int n, const char *field1, const char *field2) {
    int i, j;
    struct people temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sravnenie(&arr[j], &arr[j + 1], field1, field2) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("lab8.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int num_pec = 0;
    struct people pers[100];
    char field1[50], field2[50];
    while (fscanf(file, "%49s %49s %d %c %f", pers[num_pec].name,
                 pers[num_pec].surname, &pers[num_pec].year, 
                 &pers[num_pec].gender, &pers[num_pec].height) != EOF) {
        num_pec++;
    }
    fclose(file);

    printf("Enter first field to sort by (name, surname, year, gender, height): ");
    scanf("%49s", field1);
    printf("Enter second field to sort by (name, surname, year, gender, height): ");
    scanf("%49s", field2);

    bubbleSort(pers, num_pec, field1, field2);

    FILE *output = fopen("sorted_lab8.txt", "w");
    if (!output) {
        perror("Failed to open output file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_pec; i++) {
        fprintf(output, "%s %s %d %c %.2f\n", pers[i].name, pers[i].surname, pers[i].year, pers[i].gender, pers[i].height);
    }
    fclose(output);

    printf("Sorted records have been written to sorted_lab8.txt\n");

    return 0;
}
