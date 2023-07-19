#include <stdio.h>
#include <conio.h>

typedef enum {false,true} boolean;

struct point
{
 int x;
 int y;
};

struct rectangle
{
 struct point lt;
 struct point rb;
};

boolean  PtInRectangle(struct point p,struct rectangle r)
{
 if(  p.x > r.lt.x  && p.x < r.rb.x  &&  p.y > r.lt.y  && p.y < r.rb.y  )
	 return true;
 else
	 return false;
}

void main()
{
  struct point p;
  struct rectangle r;

  clrscr();

  p.x =9 ; p.y = 19;
  r.lt.x = 10 ; r.lt.y=10;
  r.rb.x = 20; r.rb.y=20;

  if(PtInRectangle(p,r))
	printf(" The point is inside ");
  else
	printf(" The point is outside ");

 getch();
}