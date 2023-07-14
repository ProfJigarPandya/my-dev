/*
 * linked stack main function for acceptance of symb* d symb* using insertFront and removeFront singly.  Decide palindrome.
 * Valid data symbols - 'a','b','c'. 
 * Delimiter 'd'. 
 * End of input 'e'.
 * Reset 'r'
 */


#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node *next;
};

struct stack
{
	struct node *tos;
};

void initStack(struct stack *ps);

int push(struct stack *ps, char sym);

int pop(struct stack *ps, char *psym);

int isEmptyStack(struct stack *ps);

void freeupStack(struct stack *ps);

int insertFrontLL(struct node **phead, char d);
int deleteFrontLL(struct node  **phead);

int main()
{
	struct stack s;
	char symb;
	char ch[2];
	int popstat;
	initStack(&s);
	printf("\n Program to validate a|b|c * d a|b|c* . e for end input. ");
	do
	{
		printf("\nEnter symbol (a|b|c|d-delimeter|r-reset)");
		scanf("%s",ch);
		if(ch[0]=='r')
		{
			freeupStack(&s);
			printf("\n Stack cleared ");
			continue;
		}
		if(ch[0]=='a' || ch[0]=='b' || ch[0]=='c') //valid
		{
			if(!push(&s,ch[0]))
			{
				printf("\n Push failure ");	
				freeupStack(&s);
				exit(EXIT_FAILURE);
			}
				
		}
		else if(ch[0]=='d') //delimeter, stop pushing.
			break;
		else
			printf("\nEnter valid symbol. a,b,c and d-delimeter.");
	}while(1);
	
	do
	{
		printf("\nEnter symbol (a|b|c|e-end)");
		scanf("%s",ch);

		if(ch[0]=='e')
			break;
		else if(ch[0] =='a' || ch[0]=='b' || ch[0]=='c')
		{
			popstat=pop(&s,&symb);
			if( popstat==0 )
			{
				printf("\n Not palindrome. Extra symbol on right side. ");
				return EXIT_SUCCESS;	
			}

			if(symb!=ch[0] )
			{
				printf("\n Not palindrome. Symbols do not match. ");
				freeupStack(&s);
				return EXIT_SUCCESS;	
			}
		
		}
		else
		{
			printf("\nskipped invalid input");
			continue;
		}
		
				
	}while(1);
	
	

	if(isEmptyStack(&s))
	{
		printf("\n palindrome ");
		return EXIT_SUCCESS;	
	}
	else
	{
		printf("\n Not palindrome. Extra symbols on left side. ");
		freeupStack(&s);
		return EXIT_SUCCESS;	
	}

	

}

void initStack(struct stack *ps)
{
	ps->tos = NULL;//empty linked list
}
int push(struct stack *ps, char sym)
{
	return(insertFrontLL(&(ps->tos),sym));
}
int insertFrontLL(struct node **phead, char d)
{
	
	struct node *newptr;
	newptr=(struct node*) malloc(sizeof(struct node));
	if(newptr==NULL)
	{
		printf("\n insertFrontLL: Memory allocation failed ");
		return 0;//insert failure
	}
	
	newptr->data = d;
	newptr->next = *phead;
	*phead = newptr;
	return 1;
}

int pop(struct stack *ps, char *psym)
{
	char delval;
	if(isEmptyStack(ps))
	{
		return 0;//Indicate empty stack
	}

	delval = ps->tos->data;
		
	if(deleteFrontLL(&(ps->tos)))//delete successful
	{
		*psym=delval;
		return 1; //Successful pop
	}
	else
	{
		return -1;//Error in delete
	}
}


int isEmptyStack(struct stack  *ps)
{
	if(ps->tos == NULL)
	{	
		return 1;
	}
	else
	{
		return 0;
	}
}

int deleteFrontLL(struct node  **phead)
{
	struct node *temp;
	if(*phead==NULL)
	{
		return 0;//empty
	}
	temp=*phead;
	*phead = (*phead)->next;
	free(temp);
	return (1);//successful
}

void freeupStack(struct stack *ps)
{
	struct node *trav=ps->tos;
	struct node *temp;
	while(trav)
	{
		temp=trav;
		trav=trav->next;
		free(temp);
	}	
	ps->tos=NULL;
}
