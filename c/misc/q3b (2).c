/*
Write a program to store first name, middle name, last name and technical area of interest of participant. In the program maintain any 5 inbuilt interests i.e. “computer”, “electronics”, “information technology”, “civil” and “mechanical”. 
-Display welcome message with pre-populated full name.
-Display to the participant whether do you support his interest entered or not.  
-Also, as fun gesture, if the last name length is utmost 255 characters, display message “You are one of us!!!” otherwise display “You are special one!!!”.

*/


#include <stdio.h>
#include <string.h>

#define SPECIAL 256
#define MAX 80
#define TOTALINT 5
struct participant
{
	char first_name[MAX], middle_name[MAX], last_name[MAX];
   	char interest[MAX];
};
int main()
{
	struct participant p;
	char inbuilt_interests[TOTALINT][MAX]={"computer","electronics","information technology","civil","mechanical"};
	char fullname[SPECIAL*2];
	int i;

	printf("\nEnter fname, mname, lname");
	scanf("%s %s %s",p.first_name, p.middle_name, p.last_name);
		
	getchar();

	printf("\nEnter interest");
	scanf("%[^\n]",p.interest);

	strcpy(fullname, p.first_name);
	strcat(fullname," ");
	strcat(fullname, p.middle_name);
	strcat(fullname," ");
	strcat(fullname, p.last_name);

	printf("Welcome %s", fullname);
	for(i=0;i<TOTALINT;i++)
	{
		if(!strcmp(p.interest,inbuilt_interests[i]))
		{
			printf("\n Your interest matches one of the inbuilt interests ");
			break;
		}
 	}
	if(i==TOTALINT)
	{
		printf("\n Sorry, we do not support your interest.");
	}
	if(strlen(fullname)>=SPECIAL)
	{
		printf("\nYou are special one!!");	
	}
	else
	{
		printf("\nYou are one of us!!");
	}
}
