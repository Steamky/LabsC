#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
} POINT;

typedef struct poly
{
    int n;
    POINT *p;
} POLY;

double dist(POINT p1, POINT p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double perimeter(POLY p)
{
    double s = 0;
    for(int i = 0; i < p.n; i++)
    {
        s += dist(p.p[i], p.p[(i + 1) % p.n]);
    }
    return s;
}

double area(POLY p)
{
    double s = 0;
    for(int i = 0; i < p.n; i++)
    {
        s += p.p[i].x * p.p[(i + 1) % p.n].y;
        s -= p.p[i].y * p.p[(i + 1) % p.n].x;
    }
    return fabs(s) / 2.0;
}


double diameter(POLY p)
{
    double max = 0;
    for (int i = 0; i < p.n; i++)
    {
        for (int j = i + 1; j < p.n; j++)
        {
            double d = dist(p.p[i], p.p[j]);
            if (d > max)
            {
                max = d;
            }
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    FILE *F;
    POLY p;
    
    F = fopen(argv[1], "r");
    
    fscanf(F, "%d", &p.n);
    p.p = malloc(p.n * sizeof(POINT));
    for(int i = 0; i < p.n; i++)
    {
        fscanf(F, "%lf %lf", &p.p[i].x, &p.p[i].y);
    }
    
    printf("Периметр равен: %lf\n", perimeter(p));
    printf("Площадь равна: %lf\n", area(p));
    printf("Диаметр равен: %lf\n", diameter(p));
    
    free(p.p);
    fclose(F);
    
    return 0;
}


