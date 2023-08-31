//Count spaces, tabs and newlines in the input entered by the user using while and getchar.
//DO NOT use arrays or strings.
#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int totalSpaces=0, totalTabs=0, totalNewLines=0;
	int ch;//Note that EOF is defined as -1 and hence we need this datatype to be int and not char.
	do
	{
		ch = getchar();
		if(ch==' ')
		{
			totalSpaces++;
		}
		else if(ch=='\t')
		{
			totalTabs++;
		}
		else if(ch=='\n')
		{
			totalNewLines++;
		}
	}while(ch!=EOF);
	printf("%d %d %d",totalSpaces,totalTabs, totalNewLines);
    return 0;
}
