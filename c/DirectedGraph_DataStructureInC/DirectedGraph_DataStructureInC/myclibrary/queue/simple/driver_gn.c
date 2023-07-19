/*
 * Implement simple queue using singular linked list.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simplequeue_gn.h"	
#include "dynamicgraph.h"

int main()
{
	struct squeue_gn q;
	struct gnode* data=NULL;
	initSQueue_gn(&q);

	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	insertSQueue_gn(&q,NULL);
	insertSQueue_gn(&q,NULL);
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	insertSQueue_gn(&q,NULL);
	insertSQueue_gn(&q,NULL);
	insertSQueue_gn(&q,NULL);

	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	
        insertSQueue_gn(&q,NULL);
        insertSQueue_gn(&q,NULL);
	
	if(deleteSQueue_gn(&q,&data))
		printf("\n Removed %s",data->nodeno);
	else
		printf("\n Can't delete as the queue is empty currently. ");
	

	return(EXIT_SUCCESS);
}
