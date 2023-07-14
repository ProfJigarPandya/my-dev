#include<stdio.h>
#include<conio.h>

void orig_str_rev(char *pstr)
{
	char *p=pstr,s[10];

	int i=0;
	while(*pstr != '\0')
	{
		pstr++;

	}
	while(p != pstr)
	{
		s[i]=*pstr;
	     printf("%c",s[i]);
		pstr--;
		i++;

	}




}

void main()
{
	char str[10];
	clrscr();
	printf("enter string\n");
	scanf("%s",str);

	orig_str_rev(str);

  //	printf("%s",str);

	getch();
}

