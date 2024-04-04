#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Russian");
    char information[1024];
    char name[50],famil[50],otch[50];
    int god = 0;
    FILE *fileIN, *fileOUT;
    fileIN = fopen("list.txt","r+t");
    fileOUT = fopen("sort.txt","w+t");
    while (fgets(information,sizeof(information),fileIN) != NULL)
    {   
        sscanf(information,"%s %s %s %d\n",name,famil,otch,&god);
        printf("%s\n", name);
        if (god > 1980)
        {
            fprintf(fileOUT,"%s %s %s %d\n", name,famil,otch,god);
        }

    }
    printf("\n");
    fclose(fileIN);
    fclose(fileOUT);
    return 0;
}