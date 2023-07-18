#include <stdio.h>
int main()
{
 int ch;
 while((ch=getchar())!=EOF) 
 	printf("%c",ch);

 printf("\nEOF is %d",ch);
 printf("\nEOF is %d",EOF);
 return 0;
}
