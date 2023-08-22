/*Pattern I
e.g. for n = 4 following pattern should be printed
0123
 456
  78
   9
*/
#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n,r,c;
	scanf("%d",&n);
	int data=0;
	for(r=1;r<=n;r++)
	{
		for(c=1;c<r;c++)
		{
			printf(" ");
		}
		for(c=1;c<=(n-r+1);c++)
		{
			printf("%d",data++);
		}
		if(r<n)//No need to print a newline after the last line printed.
			printf("\n");
	}
    return 0;
}
