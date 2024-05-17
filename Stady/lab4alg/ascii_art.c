#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ascii_art.h"

void read_art_dimensions(FILE *file, int *rows, int *cols) {
    char line[1024];
    *rows = 0;
    *cols = 0;
    long initial_pos = ftell(file);

    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        if (*cols < len) *cols = len;
        (*rows)++;
    }
    fseek(file, initial_pos, SEEK_SET);
}

void input(ASCII_Art *art, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    read_art_dimensions(file, &art->rows, &art->cols);
    art->data = (char **)malloc(art->rows * sizeof(char *));
    for (int i = 0; i < art->rows; i++) {
        art->data[i] = (char *)malloc((art->cols + 1) * sizeof(char));
        fgets(art->data[i], art->cols + 2, file);
        art->data[i][strcspn(art->data[i], "\r\n")] = '\0';
    }
    fclose(file);
}

void output(const ASCII_Art *art) {
    for (int i = 0; i < art->rows; i++) {
        printf("%s\n", art->data[i]);
    }
}

void clean(ASCII_Art *art) {
    for (int i = 0; i < art->rows; i++) {
        memset(art->data[i], ' ', art->cols);
        art->data[i][art->cols] = '\0';
    }
}

void inverse(ASCII_Art *art) {
    for (int i = 0; i < art->rows; i++) {
        for (int j = 0; j < art->cols; j++) {
            art->data[i][j] = (art->data[i][j] == ' ') ? '*' : ' ';
        }
    }
}

void dotting(ASCII_Art *art) {
    for (int i = 0; i < art->rows; i++) {
        for (int j = 0; j < art->cols; j++) {
            if (art->data[i][j] == ' ') {
                art->data[i][j] = '.';
            }
        }
    }
}

void rotate_r(ASCII_Art *art) {
    char **new_data = (char **)malloc(art->cols * sizeof(char *));
    for (int i = 0; i < art->cols; i++) {
        new_data[i] = (char *)malloc((art->rows + 1) * sizeof(char));
        for (int j = 0; j < art->rows; j++) {
            new_data[i][j] = art->data[art->rows - j - 1][i];
        }
        new_data[i][art->rows] = '\0';
    }

    for (int i = 0; i < art->rows; i++) {
        free(art->data[i]);
    }
    free(art->data);
    art->data = new_data;
    int temp = art->rows;
    art->rows = art->cols;
    art->cols = temp;
}

void rotate_l(ASCII_Art *art) {
    char **new_data = (char **)malloc(art->cols * sizeof(char *));
    for (int i = 0; i < art->cols; i++) {
        new_data[i] = (char *)malloc((art->rows + 1) * sizeof(char));
        for (int j = 0; j < art->rows; j++) {
            new_data[i][j] = art->data[j][art->cols - i - 1];
        }
        new_data[i][art->rows] = '\0';
    }

    for (int i = 0; i < art->rows; i++) {
        free(art->data[i]);
    }
    free(art->data);
    art->data = new_data;
    int temp = art->rows;
    art->rows = art->cols;
    art->cols = temp;
}

void frame(ASCII_Art *art, char c) {
    int new_rows = art->rows + 2;
    int new_cols = art->cols + 2;
    char **new_data = (char **)malloc(new_rows * sizeof(char *));
    for (int i = 0; i < new_rows; i++) {
        new_data[i] = (char *)malloc((new_cols + 1) * sizeof(char));
        new_data[i][new_cols] = '\0';
        if (i == 0 || i == new_rows - 1) {
            memset(new_data[i], c, new_cols);
        } else {
            new_data[i][0] = c;
            new_data[i][new_cols - 1] = c;
            memcpy(new_data[i] + 1, art->data[i - 1], art->cols);
        }
    }

    for (int i = 0; i < art->rows; i++) {
        free(art->data[i]);
    }
    free(art->data);

    art->data = new_data;
    art->rows = new_rows;
    art->cols = new_cols;
}

void save(const ASCII_Art *art, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < art->rows; i++) {
        fprintf(file, "%s\n", art->data[i]);
    }
    fclose(file);
}

void free_art(ASCII_Art *art) {
    for (int i = 0; i < art->rows; i++) {
        free(art->data[i]);
    }
    free(art->data);
}
