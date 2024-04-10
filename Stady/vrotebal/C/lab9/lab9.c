#include <stdio.h>
#include <string.h>


int main()
{
    char primer[1024];
    char* sapprimer1;
    char* sapprimer2;
    const char razd1[10] = "+";
    const char razd2[10] = "-";
    printf("Insert your math primer:\n");
    scanf("%s",&primer);
    sapprimer1 = strtok(primer, razd1);
    while (sapprimer1 != 0)
    {
        printf("%s\n", sapprimer1);
        sapprimer1 = strtok(0,razd1);
    }
    return 0;
}