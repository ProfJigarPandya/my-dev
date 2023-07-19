/* 
Program to find nth term of fibbonaci.
0 1 1 2 3 5 ...
*/
#include <stdio.h>

int fibbor(int n)
{
 if(n==0)
	return 0;
 else if (n==1)
	return 1;
 else
	return (fibbor(n-1)+fibbor(n-2));
}

int main()
{
 int n;
 int result;
 printf("\n Enter value of n for finding nth term of fibbo");

 scanf("%d",&n);
 result = fibbor(n);
 printf("\n Result is %d ",result);

 //printf("\n Result is %d ",fibbor(7));
 
 //printf("\n Result is %d ",fibbor(getchar()-'0'));

 return 0;
}
