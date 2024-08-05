/*

Find the number of solutions to 
x1+x2+x3+x4=17 where 0<=x1<=2;0<=x2<=5;0<=x3<=5;2<=x4<=6;
1 5 5 6
2 4 5 6
2 5 4 6
2 5 5 5
 Total solutions 4 
*/


#include <stdio.h>
int main()
{
 int x1,x2,x3,x4;
 int count=0;
 int requiredSum=17;
 for(x1=0;x1<=2;x1++)
 {
 	for(x2=0;x2<=5;x2++)
	 {
		 for(x3=0;x3<=5;x3++)
		 {
			 for(x4=2;x4<=6;x4++)
			 {
				if((x1+x2+x3+x4)==requiredSum)
				{
					count++;
					printf("\n%d %d %d %d", x1,x2,x3,x4);
				}
				
				
			 }

		 }

	 }
 }
 printf("\n Total solutions %d ",count);
}
