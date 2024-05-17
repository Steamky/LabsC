#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 2000

typedef struct {
    int x, y;
} Point;

void enqueue(Point queue[], int *tail, Point item) {
    queue[(*tail)++] = item;
}

Point dequeue(Point queue[], int *head) {
    return queue[(*head)++];
}

int is_empty(int head, int tail) {
    return head == tail;
}

int main() {
    FILE *file = fopen("Labirint.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return EXIT_FAILURE;
    }

    int N, M;
    fscanf(file, "%d %d\n", &N, &M);  // Чтение размеров лабиринта

    char l[N][M + 1];
    int L[N][M];

    for (int i = 0; i < N; i++) {
        fgets(l[i], M + 2, file);  // Читаем строку + символ перевода строки и null-терминатор
        l[i][strcspn(l[i], "\r\n")] = 0;  // Удаление символов новой строки
        for (int j = 0; j < M; j++) {
            L[i][j] = (l[i][j] == '*') ? -1 : INT_MAX;
        }
    }
    fclose(file);  // Закрытие файла

    Point Q1[MAX_SIZE * MAX_SIZE], Q2[MAX_SIZE * MAX_SIZE];
    int head1 = 0, tail1 = 0, head2 = 0, tail2 = 0;
    Point start = {0, 0};
    L[0][0] = 0;
    enqueue(Q1, &tail1, start);

    int Nc = 1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!is_empty(head1, tail1)) {
        while (!is_empty(head1, tail1)) {
            Point current = dequeue(Q1, &head1);
            for (int i = 0; i < 4; i++) {
                int nx = current.x + directions[i][0];
                int ny = current.y + directions[i][1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && L[nx][ny] > Nc && L[nx][ny] != -1) {
                    L[nx][ny] = Nc;
                    Point next = {nx, ny};
                    enqueue(Q2, &tail2, next);
                }
            }
        }
        Nc++;
        memcpy(Q1, Q2, sizeof(Point) * tail2);
        tail1 = tail2;
        head1 = 0;
        tail2 = 0;
        head2 = 0;
    }

    if (L[N-1][M-1] == INT_MAX) {
        printf("No path found.\n");
    } else {
        printf("Minimum steps required: %d\n", L[N-1][M-1]);
    }

    return EXIT_SUCCESS;
}
