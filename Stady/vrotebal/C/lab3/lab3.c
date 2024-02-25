#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main()
{
   char str1[81];
   printf("Insert any word: \n");
   fgets(str1,80,stdin);
   for (int i = 0; i < 80; i++){
    if (str1[i] =='a' || str1[i]=='b')
      {
        str1[i]=toupper(str1[i]);
      }
      
   }
   printf("%s", str1);
   return 0;
}