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
	initQueue(&q);

	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	insertSQueue(&q,10);
	insertSQueue(&q,20);
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);

	insertSQueue(&q,30);
	insertSQueue(&q,40);
	insertSQueue(&q,50);

	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);
	if(deleteSQueue(&q,&data))
		printf("\n Removed %d",data);

	return(EXIT_SUCCESS);
}
