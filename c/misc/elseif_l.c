/*	display the grade of student depending on his/her marks entered */

/*	percentege range		GRADE

/*	80 to 100           	HONOURS
	71 to 80		DISTINCTION_CLASS
	61 to 70		FIRST _CLASS
	51 to 60		SECOND_CLASS
	35 to 50		PASS_CLASS
	0 to 34			FAIL      				*/


#include <stdio.h>
#include <conio.h>

enum grade {HONOURS=-1,DISTINCTION,FIRST_CLASS,SECOND_CLASS,PASS_CLASS,FAIL};



void main()
{
int p_marks;
enum grade g;

clrscr();

printf("\n enter the percentage ");
scanf("%d",&p_marks);

if(p_marks>80 && p_marks<=100)
{
	g=HONOURS;
}
else if(p_marks>70 && p_marks<=80)
     {
	g=DISTINCTION;
     }
     else if(p_marks>60 && p_marks<=70)
	  {
	     g=FIRST_CLASS;
	  }
	  else if(p_marks>50 && p_marks<=60)
	       {
		  g=SECOND_CLASS;
	       }
	       else if(p_marks>34 && p_marks<=50)
		     {
			g=PASS_CLASS;
		     }
		     else if(p_marks>=0 && p_marks<=34)
			  {
			     g=FAIL;

			  }
			  else
			  {
				printf("\n Invalid input - must inbetween 0 to 100");
			  }

printf("\n YOUR GRADE IS %d ",g);


printf("\nhave a nice day");

getch();

}