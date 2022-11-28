#include <stdio.h>
#include <stdlib.h>
#include "linearslinkedlist_gn.h"	
int main()
{
	struct snode_gn *head=NULL;
	
	removeLinearSLLFront_gn(&head);
	insertLinearSLLFront_gn(&head,NULL);
	insertLinearSLLFront_gn(&head,NULL);
	insertLinearSLLRear_gn(&head,NULL);
	insertLinearSLLFront_gn(&head,NULL);
	insertLinearSLLFront_gn(&head,NULL);
	removeLinearSLLFront_gn(&head);
	removeLinearSLLFront_gn(&head);
	insertLinearSLLRear_gn(&head,NULL);
	insertLinearSLLFront_gn(&head,NULL);
	insertLinearSLLRear_gn(&head,NULL);
	removeLinearSLLFront_gn(&head);
	insertLinearSLLRear_gn(&head,NULL);
	removeLinearSLLFront_gn(&head);
	traverseSLL_gn(head);
	removeLinearSLLFront_gn(&head);
	removeLinearSLLRear_gn(&head);
	removeLinearSLLRear_gn(&head);
	removeLinearSLLRear_gn(&head);
	removeLinearSLLRear_gn(&head);
	traverseSLL_gn(head);
	return(EXIT_SUCCESS);
}

