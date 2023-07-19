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

/* for(i=0;i<11;i++)
	printf("\n %d",range[i]);*/
  printf("\n enter mark");
for(i=1;i<=15;i++)
{

  scanf("%d",&pmark);

  if(pmark>=0 && pmark<10)
	range[0]++;
  else if(pmark>=10 && pmark<20)
	range[1]++;
  else if(pmark>=20 && pmark<30)
	range[2]++;
  else if(pmark>=30 && pmark<40)
	range[3]++;
  else if(pmark>=40 && pmark<50)
	range[4]++;
  else if(pmark>=50 && pmark<60)
	range[5]++;
  else if(pmark>=60 && pmark<70)
	range[6]++;
  else if(pmark>=70 && pmark<80)
	range[7]++;
  else if(pmark>=80 && pmark<90)
	range[8]++;
  else if(pmark>=90 && pmark<100)
	range[9]++;
  else if(pmark==100)
	range[10]++;
  else
	printf("Invalid marks ");
}




printf("\n Group		No. Of students ");
for(i=0;i<11;i++)
{
  printf("\n%7d",i+1);
  printf("\t\t%10d",range[i]);
}

 getch();



}


/* if(pmark <0  || pmark>100)
   {
	printf("\n invalid no.");
	i--;
   }
   else
	range[pmark/10]++;

*/
