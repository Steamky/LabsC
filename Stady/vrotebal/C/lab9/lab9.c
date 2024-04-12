#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *razd;
    double rezult = 0;
    char primer[1024];
    char *str2;

    printf("Insert your math tasks:\n");
    fgets(primer, 1023, stdin);
    primer[strcspn(primer, "\n")] = '\0';

    for (int i = 0; primer[i]; i++) {
        if (primer[i] == ' ') {
            for (int j = i; primer[j]; j++) {
                primer[j] = primer[j + 1];
            }
            i--;
        }
    }

    razd = strtok(primer, "+-");

    if (razd == NULL) {
        printf("Retry please...\n");
        return 0;
    }
    rezult = strtod(razd, &str2);

    while ((razd = strtok(NULL, "+-")) != NULL) {
        double num = strtod(razd, &str2);
        switch (*str2) {
            case '+':
                rezult += num;
                break;
            case '-':
                rezult -= num;
                break;
            default:
                printf("Wrong index.\n");
                return 0;
        }
    }

    printf("Your answer: %lf\n", rezult);
    return 0;
}
