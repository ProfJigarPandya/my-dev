/* function with argument and
 with  return type

  findmax(a,b)

*/

#include <stdio.h>
#include <conio.h>

int findmax(int a,int b)
{
  if(a>b)
	return a;
  else
	return b;
}

void main()
{

 int x=10,y=20,z;
 clrscr();

 z = findmax(x,y);

 printf("\nThe maximum is %d",z);


 printf("\nThe maximum is %d",findmax(5,8));

 getch();
}