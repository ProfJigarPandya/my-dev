#include <stdio.h>
#include <stdlib.h>
/* Language L={a^ib^2i|i>=1}
   Set of production rules
   T={a,b}//Set of terminals
   N={S} //set of non-terminals
   Starting state S
   P //set of production rules
   S->aSbb
   S->abb
 *
 */
void aib2i(int i)
{
	if(i<=0)
	{
		printf("Undefinded");
		exit(-1);
	}

	if(i==1)
	{
		printf("abb");
	}
	else
	{
		printf("a");
		aib2i(i-1);
		printf("bb");
	}
}
int main()
{
	int i;
	scanf("%d",&i);
	aib2i(i);
	return (0);
}
