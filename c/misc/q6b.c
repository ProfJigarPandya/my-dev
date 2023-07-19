/*
Create a linked list to store employee information (id and salary). Traverse through the list and display id and bonus in a tabular manner. Bonus is calculated runtime as below logic:
 (Salary 1-10000, 30%), (10001-25000-> 20%) and (25001 onward, 10%).
*/
#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
	int id;
	int salary;
	struct linked_list * next;
};

typedef struct linked_list node;

void traverse(node *head);
void insert(node **phead,int id,int salary);
int main()
{
	node *head=NULL;
	traverse(head);
	insert(&head,1,500);
	traverse(head);
	insert(&head,2,11500);
	insert(&head,3,23500);
	insert(&head,4,55500);
	insert(&head,5,43200);
	insert(&head,6,22200);
	traverse(head);
}
void traverse(node *head)
{
	node *t=head;
	int bonus;
	if(!head)
	{
		printf("\n List is empty. ");
		return;
	}	
	
	printf("\n%10s%10s%10s","id","salary","bonus");
	do
	{
		if(t->salary>=1 && t->salary<=10000)
			bonus=t->salary*0.30;
		else if (t->salary>=10001 && t->salary<=25000)
			bonus=t->salary*0.20;
		else if( t->salary >=25001)
			bonus=t->salary*0.1;
		else
			bonus=0;
		printf("\n%10d%10d%10d",t->id,t->salary,bonus);	
		t=t->next;		
	}while(t);
}
void insert(node **phead,int id,int salary)//insert at end
{
	node *newnode, *t;
	newnode=(node *) malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("\nmalloc failed in insert");
		exit(1);
	}	
	newnode->id = id;
	newnode->salary = salary;
	newnode->next=NULL; //To indicate end
	
	if(*phead==NULL)//empty ll
	{
		*phead=newnode;
		return;			
	}

	t=*phead;

	while(t->next)
	{
		t=t->next;
	}
	t->next = newnode;
	
}

