#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 512

int n, m, current;
int N[100], M[100];
char **pic[100];

void free_picture(int i) {
    // Free allocated memory for each line
    for (int j = 0; j < M[i]; j++) {
        free(pic[i][j]);
    }
    // Free the array of pointers
    free(pic[i]);
}

void input(int cur, char *filename) {
    FILE *F;
    char str[MAX_CHAR];
    int i, len;

    len = 0;
    m = 0;
    F = fopen(filename, "r");
    if (F == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    while (fgets(str, MAX_CHAR, F)) {
        n = strlen(str);
        if (str[n - 1] == '\n') {
            n--;
        }
        len = n; // Update maximum line length

        // Allocate memory for the picture (if first time or resized)
        if (pic[cur] == NULL || N[cur] < len) {
            free_picture(cur); // Free previous allocation (if any)
            pic[cur] = (char **)malloc(m * sizeof(char *));
            for (i = 0; i < m; i++) {
                pic[cur][i] = (char *)malloc((len + 1) * sizeof(char)); // +1 for null terminator
            }
        }

        strncpy(pic[cur][m], str, len);
        pic[cur][m][len] = '\0'; // Ensure null termination
        m++;
    }

    N[cur] = len;
    M[cur] = m;
    printf("m=%d n=%d\n", m, n);
    fclose(F);
}

void output(int i) {
    int n, m, j;

    printf(" Picture # %d\n", i);
    m = M[i];
    n = N[i];
    for (j = 0; j < m; j++) {
        printf("%s\n", pic[i][j]);
    }
}

void clean(int i) {
    int m, j;

    m = M[i];
    for (j = 0; j < m; j++) {
        memset(pic[i][j], ' ', N[i] + 1); // Fill with spaces (including null terminator)
    }
}

// Implement other functions like inverse, rotate, frame, dotting, save here

int main(int argc, char *argv[]) {
    FILE *F;
    int i;
    char filename[256] = "pic1.txt";

    for (i = 0; i < 100; i++) {
        pic[i] = NULL;
    }

    F = fopen(filename, "r");
    if (F == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    input(0, filename);
    output(0);

    input(1, "pic2.txt");
    output(1);

    clean(0); // Example usage of clean function
    output(0);

    // Call other functions here

    for (i = 0; i < 100; i++) {
        free_picture(i); // Free all allocated memory before exiting
    }

    fclose(F);
    return 0;
}
