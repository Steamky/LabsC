#include <stdio.h>
 
int main() {
    int matrix[4][4];
  
    for (int i = 0; i< 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
    
    printf("matrix:\n");
    
    for (int i = 0; i< 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    int mainAxis = 0;
    int secondaryAxis = 0;
    
    for (int i = 0; i <= 3; i++) {
        mainAxis += matrix[i][i];
        secondaryAxis += matrix[i][(4-1)-i];
    }
    
    printf("Main axis sum: %d\nSecondary axis sum: %d", mainAxis, secondaryAxis);
  
    return 0;
}
