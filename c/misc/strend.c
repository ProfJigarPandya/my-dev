#include <stdio.h>
#define MAX 100
int strend(char source[], char tail[]);
int main()
{
 
 char source[MAX];
 char tail[MAX];

 printf("\n Enter source ");
 scanf("%[^*\n]",source);

 getchar();
 printf("\n Enter tail ");
 scanf("%[^*\n]",tail);

 getchar();
 if(strend(source,tail))
	printf("\nString '%s' is a tail of '%s'",tail,source);
 else
	printf("\nString '%s' is not tail of '%s'",tail,source);

 printf("\n");
 return 0;
}
int strend(char source[], char tail[])
{
   char *t=tail;
   while(*source!='\0')
   {
    if(*source==*t)
	t++;
    else
	t=tail;

    source++;
   }
  
   if(*t=='\0')
	return 1;
   else
	return 0;

}
