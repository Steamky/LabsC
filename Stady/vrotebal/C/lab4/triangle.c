
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double perimetr_triangle(double a, double b, double c)
{
   double perimeter = a + b + c;
   return perimeter;
}
double square_triangle(double a, double b, double c)
{
   double poluperimeter = (a + b + c) / 2;
   double square = sqrt(poluperimeter * (poluperimeter - a) * (poluperimeter - b) * (poluperimeter - c));
   return square;
}
bool proverka_vernosti(double a, double b, double c)
{
    if (a+b > c && b+c >a && a+c>b)
{
    return true;
}
else
{
    return false;
}
}

