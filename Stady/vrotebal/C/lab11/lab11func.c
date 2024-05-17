#include <stdarg.h>
#include "lab11func.h"

int sum(int cnt, ...) {
    va_list ap;
    int i, n;
    va_start(ap, cnt);
    n = 0;
    for (i = 0; i < cnt; i++) {
        n += va_arg(ap, int);
    }
    va_end(ap);
    return n;
}

int min(int cnt, ...) {
    va_list ap;
    int i, current, minimum;
    va_start(ap, cnt);
    minimum = va_arg(ap, int);
    for (i = 1; i < cnt; i++) {
        current = va_arg(ap, int);
        if (current < minimum)
            minimum = current;
    }
    va_end(ap);
    return minimum;
}

int max(int cnt, ...) {
    va_list ap;
    int i, current, maximum;
    va_start(ap, cnt);
    maximum = va_arg(ap, int);
    for (i = 1; i < cnt; i++) {
        current = va_arg(ap, int);
        if (current > maximum)
            maximum = current;
    }
    va_end(ap);
    return maximum;
}

double avg(int cnt, ...) {
    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, cnt);
    for (i = 0; i < cnt; i++) {
        sum += va_arg(ap, double);
    }
    va_end(ap);
    return sum / cnt;
}
