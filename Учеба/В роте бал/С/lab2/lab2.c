
#include <stdio.h>
#include <math.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int mainaxis, secondaxis;
    int i, j, k, g, h;
    double a[3][3];
    int b[2][2], c[2][2];
    char word[1024];
    char yes[1024]="Yes";
    double soglacie = 1; 

  do
  {
    printf("Insert Yes or No\n");
    scanf("%s", word);

    if (strcmp (word, yes) == 0) {
        soglacie = 1;
    }
    else { 
        soglacie = 0;
        return 0;
    }  
  mainaxis = 0, secondaxis = 0;  
  for (i = 0; i<3; i++)  
  {
    for (j = 0; j<3; j++) 
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%lf", &a[i][j]);
    }
  }

    for (i = 0; i<3; i++)  
  {
    for (j = 0; j<3; j++) 
    {
      printf("%lf ", a[i][j]);
    }
  printf("\n"); 
  }

  mainaxis += a[0][0] + a[1][1] + a[2][2];
  secondaxis += a[0][2] + a[1][1] + a [2][0];
  printf("Mainaxis = %i \nSecondaxis = %i \n", mainaxis, secondaxis);

  for(g = 0; g<2; g++)
  {
    for(h = 0; h<2; h++)
    {
      printf("b[%d][%d] = ", g, h);
      scanf("%d", &c[g][h]);
    }
  }

    for (g = 0; g<2; g++)
    {
      for (h = 0;h<2; h++)
      {
        printf("%d ", c[g][h]);
      }
      printf("\n");
    }

    for(g=0; g<2; g++) 
    {
      for(h=0; h<2; h++) 
      {
       b[g][h] = 0;
       for(k=0; k<2; k++)
       {
         b[g][h] += c[g][k]*c[k][h];
        }
      }
    }
    
    for (g = 0; g<2; g++)  
    {
      for (h = 0; h<2; h++) 
      {
        printf("%d ", b[g][h]);
      }
      printf("\n"); 
  }
  } while (soglacie == 1);
    return 0;

}