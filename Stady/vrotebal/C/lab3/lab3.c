
#include <stdio.h>
#include <ctype.h>


int main()
{
   char str[81];
   printf("Insert any word: \n");
   fgets(str,81,stdin);
   printf("%s", str);
   for (int i = 0; i < 80; i++)
   {
      if (str[i] == "a" || str[i] == "b")
      {
         str[i] = str[i]+32;
      }
   }
   printf("%s", str);
   return 0;
}
