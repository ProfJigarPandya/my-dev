/* Documentation section */
/* 
	1_3useofnl.C	

	PROGRAM FOR illustrating use of \n and \t with printf 
	
	AIM: to print following triangle using singlt printf statement
	
	*
	*	*
	*	*	*


	
	PROGRAMMER:  J.M.PANDYA

	NO INPUT.... 
*/


/* link section */
#include <stdio.h>       /* As printf() is declared in stdio.h */
#include <conio.h>	 /* to use clrscr() and getch() */


/* starting point of the program */
void main()
{  
  /*Declaration part empty      */		
	
	
  /* Executable part  */
  clrscr();	/* clears the monitor screen on starting */

  printf("*\n*\t*\n*\t*\t*\n");   
			
			/* %f indicates that result of PI*5.4*5.4 will be float */
							
  getch(); 	
}   /* end of program */
