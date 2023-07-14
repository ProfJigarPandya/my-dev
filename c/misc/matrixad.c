/* addition of two matrices

   _           _         _               _                _              _
  |  2  4   3   |       |  3    5     7  |                |   5   9    10  |
  |             |    +                          =
  |  5  8   7   |       |  4    4     7  |                |   9   12   14  |
  |             |
  |_ 4  7   0  _|       |_  5    4    8 _|                |_   9   11   8 _|


*/


#include <stdio.h>
#include <conio.h>

void main()
{

int a[3][3],b[3][3],c[3][3];
int i,j;
clrscr();

for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
	scanf("%d",&a[i][j]);
  }
}


for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
	scanf("%d",&b[i][j]);
  }
}

for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
	c[i][j] = a[i][j]  + b[i][j];
  }
}


for(i=0;i<3;i++)
{
  for(j=0;j<3;j++)
  {
	printf("\t%3d",c[i][j]);
  }
  printf("\n");
}











getch();
}