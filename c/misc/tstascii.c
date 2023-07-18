//Learning ascii and ascii arithmetic. Trying to understand what toupper, tolower, etc may be doing logically
//23/01/2014
//Jigar M. Pandya (CE)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char ch1='7'; //To explain how character constants stored via ascii table content

	char ch2='A';

	system("clear");
	
	//Converting a character number to int using ascii arithmetic
	printf(" Reading as character and displaying using %%c, %c \n Converting to integer via ch-'0' is %d \n In memory when read using %%d, %d ascii \n Typecasting to int %d \n"
		,ch1
		,ch1-'0'
		,ch1
		,(int)ch1
	);
	printf(" Ascii of %c is %d \n",ch1,ch1);
	printf(" Ascii of %c is %d \n",'0','0'); 
	printf(" Ascii of %c is %d \n",'9','9'); 
	printf(" I can convert char 9 to integer 9 via two approach: \n  1) %c is %d via subtracting '0' \n  2) %c is %d via subtracting 48 which is ascii of 0\n"
		,'9'
		,'9'-'0'
		,'9'
		,'9'-48); 

	printf(" Ascii of A is %d and a is %d \n",'A','a');
	printf(" There are two ways to convert character to lower. \n Anyhow add the difference of ascii of a and ascii of A. \n See that ascii of a is higher compare to A. \n");
	printf(" Difference between a and A from ascii table is %d \n",'a'-'A');
	if(ch2>='A' && ch2 <='Z')
	{
		printf(" Character %c is in upper \n",ch2);
		
		//Converting upper to lower using ascii arithmetic
		printf(" There are two ways to convert character to lower. Anyhow add the difference of ascii of a and ascii of A. \n See that ascii of a is higher compare to A. \n");
		printf(" Converting %c to lower case %c using x+('a'-'A') \n",
			ch2,
			ch2+('a'-'A'));
		printf(" Converting %c to lower case %c using x+(32) \n",
			ch2,
			ch2+(32));
	}
	
	//Now students, please write code to decide whether a character is lower and if yes write ascii arithmetic to convert it to upper.

printf ("\n Have a nice day!! \n");
}
