#include <stdio.h>
#include <stdlib.h>
#include "linearslinkedlist_gn.h"
#include "dynamicgraph.h"
int insertLinearSLLFront_gn(struct snode_gn **phead, struct gnode* data)
{
	struct snode_gn *newptr;
	//printf("\n insertLinearSLLFront_gn: ");

	newptr=(struct snode_gn *) malloc(sizeof(struct snode_gn));
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

int removeLinearSLLFront_gn(struct snode_gn **phead)
{
	struct snode_gn *temp;
	//printf("\n removeLinearSLLFront_gn:");
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
int insertLinearSLLRear_gn(struct snode_gn **phead, struct gnode* data)
{
	struct snode_gn *newptr,*trav;
	//printf("\n insertLinearSLLRear_gn:");
	newptr=(struct snode_gn *) malloc(sizeof(struct snode_gn));
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

int removeLinearSLLRear_gn(struct snode_gn **phead)
{
	struct snode_gn *secondToLast, *last;
	//printf("\n removeLinearSLLRear_gn:");
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

int traverseSLL_gn(struct snode_gn *head)
{
	//printf("\n traverseSLL_gn: ");
	if(!head)
	{
		printf("\n Can't traverse as the list is empty. ");
		return 0;
	}
	while(head)
	{
		printf("%s\t",head->data->nodeno);
		head=head->next;
	}
	return 1;
}
