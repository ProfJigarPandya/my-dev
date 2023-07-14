//#include <iostream.h>
#include <stdio.h>
#include <conio.h>
void strrev(char arr[],int n)
{
  static int i=n;
  char ch;
  ch=arr[i-n];
   if(n!=0)
	strrev(arr,n-1);
   printf("%c",ch);
}

void main()
{

 char arr[]="abcdef";
 strrev(arr,6);
}
