/*
 * Implement simple queue using singular linked list.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linearslinkedlist.h"
	
struct squeue
{
	struct 	snode *front, *rear;
};


void initSQueue(struct squeue *ptrq)
{
	ptrq->front = ptrq->rear = NULL;
}

int insertSQueue(struct squeue *ptrq, int data)
{
}

int deleteSQueue(struct squeue *ptrq, int *pdata)
{
	
}
