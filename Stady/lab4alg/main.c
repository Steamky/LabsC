#include <stdio.h>
#include <string.h>
#include "ascii_art.h"

int main() {
    ASCII_Art art;
    char inputFileName[256], outputFileName[256];
    char command[10];

    printf("Enter the input file name: ");
    scanf("%255s", inputFileName);
    input(&art, inputFileName);

    while (1) {
        printf("Enter command (output, clean, inverse, dotting, rotate_r, rotate_l, frame, save, exit): ");
        scanf("%9s", command);
        
        if (strcmp(command, "output") == 0) {
            output(&art);
        } else if (strcmp(command, "clean") == 0) {
            clean(&art);
        } else if (strcmp(command, "inverse") == 0) {
            inverse(&art);
        } else if (strcmp(command, "dotting") == 0) {
            dotting(&art);
        } else if (strcmp(command, "rotate_r") == 0) {
            rotate_r(&art);
        } else if (strcmp(command, "rotate_l") == 0) {
            rotate_l(&art);
        } else if (strcmp(command, "frame") == 0) {
            char c;
            printf("Enter frame character: ");
            scanf(" %c", &c); // note space before %c to eat newline
            frame(&art, c);
        } else if (strcmp(command, "save") == 0) {
            printf("Enter the output file name: ");
            scanf("%255s", outputFileName);
            save(&art, outputFileName);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    free_art(&art);
    return 0;
}
