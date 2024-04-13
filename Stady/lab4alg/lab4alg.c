#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

char image[MAX_ROWS][MAX_COLS];
int rows = 0, cols = 0;

// Функция для ввода картинки из файла
void input(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char buffer[MAX_COLS];
    while (fgets(buffer, MAX_COLS, file) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Удаляем символ новой строки
            len--;
        }
        if (len > cols) cols = len;
        strcpy(image[rows], buffer);
        rows++;
    }

    fclose(file);
}

// Функция для вывода картинки
void output() {
    for (int r = 0; r < rows; r++) {
        printf("%s\n", image[r]);
    }
}

// Функция для очистки картинки (заполнить пробелами)
void clean() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            image[r][c] = ' ';
        }
    }
}

// Функция для инверсии картинки
void inverse() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (image[r][c] == '*')
                image[r][c] = ' ';
            else
                image[r][c] = '*';
        }
    }
}

// Функция для поворота картинки по часовой стрелке
void rotate_r() {
    char temp[MAX_ROWS][MAX_COLS];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            temp[c][rows - 1 - r] = image[r][c];
        }
    }
    int temp_var = rows;
    rows = cols;
    cols = temp_var;
    memcpy(image, temp, sizeof(temp));
}

// Функция для поворота картинки против часовой стрелки
void rotate_l() {
    char temp[MAX_ROWS][MAX_COLS];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            temp[rows - 1 - c][r] = image[r][c];
        }
    }
    int temp_var = rows;
    rows = cols;
    cols = temp_var;
    memcpy(image, temp, sizeof(temp));
}

// Функция для создания рамки из символов c
void frame(char c) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                image[r][c] = c;
            }
        }
    }
}

// Функция для заполнения пробелов в картинке точками
void dotting() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (image[r][c] == ' ')
                image[r][c] = '.';
        }
    }
}

// Функция для сохранения картинки в файл
void save(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int r = 0; r < rows; r++) {
        fprintf(file, "%s\n", image[r]);
    }

    fclose(file);
}

int main() {
    const char filename[] = "pic1.txt";
    input(filename);

    printf("Original image:\n");
    output();

    clean();
    printf("\nCleaned image:\n");
    output();

    inverse();
    printf("\nInversed image:\n");
    output();

    rotate_r();
    printf("\nRotated clockwise image:\n");
    output();

    rotate_l();
    printf("\nRotated counterclockwise image:\n");
    output();

    frame('*');
    printf("\nFramed image:\n");
    output();

    dotting();
    printf("\nDotted image:\n");
    output();

    save("output.txt");
    printf("\nSaved image to output.txt\n");

    return 0;
}
