#include <stdio.h>
#include <conio.h>
#include <string.h>


void main()
{

 char name1[10];
 char name2[10];
 char name3[10]="Bond";
 char str1[10],str2[10];

 int len,cvalue;
 clrscr();


 printf("\n Enter the name ");
 scanf("%s",name1);


 //to find length of the string
 len = strlen(name1);
 printf("\n Length of the string %d",len);


 //to copy one string to other string
 strcpy(name2,name1);
 printf("\n Copied name  %s",name2);

 //to concatenate one string to the end of the other....
 strcat(name1,name3);
 printf("\n String1 after concatenation %s",name1);


 //comparison....
 printf("\n Enter two strings for comparison");
 scanf("%s%s",str1,str2);

 cvalue = strcmp(str1,str2);
 if(cvalue==0)
 {
	printf("\n Both strings are same ");
 }
 else if(cvalue>0)
 {
	printf("\n String1 comes after in alphabetical order");
 }
 else
 {
	printf("\n String2 comes after in alphabetical order");
 }


 getch();
}