//Print 5 even numbers from given number
#include <stdio.h>
#define TIMES 5
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int givenNumber;
	int i;
	scanf("%d",&givenNumber);
	if(givenNumber%2)
		givenNumber++;
	for(i=1;i<TIMES;i++)
	{
		printf("%d ",givenNumber);
		givenNumber+=2;
	}
	printf("%d",givenNumber);

    return 0;
}
