#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <graphics.h>
#include <dos.h>

void main()
{

   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   int maxx=getmaxx(),maxy=getmaxy(),midy=maxy/2;
   int x=maxx;
   settextstyle(3,0,5);
   setfillstyle(0,BLACK);
   setcolor(RED);
   setbkcolor(YELLOW);
   rectangle(50,50,maxx-50,maxy-50);
   while(!kbhit())
   {
     outtextxy(x,midy-25,"JAY GAYATRI MAA");
     moveto(x+350,midy-25);
     delay(700);
     bar(x,midy-30,x+360,midy+30);
     x=x-100;
      if(getx()<50){ x=maxx; }
   }



}//end of main
