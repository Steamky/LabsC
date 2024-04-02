#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Russian");
    char information[1024];

    char str;
    FILE *file;
    file = fopen("list.txt","r+t");
    while (fgets(information,50,file) != NULL) {
        printf("%s", information);
    }
    printf("\n");
    fclose(file);
    return 0;
}