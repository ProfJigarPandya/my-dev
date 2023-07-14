#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
 int gdriver = DETECT,gmode;
 initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
 int x1,y1,x2,y2,x,y,dx,dy,leftx=0,lefty=0,p;float m;
 restorecrtmode();
 clrscr();
do{
 cout<<"\nENTER START PT. CO-ORDINATE :\n ";
 cin>>x1>>y1;
 cout<<"\nENTER END PT. CO-ORDINATE :\n ";
 cin>>x2>>y2;

 setgraphmode(getgraphmode());
 clearviewport();

 dx=x2-x1;
 dy=y2-y1;
 m=dy/dx;

   if(abs(dx)>abs(dy)){         //xstep
	if(x2>x1)
		leftx = 1;
	x=x1;y=y1;
	p=2*abs(dy)-abs(dx);

       for(int i=0;i<abs(dx);i++){
		if(leftx == 1)
			x=x+1;
		else
			x=x-1;

		if(p<0)
			p=p+2*abs(dy);
		else if(leftx==1){
		    if(m>0){ y=y+1;
			p=p+(2*abs(dy))-(2*abs(dx));
		    }
		    else{
			 y=y-1; //extra
			 p=p+(2*abs(dx))-(2*abs(dy));
		    }
		}
		else{
		if(m>0){
			 y=y+1;
			p=p+(2*abs(dy))-(2*abs(dx));
		}
		else {
			y=y-1; //extra
			p=p+(2*abs(dx))-(2*abs(dy));
		}
		}
	       putpixel(x,y,GREEN);
       }//end of for loop .
   } //end of if(abs(dx)>abs(dy)) loop.

   else{ //     here abs(dx)<abs(dy) ystep
	  if(y2>y1)
		lefty=1;
	  x=x1;y=y1;
	  p=2*abs(dx)-abs(dy);

	  for(int j=0;j<abs(dy);j++){
		if(lefty==1)
			y=y+1;
		else
			y=y-1;

		if(p<0)
			p=p+2*abs(dx);
		else if(lefty==1){
		if(m>0) {x=x+1;
			p=p+(2*abs(dx))-(2*abs(dy));
		}
		 else{ x=x-1;
		       p=p+(2*abs(dy))-(2*abs(dx));
		}
		}
		else{
		if(m>0){ x=x-1;
		       p=p+(2*abs(dx))-(2*abs(dy));
		}
		 else{ x=x+1;
		       p=p+(2*abs(dy))-(2*abs(dx));
		 }

		}
	      putpixel(x,y,RED);
	  }
   }
  getch();
  setcolor(YELLOW);
  line(x1,y1,x2,y2);
  outtextxy(300,300," press ESC to exit ");

  leftx=0;lefty=0;
  }while(getch()!=27);

 }//end of main