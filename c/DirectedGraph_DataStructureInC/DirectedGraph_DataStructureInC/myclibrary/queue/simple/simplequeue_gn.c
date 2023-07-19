/*
 * Implement simple queue using singular linked list.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linearslinkedlist_gn.h"
#include "simplequeue_gn.h"
#include "dynamicgraph.h"

void initSQueue_gn(struct squeue_gn *ptrq)
{
	//printf("\n initSQueue: ");
	ptrq->front = ptrq->rear = NULL;
}

int insertSQueue_gn(struct squeue_gn *ptrq, struct gnode* data)
{
	int status;
	//printf("\n insertSQueue: ");
	if(!(ptrq->front))//firstever insertion
	{
		status  = insertLinearSLLFront_gn(&(ptrq->front),data);
		ptrq->rear = ptrq->front;
		return 1;
	}
	status  = insertLinearSLLRear_gn(&(ptrq->rear),data);
	
	if(status)//move rear to newly appended node address
	{
		ptrq->rear = ptrq->rear->next;
	}
	return status;
}

int deleteSQueue_gn(struct squeue_gn *ptrq, struct gnode* *pdata)
{
	int status;
	//printf("\n deleteSQueue: ");
	if(!(ptrq->front))
		return 0;

	*pdata = ptrq->front->data;
	status = removeLinearSLLFront_gn(&(ptrq->front));
	if(status)
	{
		if(!(ptrq->front))//Removed the one and only node
			ptrq->rear = NULL;
	}
	return status;
}


int isEmptySQueue_gn(struct squeue_gn *ptrq)
{
	if(ptrq->front == NULL)
		return 1;//empty
	else
		return 0;
}
