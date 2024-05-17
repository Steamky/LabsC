#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 2000
#define MAX_M 2000

char maze[MAX_N][MAX_M]; // Массив для хранения карты лабиринта
int distance[MAX_N][MAX_M]; // Массив для хранения расстояний до каждой клетки
int N, M; // Количество строк и столбцов в лабиринте

// Структура для представления координат клетки
struct Point {
    int x, y;
};

// Проверка, находится ли клетка в пределах лабиринта и доступна ли она для прохода
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && maze[x][y] != '*';
}

// Функция для поиска пути в лабиринте методом поиска в ширину (BFS)
void bfs() {
    // Массив смещений для перемещения на соседние клетки: вверх, вниз, влево, вправо
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Очередь для обхода клеток в ширину
    struct Point queue[MAX_N * MAX_M];
    int front = 0, rear = 0;

    // Инициализация очереди стартовой клеткой
    queue[rear++] = (struct Point){0, 0};
    distance[0][0] = 0; // Расстояние до стартовой клетки равно 0

    // Пока очередь не пуста, продолжаем обходить клетки
    while (front != rear) {
        struct Point current = queue[front++];
        
        // Проверяем соседние клетки на доступность и добавляем их в очередь
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            // Проверяем, является ли соседняя клетка доступной и еще не посещенной
            if (isValid(nx, ny) && distance[nx][ny] == -1) {
                // Обновляем расстояние до соседней клетки
                distance[nx][ny] = distance[current.x][current.y] + 1;
                // Добавляем соседнюю клетку в очередь для дальнейшего обхода
                queue[rear++] = (struct Point){nx, ny};
            }
        }
    }
}

// Выводит найденный путь в лабиринте
void printPath() {
    // Если расстояние до выхода осталось INT_MAX, значит, путь не найден
    if (distance[N-1][M-1] == -1) {
        printf("There is no path to the exit\n");
        return;
    }

    // Выводим длину кратчайшего пути до выхода
    printf("Minimum number of steps to reach the exit: %d\n", distance[N-1][M-1]);
    
    // Восстанавливаем путь, начиная с конечной клетки
    int x = N-1, y = M-1;
    printf("Path:\n(%d, %d)\n", x, y);
    while (x != 0 || y != 0) {
        // Ищем среди соседних клеток ту, расстояние до которой на 1 меньше
        for (int i = 0; i < 4; ++i) {
            int nx = x + nx[i];
            int ny = y + ny[i];
            if (isValid(nx, ny) && distance[nx][ny] == distance[x][y] - 1) {
                // Найдя такую клетку, переходим в неё и выводим её координаты
                x = nx;
                y = ny;
                printf("(%d, %d)\n", x, y);
                break;
            }
        }
    }
}

int main() {
    // Чтение количества строк и столбцов лабиринта
    scanf("%d %d", &N, &M);

    // Чтение карты лабиринта
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf(" %c", &maze[i][j]);
        }
    }

    // Инициализация массива расстояний
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            distance[i][j] = -1; // -1 означает, что клетка еще не была посещена
        }
    }

    // Начало поиска пути в лабиринте методом поиска в ширину
    bfs();

    // Вывод результатов
    printPath();

    return 0;
}
