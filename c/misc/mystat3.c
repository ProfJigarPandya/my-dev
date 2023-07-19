#include <stdio.h>
#include <conio.h>

 int deposit(int amt)
 {
  static int total=0;

  total+=amt;

  return total;
 }

 void main()
 {
  clrscr();
  deposit(500);
  deposit(600);
  deposit(700);
  deposit(800);

  printf("%d",deposit(400));

  getch();

 }


