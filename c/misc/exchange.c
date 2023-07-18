#include <stdio.h>

void exchange(int a, int b);
int main()
{
 int a=10, b=20;
 exchange(a, b);
 printf("\n a now is %d",a);
 printf("\n b now is %d",b);
}
void exchange(int a, int b)
{
 int temp;
 temp = a;
 a=b;
 b=temp;
}
