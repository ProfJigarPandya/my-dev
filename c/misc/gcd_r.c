//Write a program to calculate GCD using recursive function.
/*
In mathematics, the greatest common divisor (gcd), also known as the greatest common factor (gcf), or highest common factor (hcf), of two or more integers (at least one of which is not zero), is the largest positive integer that divides the numbers without a remainder. For example, the GCD of 8 and 12 is 4.
*/
#include <stdio.h>

int findgcd_r(int m,int n);
int gcd(int m,int n);

int main()
{
 int 	
	//m=8,n=12
	//m=12,n=12
	//m=26,n=16
	//m=15,n=24
	//m=75,n=125
	m,n

	;

printf("\n Enter m and n");
scanf("%d%d",&m,&n);

printf("\n Result is %d using Euclid's algorithm",gcd(m,n));
printf("\n Result is %d using binary gcd alorithm",findgcd_r(m,n));
 return 0;
}
int findgcd_r(int a, int b)
{
//using binary gcd algorithm
	int am2,bm2;
	

printf("\n Finding for %d %d " , a,b);
	if(a==0)
		return b;
	else if(b==0)
		return a;
	else if(a==b)
	{
		return a;
	}
	else
	{
	
		am2=a%2; bm2=b%2;

	 	//Both a and b are even.
	 	if(am2==0 && bm2==0)
	 	{
			//In this case 2 is a common factor. Divide both a and b by 2, double d, and continue.
			return 2 * findgcd_r(a/2,b/2);		
		}//a is even and b is odd.
		else if(am2==0 && bm2!=0)
		{
			//In this case 2 is not a common factor. Divide a by 2 and continue.
			return(findgcd_r(a/2,b));		
		}
	    	//a is odd and b is even.
		else if (am2!=0 && bm2==0)
		{
			//Like the previous case 2 is not a common factor. Divide b by 2 and continue.
			return(findgcd_r(a,b/2));		
		}
	    	//Both a and b are odd.
		else
		{
			if (a>=b)
				return(findgcd_r((a-b)/2,b));
			else
				return(findgcd_r((b-a)/2,a));
		}	
	}
}

int gcd(int x,int y){
// Using Euclid's algorithm
printf("\n Finding for %d %d " , x,y);
     while(x!=y){
	  if(x>y)
	  {
		
	      return gcd(x-y,y);
	  }
	  else
	     return gcd(x,y-x);
     }
     return x;
}
