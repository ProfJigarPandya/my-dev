/*
 * Implement simple queue using singular linked list.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simplequeue.h"	

void initSQueue(struct squeue *ptrq)
{
	//printf("\n initSQueue: ");
	ptrq->front = ptrq->rear = NULL;
}

int insertSQueue(struct squeue *ptrq, int data)
{
	int status;
	//printf("\n insertSQueue: ");
	if(!(ptrq->front))//firstever insertion
	{
		status  = insertLinearSLLFront(&(ptrq->front),data);
		ptrq->rear = ptrq->front;
		return 1;
	}
	status  = insertLinearSLLRear(&(ptrq->rear),data);
	
	if(status)//move rear to newly appended node address
	{
		ptrq->rear = ptrq->rear->next;
	}
	return status;
}

int deleteSQueue(struct squeue *ptrq, int *pdata)
{
	int status;
	//printf("\n deleteSQueue: ");
	if(!(ptrq->front))
		return 0;

	*pdata = ptrq->front->data;
	status = removeLinearSLLFront(&(ptrq->front));
	if(status)
	{
		if(!(ptrq->front))//Removed the one and only node
			ptrq->rear = NULL;
	}
	return status;
}


