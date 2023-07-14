#include <stdio.h>
#include <conio.h>
void main()
{
       int x,y,flag=0;
       clrscr();
       printf("enter two no. ");
       scanf("%d%d",&x,&y);

       if(y!=0)
       {
	  printf("\ndivision  %d",x/y);
	  flag=1;
       }

       if(flag==0)
       {
	printf("\n sorry ........\n can't do because of division by zero error  ");
       }

       getch();

}