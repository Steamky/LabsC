
#include <stdio.h>
#include <math.h>
#include <string.h>


int main(int argc, char *argv[]){
    
    double a=0, b=0, c=0; 
    double x, x1, x2, d, soglacie = 1;
    char word[1024];
    char yes[1024]="Yes";

    
    do
    {
        printf("Insert Yes or No\n");
    scanf("%s", word);

    if (strcmp (word, yes) == 0) {
        soglacie = 1;
    }
    else { 
        soglacie = 0;
        return 0;
    }

        printf("Insert numbers:\n");
        scanf( "%lf %lf %lf", &a,&b,&c);
        
        

        d = b*b - 4*a*c;
        printf("d = %lf\n", d);
        if (d > 0) {
            x1 = ( -b+sqrt(d))/(2*a);
            x2 = ( -b-sqrt(d))/(2*a);

            printf("x1=%lf x2=%lf", x1,x2);
        }
        else if (d == 0.000000) {
            x = (-b/(2*a));
            printf("x=%lf", x);

        }
        else if (d < 0) {
            printf("There are no roots, because %lf<0\n",d);
        }
    } while (soglacie == 1);

    return;



}