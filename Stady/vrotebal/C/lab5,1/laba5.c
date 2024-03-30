#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "fynkci.h"
int main()
{
   char operations;
   int  row, column;
   printf("Enter rows: ");
   scanf("%d", &row);
   printf("Enter column: ");
   scanf("%d", &column);

   double **matrix1 = (double **)malloc(row * sizeof(double *)); // указатель на строки массива
   for (int i = 0; i < row; i++)
   {
      matrix1[i] = (double *)malloc(column * sizeof(double));
   }
   printf("First matrix:\n");
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < column; j++)
      {
         printf("enter your numbers [%d][%d]= ", i, j);
         scanf("%lf", &matrix1[i][j]);
      }
   }

   // Второй массив

   double **matrix2 = (double **)malloc(row * sizeof(double *)); // указатель на строки массива
   for (int i = 0; i < row; i++)
   {
      matrix2[i] = (double *)malloc(column * sizeof(double));
   }
   printf("Second matrix:\n");
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < column; j++)
      {
         printf("enter your numbers [%d][%d]= ", i, j);
         scanf("%lf", &matrix2[i][j]);
      }
   }
   printf("enter the operation sign (+, -, *):");
   getchar();
   scanf("%c", &operations);

   double **matr_result = operations_matrix(matrix1, matrix2, row, column, operations);
   print_matrix(matr_result, row, column);
  
   free(matrix1);
   free(matrix2);
   free(matr_result);
}