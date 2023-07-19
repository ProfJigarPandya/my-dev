/* program for storing

   marks of three subjects for each 10 student */

#include <stdio.h>
#include <conio.h>

void main()
{

 int marks[10][3];
 int row,column,total=0,i;



 clrscr();

 //read data...
 for(row=0;row<10;row++)
 {
    for(column=0;column<3;column++)
    {
	printf("Enter marks for student %d        subject %d ",row,column);
	scanf("%d",&marks[row][column]);
    }
 }



 // Display total marks for individual  students....
 printf("\n Student rollNo   total");
 for(i=0;i<10;i++)
 {
	total = marks[i][0] + marks[i][1] + marks[i][2];
	printf("\n\t\t%2d\t%3d",i,total);
 }












 getch();
}