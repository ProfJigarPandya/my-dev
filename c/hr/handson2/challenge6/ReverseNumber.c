//Take an input from the user and print reverse of that number
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int input;
	scanf("%d",&input);//Length(input)=3
	printf("%d",input%10);
	input=input/10;
	printf("%d",input%10);
	input=input/10;
	printf("%d",input);
    return 0;
}

