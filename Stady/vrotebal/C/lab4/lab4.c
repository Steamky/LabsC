#include <string.h>
#include <stdio.h>

int main()
{
    int a, b, c;


    printf("Insert sides of triangle:\n");
    scanf("%d %d %d", &a, &b, &c);
    perimetr_triangle(a, b, c);
    square_triangle(a,b,c);    
    return 0;
}