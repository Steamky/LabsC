#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   clock_t start_time = clock();
   srand(time(NULL));
   int N;

   printf("Insert number of random numbers: ");
   scanf("%d", &N);

   int numbers[N];

   for (int i = 0; i < N; i++)
   {
      numbers[i] = rand() % 101;
   }

   FILE *fp = fopen("input.txt", "w");

   for (int i = 0; i < N; i++)
   {
      fprintf(fp, "%d\n", numbers[i]);
   }

   fclose(fp);

   for (int i = 0; i < N; i++)
   {
      numbers[i] = 0;
   }

   FILE *input_file = fopen("input.txt", "r");
   FILE *output_file = fopen("output.txt", "w");

   int number;
   while (fscanf(input_file, "%d", &number) != EOF)
   {
      if (number % 5 == 0 && number % 7 == 0)
      {
         fprintf(output_file, "ПЯТЬСЕМЬ ");
      }
      else if (number % 5 == 0)
      {
         fprintf(output_file, "ПЯТЬ ");
      }
      else if (number % 7 == 0)
      {
         fprintf(output_file, "СЕМЬ ");
      }
      else
      {
         fprintf(output_file, "%d ", number);
      }
   }

   fclose(input_file);
   fclose(output_file);

   input_file = fopen("input.txt", "r");
   int M;

   printf("enter the number of columns: ");
   scanf("%d", &M);

   int matrix[N / M][M];
   int i = 0, j = 0;

   while (fscanf(input_file, "%d", &number) != EOF)
   {
      matrix[i][j] = number;
      j++;
      if (j == M)
      {
         j = 0;
         i++;
      }
   }

   fclose(input_file);

   int row_sums[N / M], col_sums[M];
   for (i = 0; i < N / M; i++)
   {
      row_sums[i] = 0;
      for (j = 0; j < M; j++)
      {
         row_sums[i] += matrix[i][j];
      }
   }

   for (j = 0; j < M; j++)
   {
      col_sums[j] = 0;
      for (i = 0; i < N / M; i++)
      {
         col_sums[j] += matrix[i][j];
      }
   }

   printf("matrix:\n");
   for (i = 0; i < N / M; i++)
   {
      for (j = 0; j < M; j++)
      {
         printf("%d\t", matrix[i][j]);
      }
      printf("\n");
   }

   printf("sum row: ");
   for (i = 0; i < N / M; i++)
   {
      printf("%d ", row_sums[i]);
   }
   printf("\n");

   printf("sum columns: ");
   for (j = 0; j < M; j++)
   {
      printf("%d ", col_sums[j]);
   }
   printf("\n");

   clock_t end_time = clock();
   double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
   printf("time running program: %f second\n", elapsed_time);
   return 0;
}
