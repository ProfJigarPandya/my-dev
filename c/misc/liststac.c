/*
  stack using linked list..
  stackptr--->nodetop(info,ptrtonextnode)--->    ---  -->nodebottom(info,null)
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef enum {true,false} BOOL;
struct NODE{
 int info;
 struct NODE* next;
};

typedef struct NODE node;

void init(node** stpptr)
{
 *stpptr = NULL;
}

node* getnode()
{
 node* nodeptr;
 nodeptr=(node *)malloc(sizeof(node));
 if (nodeptr == NULL)
 {
   printf("Not enough memory to allocate buffer\n");
   exit(1);  /* terminate program if out of memory */
 }
 return nodeptr;
}
void freenode(node** ptr)
{
 free(*ptr);
}

void push(node** stpptr,int value)
{

 if(*stpptr == NULL) //last node of the list actually which is created atmost first
 {
   (*stpptr) = getnode(); //(node *)malloc(1*sizeof(node));
   (*stpptr)->info = value;
   (*stpptr)->next = NULL;
 }
 else
 {
   node *tempptr;
   tempptr = (node *)malloc(1*sizeof(node));
   tempptr->info = value;
   tempptr->next = *stpptr;
   *stpptr = tempptr;
 }
}

BOOL empty(node** st)
{
 if((*st)==NULL)
   return true;
 else
   return false;
}

void showall(node* temp)
{
 while(empty(&temp)!=true)
 {
	printf("\n %d ",temp->info);
	temp = temp->next;
 }
}

int pop(node **stpptr)
{
 int value;
 node *ptr;
 if(empty(stpptr)!=true)
 {
  value = (*stpptr)->info;
  ptr = (*stpptr)->next;
  freenode(stpptr);
  *stpptr = ptr;
  return value;
 }
 else
 {
  printf("\n stack underflow ");
  return NULL;
 }
}
int stacktop(node** stpptr)
{
 if(empty(stpptr)==false)
   return((*stpptr)->info);
 else
 {
   printf("\n The stack is empty");
   return NULL;
 }
}




void main()
{
node *stack;
clrscr();
init(&stack);

push(&stack,1);
push(&stack,2);
push(&stack,3);

showall(stack);
printf("\n stack top is %d ",stacktop(&stack));
printf("\n poped %d ",pop(&stack));

printf("\n poped %d ",pop(&stack));
printf("\n poped %d ",pop(&stack));

printf("\n poped %d ",pop(&stack));

getch();

}
