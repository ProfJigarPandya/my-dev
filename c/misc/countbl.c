/* count no. of blanks tabs and newlines in input */

#include <stdio.h>
#include <conio.h>

void main()
{
 int nb=0,nt=0,nnl=0,nother=0,total=0;
 char ch;
 clrscr();
 while( ( ch=getchar())!=EOF)
 {
     if(ch==' ')
	nb++;
     else if(ch=='\t')
	nt++;
     else if(ch=='\n')
	nnl++;
     else
	nother++;


     total++;

 }

 printf("\n No. of blanks %d \n No. Of tabs %d \n No. Of new lines %d",nb,nt,nnl);
 printf("\n No. Of other chars %d ",nother);
 printf("\n No. Of total chars %d ",total);



 getch();
}