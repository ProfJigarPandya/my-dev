/*
		1   2   3   4 	5	
				6
				7
				8
	        .  .  .  11 10	9
*/
#include <conio.h>
#include <stdio.h>

int main(void)
{
   int n=15,i,j,value,leftup,times,x,y;

   clrscr();

   value=1;
   times=n;
   x=5;y=5;

   while(1)
   {
	if(times==n) //once	 horizontal
	{
	      for(i=1;i<=n;i++)
	      {
		gotoxy(x,y);
		printf("%d",value++);
		delay(100);
		x+=5;
	      }
	      x-=5;
	      y++;//next line
	      times--;
	      leftup=1;
	}
	else //twice
	{
		//1	vertical
		for(i=1;i<=times;i++)
		{
			gotoxy(x,y);
			printf("%d",value++);
			delay(100);
			if(leftup==0)
				y--;
			else
				y++;
		}

		 y = leftup==0 ? y+1 : y-1;
		 x = leftup==0 ? x+5 : x-5;

		//2	horizontal
		for(i=1;i<=times;i++)
		{
			gotoxy(x,y);
			printf("%d",value++);
			delay(100);
			if(leftup==0)
				x+=5;
			else
				x-=5;
		}

		x = leftup == 0 ? x-5 : x+5;//undo
		y = leftup == 0 ? y+1 :  y-1 ;
		times--;
		leftup = leftup == 0 ? 1 : 0;
	}

	if(value>n*n)
		break;
   }

   getch();
   return 0;
}
