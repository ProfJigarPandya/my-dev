
  /*  CALENDAR GENERATING PROGRAM
	       BASED ON -> 01/01/1900 WAS MONDAY
	       last year 2079 A.D  calemdar can be view		     */

#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <process.h>
void draw_cal(int l_date,int f_day);
void main()
{
      clrscr();
      int month,year;
      cout<<"\n ENTER MONTH IN DIGIT: ";
      cin>>month;
       if(month>12){
	     cout<<"\n INVALID MONTH NUMBER , enter month in digit again ";
	     cin>>month;
	     if(month>12){ cout<<"\n IMPROPER USE OF COMPUTER ";exit(0);}
       }
      cout<<"\n ENTER YEAR  : ";
      cin>>year;
      if(year<1900){
		cout<<"\n SORRY , IT'S OUT OF RANGE FOR CALENDAR CALCULATION ";
		exit(0);
      }

      unsigned int totaldays=0;
      unsigned int diff_year;
      diff_year = year - 1900;


      /////////count no. of leap years inbetween 1900 & entered year ..
      /////////except last year itself...
       int ly_count=0,nly_count;//leap year count & non-leap year count..
       for(int i=1900;i<year;i=i+1){
		if(i%4==0){
		      ly_count++;
		}
       }
       cout<<"\n total no of leap years are "<<ly_count;
       nly_count = diff_year - ly_count;
       cout<<"\n total no of non-leap years "<<nly_count;
       cout<<"\n total years difference : "<<diff_year;
      ////////////



       /////calculate totol days .. from base to entered month ...
       totaldays = (365 * nly_count) + (366 * ly_count);
       cout<<"\n totoaldays 1.."<<totaldays;
       unsigned int lastday;
       if(nly_count<133){         // to fit in unsigned range 65535 >= (134 *365 + 45*366 =65380)
	       lastday = (totaldays % 7);
		cout<<"\n first day of  year >> that's 1'st JAN is "<<lastday;
		//firstday = 1 means mon ,2 means tue ...
       }
       else{
	       totaldays = 0;
	       cout<<"\n SORRY , out of range from calendar  ...";
	       exit(0);
       }


       //////find out upto month's 1'st date .......

       /////////is last year a leap year ?
       int LEAP=0;
       if(year%4==0){
	   cout<<"\n entered year is LEAP YEAR ";
	   LEAP = 1;
       }
      ///////////// so , feb month has 29 days to calculate ..

       ///// calculate no. of months in last year ..
       int month_count;
       month_count = month - 1;
       ///////////

       /* jan 31
	  feb 28/29 ,mar 31,apr 30,may 31,jun 30,july 31,aug 31,sep 30,
	  oct 31,nov 30,dec 31                                   */
 for(int j=1;j<=month_count;j++){
   switch(j){

      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
		totaldays+=31;
		break;
      case 2:
		if(LEAP==1)
		      totaldays+=29;
		else
		      totaldays+=28;
		break;


      case 4:
      case 6:
      case 9:
      case 11:
		totaldays+=30;
		break;
      default:
		cout<<"\n error in month days calculating...";
    };
 }
      cout<<"\ntotaldays 2.."<<totaldays;
      lastday = (totaldays % 7);
      cout<<"\n first day of entered year & month is "<<lastday;

      getch();
      clrscr();

      cout<<"\n    CALENDAR               ";
      cout<<"MONTH  "<<month<<" of "<<year<<" YEAR \n";
  switch(month){
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
		draw_cal(31,lastday);
		break;
      case 2:
		if(LEAP==1)
		      draw_cal(29,lastday);
		else
		      draw_cal(28,lastday);

		break;
      case 4:
      case 6:
      case 9:
      case 11:
		draw_cal(30,lastday);
		break;
      default:
		cout<<"\n error in month days calculating...";
    };

	_setcursortype(_NOCURSOR);
	getch();
}//end of main
void draw_cal(int l_date,int f_day){

	cout<<f_day;
	gotoxy(15,5);

	cout<<"SUN     MON     TUE     WED     THU     FRI     SAT  ";
       //	cout<<"MON     TUE     WED     THU     FRI     SAT     SUN  ";
	int init_x=15,init_y=7,dist=8;
	for(int i=1;i<=l_date;i++){
		     gotoxy(init_x+(f_day*dist),init_y);
		     cout<<i;
		     f_day++;
			     if(f_day==7){
				     init_y++;
				     f_day=0;                     //SUNDAY
			      }
	}

}

