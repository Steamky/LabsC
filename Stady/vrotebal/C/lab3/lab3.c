
#include <stdio.h>
#include <ctype.h>


int main()
{
   int stroka[1024];
   printf("Input any word:\n");
   scanf("%d", &stroka);

   printf("%d in rework type is: %d", stroka, toupper(stroka));

   return 0;
}
