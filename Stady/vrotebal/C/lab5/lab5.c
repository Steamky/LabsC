
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() 
{
    int row, colms;
    double** a;
    double**** b;
    printf("Insert nubmers of rows:\n");
    scanf("%d", &row);
    printf("Insert numbers of colmns:\n");
    scanf("%d", &colms);
    // Выделение памяти под указатели на строки
    a = (double**)malloc(row*sizeof(double*));
    b = (double****)malloc(row*sizeof(double***));
    for (int i = 0; i < row; i++)  
    {
      a[i] = (double*)malloc(colms * sizeof(double));
      for (int j = 0; j < colms; j++) 
      {
        printf("a[%d][%d] = ", i, j);
        scanf("%lf", &a[i][j]);
      }
    }
    for (int i = 0; i < row; i++)
    {
      b[i] = (double***)malloc(colms * sizeof(double));
      for (int j = 0; j < colms; j++)
      {
        printf("b[%d][%d]= ", i,j);
        scanf("%lf",&b[i][j]);
      }
    }
    for (int i = 0; i< row; i++)  
    {
      for ( int j = 0; j< colms; j++) 
      {
        printf("%5lf ", a[i][j]);
      }
    printf("\n"); 
    }
    printf("\n");
    for (int i = 0; i < row; i++)
    {
      for ( int j = 0; j < colms; j++)
      {
        printf("%5lf ", b[i][j]);
      }
    printf("\n");
    }




    return 0;









}
