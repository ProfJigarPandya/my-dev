#include<stdio.h>
#include<stdlib.h>

typedef struct DATA
{	
int empID;
char name[20];
int salary;
int experience;
}data;

struct Emp
{
data edata;
struct Emp *next;
}*ActiveLinkedList=NULL,*InActiveLinkedList=NULL;

void insertInactive(struct Emp *ptr)
{
		if(InActiveLinkedList==NULL)
			{
			InActiveLinkedList=ptr;
			ptr->next=NULL;
			}
		else
			{
			ptr->next=InActiveLinkedList;
			InActiveLinkedList=ptr;
			}
		

}

void empJoined()
{
struct Emp *newemp;
newemp=(struct Emp *) malloc(sizeof(struct Emp));

printf("\nEnter Name of New Employee: ");
scanf("%s",newemp->edata.name);

printf("\nEnter ID of New Employee: ");
scanf("%d",&newemp->edata.empID);

printf("\nEnter salary of New Employee: ");
scanf("%d",&newemp->edata.salary);

printf("\nEnter experience of New Employee: ");
scanf("%d",&newemp->edata.experience);

if(ActiveLinkedList==NULL)
	{
	ActiveLinkedList=newemp;
	newemp->next=NULL;
	}
else
	{
	newemp->next=ActiveLinkedList;
	ActiveLinkedList=newemp;
	}
}

void empResigned()
{
struct Emp *ptr=ActiveLinkedList,*prev=NULL;
int id;
printf("\nEnter Employee ID:");
scanf("%d",&id);
if(ptr==NULL)
	{
	printf("Can't Delete from Empty List");
	return;
	}
if(ptr->edata.empID==id)//first node
	{
	ActiveLinkedL
ist=ptr->next;
	insertInactive(ptr);
	return;
	}

while(ptr!=NULL)//Intermediate Node
	{
	if(ptr->edata.empID==id)
		{
		prev->next=ptr->next;
		insertInactive(ptr);
		}
	prev=ptr;
	ptr=ptr->next;
	}


}


void print(int list)
{
struct Emp *ptr;
if(list==1)
	ptr=ActiveLinkedList;
else
	ptr=InActiveLinkedList;
if(ptr==NULL)
	printf("\nList is Empty");
else
	{
	printf("\n%3s %20s %6s %3s","ID","NAME","Salary","Exp");
	while(ptr!=NULL)
		{
		printf("\n%3d %20s %6d %3d",ptr->edata.empID,ptr->edata.name,ptr->edata.salary,ptr->edata.experience);
		ptr=ptr->next;
		}
	}
}
main()
{
	int i,choice;
	while(1)
	{
		printf("\n1.Register new Employee 2.EmployeeResigned 3.print 4.Exit");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&i);
		switch(i)
			{
			case 1:
				empJoined();
				break;
			case 2:
				empResigned();
				break;
			case 3:
				printf("\n1.Print Active Linkedlist 2.Print InActiveLinkedlist: ");
				scanf("%d",&choice);				
				print(choice);
				break;
			case 4:
				exit(0);
			default:
				printf("\nPlease Enter Valid Choice");
				break;
			}
	
	}
}
