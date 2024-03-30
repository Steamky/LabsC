#include "fynkci.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void print_matrix(double **matrix, int row, int column)
{
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < column; j++)
      {
         printf("%.f\t", matrix[i][j]);
      }
      printf("\n");
   }
}
double **operations_matrix(double **matrix1, double **matrix2, int row, int column, char operations)
{

   double **matr_result = (double **)malloc(row * sizeof(double *));
   for (int i = 0; i < row; i++)
   {
      matr_result[i] = (double *)malloc(column * sizeof(double));
   }
   switch (operations)
   {
   case '+':
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < column; j++)
         {
            matr_result[i][j] = matrix1[i][j] + matrix2[i][j];
         }
      }
      break;
   case '-':
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < column; j++)
         {
            matr_result[i][j] = matrix1[i][j] - matrix2[i][j];
         }
      }
      break;
   case '*':
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < column; j++)
         {
            double a = 0;
            for (int k = 0; k < column; k++)
            {
               a = matrix1[i][k] * matrix2[k][j];
            }
            matr_result[i][j] = a;
         }
      }
      break;
   default:
      for (int i = 0; i < row; i++)
      {
         free(matr_result[i]);
      }
      free(matr_result);
   }
   return matr_result;
}
   