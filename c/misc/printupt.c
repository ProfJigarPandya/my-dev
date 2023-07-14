#include <stdio.h>
#include <conio.h>

void printupto(int n)
{
  if(n==1)
  {
	printf(" 1 ");
	return;
  }
  else
  {
	printupto(n-1);
	printf(" %d ",n);
  }


}
void main()
{

 clrscr();
 printupto(50);
 getch();

}