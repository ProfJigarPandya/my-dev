/* odd input
 * 
 *
n=7
Pattern
A B C D E F G F E D C B A
A B C D E F   F E D C B A
A B C D E       E D C B A
A B C D           D C B A
A B C               C B A
A B                   B A
A                       A

 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n;
	int line;
	char datachar,fillerchar,spacechar;
	int fwdchar, bwdchar;
	scanf("%d",&n);
	if(n==1)
	{
		printf("A");
		return 0;
	}

	fillerchar=' ';
	//fillerchar='f';
	spacechar=' ';
	//spacechar='*';
	for(line=1;line<=n;line++)
	{
		datachar='A';
		//print forward alphabet until middle location
		for(fwdchar=1;fwdchar<=(n-line);fwdchar++)//(n-line) times
		{
			printf("%c%c",datachar++,spacechar);
		}
		printf("%c",datachar++);
		
		for(fwdchar=(n-line+1);fwdchar<n;fwdchar++)
		{
			printf("%c%c",spacechar,fillerchar);
		}
		for(bwdchar=n;bwdchar>(n-line+1)+1;bwdchar--)
		{
			printf("%c%c",spacechar,fillerchar);
		}
		
		if(line==1)
		{	
			datachar--;
			for(bwdchar=(n-line+1)-1;bwdchar>1;bwdchar--)
			{
				printf("%c%c",spacechar,--datachar);
			}
		}
		else
		{
			for(bwdchar=(n-line+1);bwdchar>1;bwdchar--)
			{
				printf("%c%c",spacechar,--datachar);
			}
		}
		printf("%c%c",spacechar,--datachar);
		if(line<n)
			printf("\n");
	}
	
    return 0;
}

