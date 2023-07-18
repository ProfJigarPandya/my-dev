#include <stdio.h>

int main()
{
	char *city[3]={"Baroda","Ahmedabad","Surat"};
	printf("\n%u",*(city+1)+4);//pointer to char d of Ahm..
	printf("\nproof %c",*(*(city+1)+4));//char d of Ahm..proof
	printf("\n%c",**(city+1));//char A of Ahm.. 
	printf("\n%u",*(city+1));//pointer to char A of Ahm
	printf("\nproof %c",*(*(city+1)));//char A of Ahm .. proof
	printf("\n%u",*city+3);//pointer to char o of Baroda
	printf("\nproof %c",*(*city+3));//char o of Baroda..proof
	printf("\n%c",(*(*(city+1)+2)));//m of Ahm..
	printf("\n%c",**city+1);//'B'+1 == 'C'
}

