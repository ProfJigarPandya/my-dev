#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%ld\n",a+b);//Note that addition of two numbers may generate bigger than int
	printf("%d\n",a-b);
	printf("%ld\n",a*b);//Note that multiplication of two numbers may generate bigger than int
	printf("%d",a/b);
    return 0;
}

