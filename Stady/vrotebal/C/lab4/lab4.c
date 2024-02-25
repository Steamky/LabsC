#include <string.h>
#include <stdio.h>

int main()
{
    int a, b, c;


    printf("Insert sides of triangle:\n");
    scanf("%d %d %d", &a, &b, &c);
    parametr_triangle(a, b, c);
    
    return 0;
}