//Find the maximum number of the two given numbers
#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	if(n1==n2)//both are same
		printf("%d",n1);
	else if(n1>n2)//n1 is greater
		printf("%d",n1);
	else//n2 is greater
		printf("%d",n2);
    return 0;
}
