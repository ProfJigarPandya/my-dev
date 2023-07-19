/*
 * insert into order. resulting insertin sort.
 */

struct node
{
	int data;
	struct node *next;
};
void insertorder(struct node **phead,int data);
void traverse(struct node *head);
int main()
{
	struct node *head=NULL;
	insertorder(&head,10);
	insertorder(&head,14);
	insertorder(&head,12);
	insertorder(&head,18);
	insertorder(&head,14);
	insertorder(&head,13);
	insertorder(&head,120);
	insertorder(&head,50);
	
	traverse(head);

}
void insertorder(struct node **phead,int data)
{
	struct node *newptr  = (struct node *) malloc(sizeof(struct node));
	struct node *trav;
	if(newptr==NULL)
	{
		printf("\n Malloc error");
		//may clean up ll
		exit(EXIT_FAILURE);
	}
	newptr->data = data;
	if(*phead==NULL)
	{
		newptr->next = NULL;
		*phead=newptr;
		return;
	}
	
	trav=*phead;

	while(!trav)
	{
		if(trav->data >= data)
			break;
		lefttrav=trav;
		trav=trav->next;
	}
	
	lefttrav->next=newptr;
	newptr->next=trav;
	
}
void traverse(struct node *head)
{
	printf("\n Data Elements: ");
	while(head)
	{
		printf("\t%d",head->data);
		head=head->next;
	}
}	
