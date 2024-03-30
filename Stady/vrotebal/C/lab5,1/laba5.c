#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "fynkci.h"
int main()
{
   char operations;
   int line1, column1, line2, column2;
   printf("Enter row first matrix: ");
   scanf("%d", &line1);
   printf("Enter column first matrix: ");
   scanf("%d", &column1);

   printf("Enter row second matrix: ");
   scanf("%d", &line2);
   printf("Enter column second matrix: ");
   scanf("%d", &column2);

   double **matrix1 = (double **)malloc(line1 * sizeof(double *)); // указатель на строки массива
   for (int i = 0; i < line1; i++)
   {
      matrix1[i] = (double *)malloc(column1 * sizeof(double));
   }
   printf("First matrix:\n");
   for (int i = 0; i < line1; i++)
   {
      for (int j = 0; j < column1; j++)
      {
         printf("enter your numbers [%d][%d]= ", i, j);
         scanf("%lf", &matrix1[i][j]);
      }
   }

   // Второй массив

   double **matrix2 = (double **)malloc(line2 * sizeof(double *)); // указатель на строки массива
   for (int i = 0; i < line2; i++)
   {
      matrix2[i] = (double *)malloc(column2 * sizeof(double));
   }
   printf("Second matrix:\n");
   for (int i = 0; i < line2; i++)
   {
      for (int j = 0; j < column2; j++)
      {
         printf("enter your numbers [%d][%d]= ", i, j);
         scanf("%lf", &matrix2[i][j]);
      }
   }
   printf("enter the operation sign (+, -, *):");
   getchar();
   scanf("%c", &operations);

   double **matr_result = operations_matrix(matrix1, matrix2, line1, column1, operations);
   printf("result:\n");
   for (int i = 0; i < line1; i++)
   {
      for (int j = 0; j < column1; j++)
      {
         printf("%.2f\t", matr_result[i][j]);
      }
      printf("\n");
   }
   for (int i = 0; i < line1; i++)
   {
      free(matrix1[i]);
      free(matrix2[i]);
      free(matr_result[i]);
   }
   free(matrix1);
   free(matrix2);
   free(matr_result);
}