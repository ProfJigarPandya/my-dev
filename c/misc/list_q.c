/*                                                              rear
  QUEUE using linked list..                                     |
  front--->nodetop(info,ptrtonextnode)--->    ---  -->nodebottom(info,null)
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


typedef enum {true,false} BOOL;

struct NODE{
 int info;
 struct NODE* next;
};

typedef struct {
  struct NODE* front;
  struct NODE* rear;
} QUEUE;

typedef struct NODE node;
typedef QUEUE* QPTR;

void init(QPTR* stpptr)
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
 nodeptr->info = 10;
 return nodeptr;
}
void freenode(node** ptr)
{
 free((*ptr));
}

void insert(QPTR* q,int value)
{

 if(*q == NULL) //last node of the list actually which is created atmost first
 {
   (*q) = (QPTR) malloc(sizeof(QUEUE)); // very important
   (*q)->rear = getnode();//(node *)malloc(1*sizeof(node));
   (*q)->rear->info = value;
   (*q)->rear->next = NULL;
   (*q)->front = (*q)->rear;
 }
 else
 {
   node *tempptr;
   tempptr = getnode();//(node *)malloc(1*sizeof(node));
   tempptr->info = value;
   tempptr->next = NULL;
   (*q)->rear->next = tempptr;
   (*q)->rear = tempptr;
 }
}

BOOL empty(QPTR* st)
{
 if( (*st)->rear == NULL)
   return true;
 else
   return false;
}

int removeele(QPTR *q)
{
 int value;
 node *ptr;
 if(empty(q)!=true)
 {
  value = (*q)->front->info;
  ptr = (*q)->front->next;
  freenode(&((*q)->front));
  (*q)->front = ptr;
  if( (*q)->front == NULL)  // if last element removed than rear also must be NULL
	(*q)->rear = NULL;
  return value;
 }
 else
 {
  printf("\n queue underflow ");
  return NULL;
 }
}

void main()
{

QPTR q;
clrscr();
init(&q);

insert(&q,1);
insert(&q,2);
insert(&q,3);

printf("\n poped %d ",removeele(&q));

printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));

printf("\n poped %d ",removeele(&q));

getch();

}
