//Trying to learn runtime error
#include <stdio.h>
int main()
{
 int a,b;
 float res;
 printf("Enter a and b");
 scanf("%d%d",&a,&b);
 res = 500/(a-b);
 printf("Result is %f",res);
 return 0;
}
