#include <stdio.h>
#include <stdlib.h>

struct snode
{
	int data;
	struct snode *next;
};

int insertLinearSLLFront(struct snode **phead, int data)
{
	struct snode *newptr;
	newptr=(struct snode *) malloc(sizeof(struct snode));
	if(!newptr)
	{
		printf("\n Malloc-Memory allocation failed");
		return 0;//Failure
	}
	newptr->data = data;
	newptr->next = *phead;
	*phead=newptr;

	return 1;//Success
}

int removeLinearSLLFront(struct snode **phead)
{
	struct snode *temp;
	if((*phead)==NULL)//empty linked list
	{
		return 0;//Can not be deleted
	}
	
	if((*phead)->next == NULL)//single node in the list
	{
		free(*phead);
		*phead=NULL;
	}
	else//more than one node
	{	
		temp=(*phead)->next;
		free(*phead);
		*phead=temp;
	}
	return 1;
}
int insertLinearSLLRear(struct snode **phead, int data)
{
	struct snode *newptr,*trav;
	newptr=(struct snode *) malloc(sizeof(struct snode));
	if(!newptr)
	{
		printf("\n Malloc-Memory allocation failed");
		return 0;//Failure
	}
	newptr->data = data;
	newptr->next = NULL;

	if((*phead)==NULL)
	{
		*phead = newptr;
		return 1;	
	}
	
	trav=(*phead);
	while( trav->next != NULL)
		trav=trav->next;

	trav->next = newptr;

	return 1;//Success
}

int removeLinearSLLRear(struct snode **phead)
{
	struct snode *secondToLast, *last;
	if((*phead)==NULL)//empty linked list
	{
		return 0;//Can not be deleted
	}
	
	if((*phead)->next == NULL)//single node in the list
	{
		free(*phead);
		*phead=NULL;
	}
	else//more than one node
	{	
		secondToLast=(*phead);
		last=(*phead)->next;

		while(last->next != NULL)
		{
			secondToLast=last;
			last=last->next;
		}

		free(last);
		secondToLast->next = NULL;
		
	}
	return 1;
}

int traverseSLL(struct snode *head)
{
	printf("\n");
	while(head)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
	return 1;
}
