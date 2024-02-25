#include <string.h>
#include <stdio.h>
#include <math.h>

double parametr_triangle(int a, int b, int c)
{
    int perimetr;
    double square;
    double poluperimetr;

    perimetr = a + b + c;
    poluperimetr =(double) perimetr / 2;
    square = sqrt(poluperimetr*(poluperimetr - a)*(poluperimetr - b)*(poluperimetr - c));
    printf("perimetr:%d\nsquare:%lf\n",perimetr, square);

    return 0;

} 