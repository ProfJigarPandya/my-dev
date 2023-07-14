 /* program for finding perfect no
  like 6 = 3*2*1 then 6 is perfect no.					*/

#include <iostream.h>
#include <conio.h>

void main()
{
	clrscr();
	int arr[100];
	arr[0]=1;
	int no,i=1,j,factor=2,temp,sum=0,tempno;

	for(no=2;no<=100;no++){
	       tempno = no;
		while(factor<=tempno){
			temp = tempno % factor;
			if(temp == 0){
				arr[i++] = factor;
				tempno = tempno / factor;
				factor = 2;
			}
			else
				factor++;
		}
		for(j=0;j<i;j++){
			sum = sum + arr[j];
		}
		if(sum == no){
			cout<<"\n DIGIT "<<no<<" IS A PERFECT NO ";
		}
//		else
//			cout<<"\n DIGIT "<<no<<" IS NOT ....";
		sum=0;
		factor=2;
		i=1;

       }
       getch();
}


