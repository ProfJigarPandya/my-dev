/*               BOOKSHOP INVENTORY

structure should contain  author
			  title
			  price
			  stock position
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct record
{
	char author[20];
	char title[30];
	float price;
	int quantity;
};

int lookup(struct record table[],char s1[],char s2[],int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(strcmp(s1,table[i].title) == 0 && strcmp(s2,table[i].author) == 0)
		return i;         /*Book found*/
	}
		return -1;        /*Book not found*/

}

void main()
{
	struct record book[]={{"Ritchie","CLanguage",100.00,10},{"samy","BASIC",90.00,25},{"samy","COBOL",76.00,20}};
	int no_of_records,index,quantity;
	char title[20],author[30],ans;
	clrscr();

	no_of_records=sizeof(book)/sizeof(struct record);

	do{
	printf("\nEnter title and author name \n");

	printf("\n Title");
	scanf("%s",title);

	printf("\n Author");
	scanf("%s",author);

	index = lookup(book,title,author,no_of_records);

	if(index != -1)
	{
	    printf("\n %s  %s  %f  ",book[index].title,book[index].author,book[index].price);

	    printf("\n\n Enter no of copies");
	    scanf("%d",&quantity);

	    if(quantity>book[index].quantity)
	    {
		printf("\n\n required copies not in stock");
	    }
	    else
	    {
		printf("\n\n Cost of %d copies = %.2f",quantity,book[index].price*quantity);
	    }
       }
       else
	printf("\n\nBook not in list");
	printf("\n\ndo u want to continue");
	fflush(stdin);
	scanf("%c",&ans);
	}
	while(ans=='Y' || ans=='y');

	printf("\n\nthank you. good bye");

       getch();

}