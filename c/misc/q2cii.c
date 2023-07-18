#include <stdio.h>
void main()
{ 
 int a=25,b=20;
 { 
   int a=10;
   int c=a%b;
   printf("%d",c);
 }
 b=c;
 printf("%d",b); 
} 
