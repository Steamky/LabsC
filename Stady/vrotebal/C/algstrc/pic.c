#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, current;
 int N[100],M[100];
 char **pic[100];

void input(int cur, char *filename)
{
 FILE *F;
 char str[512], Pic[512][512];
 int i, len;
   len=0; m=0;
   F=fopen(filename,"r");
   while (fgets(str,512,F))
   {
     n= strlen(str);
     if (str[n-1]=='\n') n--;
     len = n;
     strncpy(Pic[m], str,n);  
     m++; 
   } 
//  if (pic[cur]) freepic(cur);
  pic[cur]=(char **)malloc(m*sizeof(char *));
  for (i=0; i<m; i++) 
    {
     pic[cur][i]=(char *)malloc(n); 
     strncpy(pic[cur][i],Pic[i],n);
    }
   N[cur]=n;
   M[cur]=m;
  printf("m=%d n=%d\n",m,n);
}

void output(int num)
{
  int n,m,i,j;
  printf(" Picture # %d\n",num);
  m=M[num]; n=N[num];
  for (i=0; i<m; i++)
   {
    for (j=0; j<n; j++)
      putchar(pic[num][i][j]);
    putchar('\n');
   }
 
}
int main(int argc, char *argv[])
{
  FILE *F, *FO;
  int i;
  char filename[256]="pic1.txt";
  char str[512], *f;
   for(i=0; i<100; i++) pic[i]=NULL;
   F=fopen(filename,"r");
   input(0,filename);
   output(0);
   input(1,"pic2.txt");
   output(1);
   output(0);
   input(2,"picB.txt");
   output(2);
   
  fclose(F);
   return 0;
}
 