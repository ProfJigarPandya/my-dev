#include <stdio.h>
#define MAX 100
int strindex(char source[], char part[]);
int main()
{
 
 int ind;
 char source[MAX];
 char part[MAX];

 printf("\n Enter source ");
 scanf("%[^*\n]",source);

 getchar();
 printf("\n Enter part ");
 scanf("%[^*\n]",part);

 getchar();

 if((ind=strindex(source,part))!=-1)
	printf("\nString '%s' is a located at index %d in '%s'. (Know that index assumed to be 0  as beginning of string)",part,ind,source);
 else
	printf("\nString '%s' is not found in '%s'",part,source);

 printf("\n");

 return 0;
}
int strindex(char source[], char part[])
{
   char *p=part,*s=source;

   while(*p!='\0' && *s!='\0')
   {
    if(*s==*p)
	p++;
    else
	p=part;

    s++;
   }
  
   if(*p=='\0')
	return (s-source-(p-part));
   else
	return -1;

}
