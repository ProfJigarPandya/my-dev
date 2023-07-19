/* odd or even decision
      use of do-while for more than one time use of the programm..........*/

#include <stdio.h>
#include <conio.h>

void main()
{
 char choice;
 int no;
 clrscr();
 do
 {
       printf("\nenter the no. ");
       scanf("%d",&no);

       if( no%2 == 0 )
		printf("\n No is even ");
       else
		printf("\n No is ODD ");

       printf("\n Do you want to continue ? (press 'y'	for yes) ");

       fflush(stdin);

       scanf("%c",&choice);

 }while(choice=='y');


 getch();
}