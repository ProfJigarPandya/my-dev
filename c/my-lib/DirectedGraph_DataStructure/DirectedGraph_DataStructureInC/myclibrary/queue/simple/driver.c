/*
 * Implement simple queue using singular linked list.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simplequeue.h"	

int main()
{
	struct squeue q;
	int data;
	initSQueue(&q);

	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	insertSQueue(&q,10);
	insertSQueue(&q,20);
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	insertSQueue(&q,30);
	insertSQueue(&q,40);
	insertSQueue(&q,50);

	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
        insertSQueue(&q,60);
        insertSQueue(&q,70);
	
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	

	return(EXIT_SUCCESS);
}
