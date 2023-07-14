#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
struct node
{
  int info;
  struct node* next;
};
typedef struct node NODE;
typedef struct
{
 NODE *front;
 NODE *rear;
 NODE *list;
}QUEUE;

void insert_end(int data,QUEUE** FIRSTPTR)
{
	NODE *tempptr;
	if( ( tempptr=new NODE() ) == NULL)
	{
	  cout<<"memory allocation failure - stack overflow ";
	  return;
	}

	tempptr->next = NULL;
	tempptr->info = data;

	if((*FIRSTPTR)->list == NULL)
	{
		(*FIRSTPTR)->list = tempptr;
		(*FIRSTPTR)->front = tempptr;
	}
	else
	{
//		tempptr->next = *FIRSTPTR;
		 (*FIRSTPTR)->rear->next = tempptr;

	}
	(*FIRSTPTR)->rear = tempptr;
}

int remove_front(QUEUE **FIRSTPTR)
{
   NODE *tempptr;
   int tempvar;
	if((*FIRSTPTR)->list == NULL)
	{
		cout<<"list is empty - stack underflow ";
		exit(0);
	}
	tempptr = (*FIRSTPTR)->list;
	(*FIRSTPTR)->list = tempptr->next;
	tempvar = tempptr->info;
	free(tempptr);
	return tempvar;
}
void main()
{
 clrscr();
 QUEUE *q;

 q->front=NULL;
 q->rear=NULL;
 q->list=NULL;

 insert_end(5,&q);
 insert_end(13,&q);
 cout<<"\n"<<remove_front(&q);
 cout<<"\n"<<remove_front(&q);
  cout<<"\n"<<remove_front(&q);
 getch();
}