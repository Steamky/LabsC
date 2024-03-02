#include <stdio.h>
#include <math.h>

double trapezoidal_rule(double z, double eps) {
    int n = 1;
    double prev_result = 0;
    
    while (1) {
        double h = z / n;
        double result = 0;
        
        for (int i = 1; i < n; i++) {
            double x = i * h;
            result += sinh(x) * sin(x);
        }
        
        result += (sinh(0) * sin(0) + sinh(z) * sin(z)) / 2;
        result *= h;
        
        if (fabs(result - prev_result) < eps) {
            return result;
        }
        
        prev_result = result;
        n *= 2;
    }
}

int main() {
    double start = 0;
    double end = 10;
    double step = 0.2;
    double eps = 1e-7;
    
    printf("Z\t\tIntegral\n");
    printf("------------------------------\n");
    for (double z = start; z <= end; z += step) {
        double integral = trapezoidal_rule(z, eps);
        printf("%f\t%f\n", z, integral);
    }
    
    return 0;
}
