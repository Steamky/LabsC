
#include <stdio.h>
#include <math.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
  int i, j, k, g, h;
  int size, size2 = 0;
  char word[1024];
  char yes[1024]="Yes"; 
  do
  {
    printf("Insert number of size:\n");
    scanf("%d", &size);
    int mainaxis = 0, secondaxis = 0;  
    double a[size][size];
    for (i = 0; i < size; i++)  
    {
      for (j = 0; j < size; j++) 
      {
        printf("a[%d][%d] = ", i, j);
        scanf("%lf", &a[i][j]);
      }
    }

    for (i = 0; i<size; i++)  
    {
      for (j = 0; j<size; j++) 
      {
        printf("%lf ", a[i][j]);
      }
    printf("\n"); 
    }

    for (int i = 0; i <= size-1; i++) {
          mainaxis += a[i][i];
          secondaxis += a[i][(size-1)-i];
      }

    
    printf("Mainaxis = %d \nSecondaxis = %d \n", mainaxis, secondaxis);

    printf("Insert nubmer of size2:");
    scanf("%d", &size2);

    int b[size2][size2], c[size2][size2];
    for(g = 0; g<size2; g++)
    {
      for(h = 0; h<size2; h++)
      {
        printf("b[%d][%d] = ", g, h);
        scanf("%d", &c[g][h]);
      }
    }

    for (g = 0; g<size2; g++)
    {
      for (h = 0;h<size2; h++)
      {
        printf("%d ", c[g][h]);
      }
      printf("\n");
    }

    for(g=0; g<size2; g++) 
    {
      for(h=0; h<size2; h++) 
      {
      b[g][h] = 0;
      for(k=0; k<size2; k++)
      {
        b[g][h] += c[g][k]*c[k][h];
        }
      }
    }
      
    for (g = 0; g<size2; g++)  
    {
      for (h = 0; h<size2; h++) 
      {
        printf("%d ", b[g][h]);
      }
      printf("\n"); 
    }
    printf("Insert Yes or No\n");
    scanf("%s", word);
  } while (strcmp (word, yes) == 0);
  return 0;
}