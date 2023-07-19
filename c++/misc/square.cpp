// no-square arrange game
// 1-08-2002

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <process.h>
#include <dos.h>

int maxx,maxy;

void draw_box()
{
   maxx = getmaxx();
   maxy = getmaxy();

   outtextxy(20,20, "press ESC to exit from game ");

   // squre
   line(maxx/2-100,maxy/2-100,maxx/2-100,maxy/2+100);
   line(maxx/2+100,maxy/2-100,maxx/2+100,maxy/2+100);
   line(maxx/2-100,maxy/2-100,maxx/2+100,maxy/2-100);
   line(maxx/2-100,maxy/2+100,maxx/2+100,maxy/2+100);

   //vertical lines
   line(maxx/2-100,maxy/2-50,maxx/2+100,maxy/2-50);
   line(maxx/2-100,maxy/2,maxx/2+100,maxy/2);
   line(maxx/2-100,maxy/2+50,maxx/2+100,maxy/2+50);

   //horizontal lines
   line(maxx/2-50,maxy/2-100,maxx/2-50,maxy/2+100);
   line(maxx/2,maxy/2-100,maxx/2,maxy/2+100);
   line(maxx/2+50,maxy/2-100,maxx/2+50,maxy/2+100);
}

void showtext(int temp,int xx,int yy)
{
  switch(temp){
	   case 1 :  outtextxy(xx,yy, "1");
		     break;
	   case 2 :  outtextxy(xx,yy, "2");
		     break;
	   case 3 :  outtextxy(xx,yy, "3");
		     break;
	   case 4 :  outtextxy(xx,yy, "4");
		     break;
	   case 5 :  outtextxy(xx,yy, "5");
		     break;
	   case 6 :  outtextxy(xx,yy, "6");
		     break;
	   case 7 :  outtextxy(xx,yy, "7");
		     break;
	   case 8 :  outtextxy(xx,yy, "8");
		     break;
	   case 9 :  outtextxy(xx,yy, "9");
		     break;
	   case 10 :  outtextxy(xx,yy, "10");
		     break;
	   case 11 :  outtextxy(xx,yy, "11");
		     break;
	   case 12 :  outtextxy(xx,yy, "12");
		     break;
	   case 13 :  outtextxy(xx,yy, "13");
		     break;
	   case 14 :  outtextxy(xx,yy, "14");
		     break;
	   case 15 :  outtextxy(xx,yy, "15");
		     break;
	   default:
		     setfillstyle(0,BLACK);
		     bar(xx-18,yy+2,xx+28,yy+48);
	 }; //end of switch
      moveto(xx,yy);
}    //end of showtext

int getkey()
{
 union REGS i,o;
 while(!kbhit());
 i.h.ah = 0;
 int86(22,&i,&o);
 return(o.h.ah);
}



void main()
{
 clrscr();
   int arr[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,0};
   // request auto detection
   int gdriver = DETECT, gmode, errorcode;

   // initialize graphics mode
   initgraph(&gdriver, &gmode,"c:\\tc\\bgi");

   // read result of initialization
   errorcode = graphresult();

   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             // return with error code
   }

  draw_box();

  settextstyle(4,HORIZ_DIR,3);

  int no,xleft,yup=100;
  for(int p=0;p<4;p++){
    xleft=80;
    for(int q=0;q<4;q++){
	 no=arr[p][q];
	 showtext(no,maxx/2-xleft,maxy/2-yup);
	 xleft-=50;
    }
    yup-=50;
  }

  int key,loop=1;
  int x=3,y=3,temp;

  while(loop){
   key = getkey();
	if(key == 1){   loop = 0;exit(0); }
	switch(key){
	    case 75 : //left
		       if(y!=0){
			    temp=arr[x][y];
			    arr[x][y]=arr[x][y-1];
			    arr[x][y-1]=temp;
			    no=arr[x][y];
			    showtext(no,getx(),gety());
			    no=0;
			    showtext(no,getx()-50,gety());
			    y--;
		       }
		       break;
	    case 72 :  //up
		       if(x!=0){
			    temp=arr[x][y];
			    arr[x][y]=arr[x-1][y];
			    arr[x-1][y]=temp;
			    no=arr[x][y];
			    showtext(no,getx(),gety());
			    no=0;
			    showtext(no,getx(),gety()-50);
			    x--;
		       }
		       break;
	    case 80 :   //down
		       if(x!=3){
			    temp=arr[x][y];
			    arr[x][y]=arr[x+1][y];
			    arr[x+1][y]=temp;
			    no=arr[x][y];
			    showtext(no,getx(),gety());
			    no=0;
			    showtext(no,getx(),gety()+50);
			    x++;
		       }
		       break;
	    case 77 :   //right
		       if(y!=3){
			    temp=arr[x][y];
			    arr[x][y]=arr[x][y+1];
			    arr[x][y+1]=temp;
			    no=arr[x][y];
			    showtext(no,getx(),gety());
			    no=0;
			    showtext(no,getx()+50,gety());
			    y++;
		       }
		       break;
	   default  :
		       cout<<"\nkey is"<<key;
   };
      if( x==3 && y==3){
	 if(arr[0][0]==1&&arr[0][1]==2&&arr[0][2]==3&&arr[0][3]==4&&arr[1][0]==5&&arr[1][1]==6&&arr[1][2]==7&&arr[1][3]==8&&arr[2][0]==9&&arr[2][1]==10&&arr[2][2]==11&&arr[2][3]==12&&arr[3][0]==13&&arr[3][1]==14&&arr[3][2]==15){
	     loop = 0;
	      clearviewport();
	      outtextxy(50,maxy/2, "CONGRATULATIONS , YOU HAVE DONE IT ");
	      getkey();
	 }
	 else
	     loop = 1;
      }

} //end of infinite while loop
  /* clean up */
   getch();
   closegraph();

} //end of main



