/* odd input
 * 
 *
n=7
Pattern
A B C D E F G F E D C B A
A B C D E F E D C B A
A B C D E D C B A
A B C D C B A
A B C B A
A B A
A 

 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n;
	int line;
	char ch='A';
	int fwd,bwd;
	scanf("%d",&n);
	if(!(n%2))//even input
		return 1;
	

	for(line=1;line<=n;line++)
	{
		ch='A';
		for(fwd=1;fwd<=(n-line);fwd++)
		{
			printf("%c ",ch++);
		}
		
		printf("%c",ch);
		
		for(bwd=(n-line);bwd>=1;bwd--)
		{
			printf(" %c",--ch);
		}
		printf("\n");
	}
	
    return 0;
}

