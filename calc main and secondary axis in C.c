#include <stdio.h>
 
int main() {
    int matrix[3][3];
  
    for (int i = 0; i< 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
    
    printf("matrix:\n");
    
    for (int i = 0; i< 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    int mainAxis = 0;
    int secondaryAxis = 0;
    
    for (int i = 0; i <= 2; i++) {
        mainAxis += matrix[i][i];
        secondaryAxis += matrix[i][2-i];
    }
    
    printf("Main axis sum: %d\nSecondary axis sum: %d", mainAxis, secondaryAxis);
  
    return 0;
}
