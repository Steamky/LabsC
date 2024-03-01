#include <string.h>
#include <stdio.h>
#include <math.h>

double perimetr_triangle(int a, int b, int c)
{
    int perimetr;
    

    perimetr = a + b + c;
    printf("perimetr:%d\n", perimetr);
    return 0;
}

double square_triangle(int a, int b, int c)
{
    double square;
    double poluperimetr;

    poluperimetr =(double) (a+b+c) / 2;
    square = sqrt(poluperimetr*(poluperimetr - a)*(poluperimetr - b)*(poluperimetr - c));
    printf("square:%lf\n", square);

    return 0;

} 