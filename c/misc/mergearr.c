/*     merge two arrays...............*/




#include <stdio.h>
#include <conio.h>

void main()
{
int arr1[5]={1,2,3,4,5},arr2[5]={10,9,8,7,6},arr3[10];
int i,j;
clrscr();

/*for(i=0;i<10;i++)
{
       if(i<5)
	 arr3[i]=arr1[i];
       else
	 arr3[i]=arr2[9-i];
} */


  for(i=0;i<5;i++)
	arr3[i]=arr1[i];
  for(j=4;j>=0;j--,i++)
	arr3[i]=arr2[j];


for(i=0;i<10;i++)
	printf("\t%d",arr3[i]);


getch();
}