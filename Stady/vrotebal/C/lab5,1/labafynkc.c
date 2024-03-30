//#include "fynkci.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
double **operations_matrix(double **matrix1, double **matrix2, int li_result, int col_result, char operations)
{

   double **matr_result = (double **)malloc(li_result * sizeof(double *));
   for (int i = 0; i < li_result; i++)
   {
      matr_result[i] = (double *)malloc(col_result * sizeof(double));
   }
   switch (operations)
   {
   case '+':
      for (int i = 0; i < li_result; i++)
      {
         for (int j = 0; j < col_result; j++)
         {
            matr_result[i][j] = matrix1[i][j] + matrix2[i][j];
         }
      }
      break;
   case '-':
      for (int i = 0; i < li_result; i++)
      {
         for (int j = 0; j < col_result; j++)
         {
            matr_result[i][j] = matrix1[i][j] - matrix2[i][j];
         }
      }
      break;
   case '*':
      for (int i = 0; i < li_result; i++)
      {
         for (int j = 0; j < col_result; j++)
         {
            double a = 0;
            for (int k = 0; k < col_result; k++)
            {
               a = matrix1[i][k] * matrix2[k][j];
            }
            matr_result[i][j] = a;
         }
      }
      break;
   default:
      for (int i = 0; i < li_result; i++)
      {
         free(matr_result[i]);
      }
      free(matr_result);
   }
   return matr_result;
}