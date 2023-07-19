#include <stdio.h>
#include <stdlib.h>
#include "linearslinkedlist.h"	
int main()
{
	struct snode *head=NULL;
	
	removeLinearSLLFront(&head);
	insertLinearSLLFront(&head,10);
	insertLinearSLLFront(&head,20);
	insertLinearSLLRear(&head,15);
	insertLinearSLLFront(&head,17);
	insertLinearSLLFront(&head,11);
	removeLinearSLLFront(&head);
	removeLinearSLLFront(&head);
	insertLinearSLLRear(&head,21);
	insertLinearSLLFront(&head,151);
	insertLinearSLLRear(&head,171);
	removeLinearSLLFront(&head);
	insertLinearSLLRear(&head,172);
	removeLinearSLLFront(&head);
	traverseSLL(head);
	removeLinearSLLFront(&head);
	removeLinearSLLRear(&head);
	removeLinearSLLRear(&head);
	removeLinearSLLRear(&head);
	removeLinearSLLRear(&head);
	traverseSLL(head);
	return(EXIT_SUCCESS);
}

