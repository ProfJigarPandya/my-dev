/* program for finding no. of students falls in the range
of marks
Range    0-9  10-19  20-29 .........90-99. and exactly 100.
Group     0    1      2               9                 10

    total no. of students            15;
    */


#include <stdio.h>
#include <conio.h>

void main()
{

 int range[11]={0};
 int pmark;
 int i;

 clrscr();


printf("\n enter mark");
for(i=1;i<=5;i++)
{

  scanf("%d",&pmark);

  if(pmark <0  || pmark>100)
   {
	printf("\n invalid no.");
	i--;
   }
   else
	range[pmark/10]++;

}

printf("\n Group		No. Of students ");
for(i=0;i<11;i++)
{
  printf("\n%7d",i+1);
  printf("\t\t%10d",range[i]);
}

 getch();



}


