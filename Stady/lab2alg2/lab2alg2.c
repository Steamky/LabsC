#include <stdio.h>
#include <math.h>

double f(double x) {
    return sinh(x) * sin(x);
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        result += f(a + i * h);
    }

    return result * h;
}

int main() {
    double start = 0;
    double end = 10;
    double step = 0.2;

    printf("Z\t\tIntegral\n");
    printf("------------------------------\n");

    for (double z = start; z <= end; z += step) {
        double integral = trapezoidal_rule(0, z, 1000);
        printf("%f\t%f\n", z, integral);
    }

    return 0;
}
