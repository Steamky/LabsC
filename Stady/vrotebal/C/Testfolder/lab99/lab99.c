#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char primer[1024];
    double rezult = 0;
    char *token;
    char *saveptr;

    printf("Введите математическое выражение: ");
    fgets(primer, 1023, stdin);
    primer[strcspn(primer, "\n")] = '\0';

    // Инициализация strtok_r
    token = strtok_r(primer, "+-", &saveptr);

    // Обработка первого токена
    rezult = atof(token);

    // Продолжаем обработку оставшихся токенов
    while ((token = strtok_r(NULL, "+-", &saveptr)) != NULL) {
        // Если токен содержит минус, значит это оператор вычитания
        if (strchr(token, '-') != NULL) {
            char *minus_ptr = strchr(token, '-');
            *minus_ptr = '\0'; // Разделяем токен на две части по знаку "-"
            rezult -= atof(token + 1); // Преобразуем вторую часть в число и вычитаем из результата
        } else {
            rezult += atof(token); // Иначе добавляем значение к результату
        }
    }

    printf("Результат: %.2lf\n", rezult);

    return 0;
}
