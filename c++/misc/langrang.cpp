#include <iostream.h>
#include <conio.h>
#define MAX 25

void main()
{
  long float num,den,x;int n;
  long float x_val[MAX],y_val[MAX],part[MAX];
  int yth,xth;
  int count=0;
  clrscr();
  cout<<"\n*  \" LANGRANGE'S INTERPOLATION FORMULA \"  FOR FINDING FUNCTION VALUE *";
  cout<<"\n\n\n\n ENTER  n >> NO OF READINGS WANT TO INSERT (int): ";
  cin>>n;


  cout<<"\n ENTER VALUES x_val[0..n] (float) : \n";
  int i=0;
  while(i<n){ cin>>x_val[i++];}

  cout<<"\n ENTER VALUES y_val[0..n] (float) :\n ";
  int j=0;
  while(j<n){ cin>>y_val[j++];}

  cout<<"\n ENTER VALUE AT WHICH YOU WANT TO FIND RESULT  x (float): ";
  cin>>x;


  yth=0;
  while(yth<n)
  {
	num=1;
	den=1;
	xth=0;
		while(xth<n){

			if(xth!=yth)  num = num * (x-x_val[xth]);
			     xth++;
		}
	xth=0;
		while(xth<n){
			if(xth!=yth) den = den * (x_val[yth]-x_val[xth]);
		     xth++;
		}
	part[count++] = (num*y_val[yth])/den;
      yth++;
   }

   int cc=0;float result=0;
   while(cc<count){
	result = result + part[cc++];
   }

   cout<<"\n output ";
   cout<<"\n f("<<x<<") : "<<result;
   getch();
}


