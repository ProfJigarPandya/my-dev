/* Given a list of marks....
pg 127. 5.10




*/

#include <stdio.h>
#include <conio.h>

void main()
{
 int marks;
 int above80=0,above60=0,above40=0,lesseq40=0;
 int ran81to100=0,ran61to80=0,ran41to60=0,ran0to40=0;
 clrscr();

 Start:
	printf("\n Enter marks for the student \n enter -1 to end entry");
	scanf("%d",&marks);
   if(marks!=-1)
   {
	if(marks>80)
	{
	    above80++;
	    ran81to100++;
	}
	else if(marks>60)
	     {
		    above60++;
		    ran61to80++;
	     }
	     else if(marks>40)
		  {
		    above40++;
		    ran41to60++;
		  }
		  else
		  {
			lesseq40++;
			ran0to40++;
		  }
	 goto Start;
   }

   printf("\n RESULT ");

   printf("\n No. of students \n\t who obtained more than 80 marks %d",above80);
   printf("\n\t who obtained more than 60 marks %d",above60);
   printf("\n\t who obtained more than 40 marks %d",above40);
   printf("\n\t who obtained 40 or less marks %d",lesseq40);
   printf("\n No. of students \n\t in the range 81 to 100  are %d",ran81to100);
   printf("\n No. of students \n\t in the range 61 to 80  are %d",ran61to80);
   printf("\n No. of students \n\t in the range 41 to 60  are %d",ran41to60);
   printf("\n No. of students \n\t in the range 0 to 40  are %d",ran0to40);
 getch();
}