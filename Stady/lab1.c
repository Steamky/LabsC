#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Здесь должно быть первое задание. 







*/

int main(int argc, char *argv[]){
    double a=0,b=0,c=100;
    double x1,x2,d=0;

    a=5;
    b=6;
    c=1;

    d = b*b - 4*a*c;
    printf("d = %lf"\n, d);

    x1= (-b+sqrt(d))/(2*a);
    x2= (-b-sqrt(d))/(2*a);

    printf("x1=%lf x2=%lf", x1, x2);


    return;


}