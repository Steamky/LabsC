#include <stdio.h>
#include <math.h>

#define EPS 1e-7
#define EULER 0.577215664901532860606512090082

double fst(double x)
{
    //fst(x) = 1 + x2/2! + x4/4! + x6/6! + x8/8! + ...
    double y = 0;
    int m = 0;
    // ... ... ...
    return y;
}

double sc(double x)
{
    //sc(x) = x + x3/3! + x5/5! + x7/7! + x9/9! + ...
    double y = 0;
    int m = 0;
    // ... ... ...
    return y;
}

double si(double x)
{
    double y = 0;
    double a = x;
    double t = a;
    int m = 2;
    
    while (fabs(t) > EPS)
    {
        y += t;
        a = -a * x * x / ((2*m-1) * 2 * m);
        t = a;
        m++;
    }

    return EULER + log(x) + y;
}


int main()
{
    double x;
    for (x = 0.5; x < 10; x += 0.2)
    {
        printf("%16.7lf %16.7lf\n", x, si(x));
        //printf("%16.8lf %16.8lf %16.8lf %16.8lf\n", sc(x), fst(x), sinh(x), cosh(x));
    }
    
    return 0;
}



