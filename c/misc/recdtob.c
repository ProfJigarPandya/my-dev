
#include <stdio.h>
#include <conio.h>

void dectobin(int n)
{
  if(n==1)
  {
	printf("1");
	return;
  }
  dectobin(n/2);
  printf(" %d ",n%2);
}

void main()
{

clrscr();
dectobin(119);
getch();

}

