
#include <stdio.h>
#include <stdbool.h>
#include "triangle.h"

int main()
{
   double a, b, c;
   printf("Insert sides of triangle:\n");
   scanf("%lf %lf %lf", &a, &b, &c);
   if (proverka_vernosti(a,b,c) == false)
   {
    printf("Triangle dont exist\n");
   }
   else
   {
   double perimeter = perimetr_triangle(a, b, c);
   double square = square_triangle(a, b, c);
   printf("perimeter = %lf\nsquare = %lf\n", perimeter, square);
   }
}