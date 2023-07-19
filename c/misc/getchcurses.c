//Program to use getch in linux with curses library
//Compile program using option lcurses: gcc filename.c -lcurses
#include <stdio.h>
#include <stdlib.h>
#include <err.h> 
#include <curses.h>
int main()
{
	int ch;
	initscr ();
	//noecho ();
	echo();
	timeout (0);
	printf("Please, press any key");
	do
	{
		ch = getch();
	}
	while( ch == ERR);
	endwin ();

	printf("You pressed %d ",ch);
}
