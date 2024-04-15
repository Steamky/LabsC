#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int n, m;
int N[100], M[100];
char ***pic; // Заменил объявление pic на тройной указатель

// Функция для ввода "картинки" из файла в i-й массив
void input(int cur, char *filename) {
    FILE *F;
    char str[512], Pic[512][512];
    int i, len;
    len = 0;
    m = 0;
    F = fopen(filename, "r");
    while (fgets(str, 512, F)) {
        n = strlen(str);
        if (str[n - 1] == '\n') n--;
        len = n;
        strncpy(Pic[m], str, n);
        m++;
    }
    pic[cur] = (char ***)malloc(m * sizeof(char **)); // Изменение типа на char ***
    for (i = 0; i < m; i++) {
        pic[cur][i] = (char **)malloc(n * sizeof(char *)); // Изменение типа на char *
        pic[cur][i][n] = '\0'; // Добавление завершающего нуля
        strncpy(pic[cur][i], Pic[i], n);
    }
    N[cur] = n;
    M[cur] = m;
    printf("m=%d n=%d\n", m, n);
}

// Функция для вывода "картинки"
void output(int num) {
    int n, m, i, j;
    printf(" Picture # %d\n", num);
    m = M[num];
    n = N[num];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            putchar(pic[num][i][j]);
        putchar('\n');
    }
}

// Функция для очистки картинки (заполнить пробелами)
void clean(int i) {
    for (int row = 0; row < M[i]; row++) { // Исправление на M[i]
        for (int col = 0; col < N[i]; col++) { // Исправление на N[i]
            pic[i][row][col] = ' ';
        }
    }
}

// Функция для инверсии картинки
void inverse(int i) {
    for (int row = 0; row < M[i]; row++) { // Исправление на M[i]
        for (int col = 0; col < N[i]; col++) { // Исправление на N[i]
            if (pic[i][row][col] == ' ') {
                pic[i][row][col] = '*';
            } else {
                pic[i][row][col] = ' ';
            }
        }
    }
}

// Функция для поворота картинки по часовой стрелке
void rotate_r(int i) {
    char **temp = (char **)malloc(N[i] * sizeof(char *)); // Исправление на N[i]
    for (int row = 0; row < N[i]; row++) { // Исправление на N[i]
        temp[row] = (char *)malloc(M[i] + 1); // Исправление на M[i]
        temp[row][M[i]] = '\0'; // Добавление завершающего нуля
        for (int col = 0; col < M[i]; col++) { // Исправление на M[i]
            temp[row][col] = pic[i][M[i] - 1 - col][row]; // Исправление на M[i]
        }
    }
    for (int row = 0; row < N[i]; row++) { // Исправление на N[i]
        for (int col = 0; col < M[i]; col++) { // Исправление на M[i]
            pic[i][row][col] = temp[row][col];
        }
    }
    int temp_dim = M[i];
    M[i] = N[i];
    N[i] = temp_dim;
    for (int row = 0; row < N[i]; row++) { // Исправление на N[i]
        free(temp[row]);
    }
    free(temp);
}

// Функция для поворота картинки против часовой стрелки
void rotate_l(int i) {
    char **temp = (char **)malloc(N[i] * sizeof(char *)); // Исправление на N[i]
    for (int row = 0; row < N[i]; row++) { // Исправление на N[i]
        temp[row] = (char *)malloc(M[i] + 1); // Исправление на M[i]
        temp[row][M[i]] = '\0'; // Добавление завершающего нуля
        for (int col = 0; col < M[i]; col++) { // Исправление на M[i]
            temp[row][col] = pic[i][col][N[i] - 1 - row]; // Исправление на N[i]
        }
    }
    for (int row = 0; row < N[i]; row++) { // Исправление на N[i]
        for (int col = 0; col < M[i]; col++) { // Исправление на M[i]
            pic[i][row][col] = temp[row][col];
        }
    }
    int temp_dim = M[i];
    M[i] = N[i];
    N[i] = temp_dim;
    for (int row = 0; row < N[i]; row++) { // Исправление на N[i]
        free(temp[row]);
    }
    free(temp);
}

// Функция для создания рамки из символов c
void frame(int i, char c) {
    for (int row = 0; row < M[i]; row++) { // Исправление на M[i]
        for (int col = 0; col < N[i]; col++) { // Исправление на N[i]
            if (row == 0 || row == M[i] - 1 || col == 0 || col == N[i] - 1) { // Исправление на M[i] и N[i]
                pic[i][row][col] = c;
            }
        }
    }
}

// Функция для заполнения пробелов в картинке точками
void dotting(int i) {
    for (int row = 0; row < M[i]; row++) { // Исправление на M[i]
        for (int col = 0; col < N[i]; col++) { // Исправление на N[i]
            if (pic[i][row][col] == ' ') {
                pic[i][row][col] = '.';
            }
        }
    }
}

// Функция для сохранения картинки в файл
void save(int i, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка при создании файла для сохранения изображения!\n");
        exit(1);
    }

    for (int row = 0; row < M[i]; row++) { // Исправление на M[i]
        fprintf(file, "%s\n", pic[i][row]);
    }

    fclose(file);
}

int main() {
    char filename[256] = "pic1.txt";

    pic = (char ***)malloc(100 * sizeof(char **)); // Изменение типа на char *** и выделение памяти

    for (int i = 0; i < 100; i++) pic[i] = NULL;

    input(0, filename);
    output(0);

    clean(0);
    printf("\nКартинка после очистки:\n");
    output(0);

    inverse(0);
    printf("\nКартинка после инверсии:\n");
    output(0);

    rotate_r(0);
    printf("\nКартинка после поворота по часовой стрелке:\n");
    output(0);

    frame(0, '#');
    printf("\nКартинка с рамкой:\n");
    output(0);

    dotting(0);
    printf("\nКартинка с точками:\n");
    output(0);

    save(0, "output.txt");
    printf("\nКартинка сохранена в файле output.txt\n");

    // Освобождение памяти
    for (int i = 0; i < 100; i++) {
        if (pic[i] != NULL) {
            for (int j = 0; j < M[i]; j++) {
                free(pic[i][j]);
            }
            free(pic[i]);
        }
    }
    free(pic);

    return 0;
}
