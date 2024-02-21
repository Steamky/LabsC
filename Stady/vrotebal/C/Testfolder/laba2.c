#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
/*Объявить массив данных типа double размером 3 на 3.
Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной
диагонали и сумму элементов, расположенных на  побочной диагонали.
Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значе-ния, вывести на консоль квадрат данной матрицы.
Цикл добавить*/
int main()
{
   int size = 0;
   int z;
   do
   {
      printf("Vvedite razmernoct: ");
      scanf("%d", &size);
      int mainAxis = 0;
      int secondaryAxis = 0;
      double m[size][size];
      for (int i = 0; i < size; i++)
      {
         for (int j = 0; j < size; j++)
         {
            printf("m[%d][%d]= ", i, j);
            scanf("%lf", &m[i][j]);
         }
      }
      for (int i = 0; i <= size - 1; i++)
      {
         mainAxis += m[i][i];
         secondaryAxis += m[i][(size - 1) - i];
      }
      printf("Main axis sum: %d\nSecondary axis sum: %d\n", mainAxis, secondaryAxis);
      int size1 = 0;
      printf("Vvedite razmernoct: ");
      scanf("%d", &size1);
      int g[size1][size1];
      int r[size1][size1];
      for (int i = 0; i < size1; i++)
      {
         for (int j = 0; j < size1; j++)
         {
            printf("g[%d][%d]= ", i, j);
            scanf("%d", &g[i][j]);
         }
      }

      for (int i = 0; i < size1; i++)
      {
         for (int j = 0; j < size1; j++)
         {
            r[i][j] = 0;
            for (int n = 0; n < size1; n++)
            {
               r[i][j] += g[i][n] * g[n][j];
            }
         }
      }
      for (int i = 0; i < size1; i++)
      {
         for (int j = 0; j < size1; j++)
         {
            printf("%d ", r[i][j]);
         }
         printf("\n");
      }
      printf("Enter 1 to continue or any other number to exit: ");
      scanf("%d", &z);
   } while (z == 1);
   return 0;
}
//готово