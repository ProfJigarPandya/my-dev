//Detect if two integers have opposite signs
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	//1 if Signs are Opposite
	if((n1<0)&&(n2<0))//both negative
	{
		putchar('0');
	}
	else if((n1>=0)&&(n2>=0))//both 0 or positive
	{
		putchar('0');
	}
	else//both opposites
		putchar('1');


    return 0;
}

