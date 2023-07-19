/*
  ASCENDING PRIORITY QUEUE using OREDRED doubly linked list.. // MIN FIRST REMOVE
  front will be minimum no..
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef enum {true,false} BOOL;
struct NODE{
 int info;
 struct NODE* next;
 struct NODE* back;
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
   (*q)->rear->back = NULL;
   (*q)->front = (*q)->rear;
 }
 else// after one node is there in Q
 {
   if( value<=(*q)->front->info ) //insert before front
   {
    node *tempptr;
    tempptr = getnode();//(node *)malloc(1*sizeof(node));
    tempptr->info = value;
    tempptr->next = (*q)->front;
    tempptr->back = NULL;
    (*q)->front = tempptr;
    (*q)->front->next->back = tempptr;
   }
   else if(value >=(*q)->rear->info) //insert at last
   {
    node *tempptr;
    tempptr = getnode();//(node *)malloc(1*sizeof(node));
    tempptr->info = value;
    tempptr->next = NULL;
    tempptr->back = (*q)->rear;
    (*q)->rear->next = tempptr;
    (*q)->rear = tempptr;
   }
   else  // value is inbetween min and max
   {
     // starting from front towards rear ...
     int prev_value;
     node* tempptr;
     node* tt;
     tempptr = (*q)->front;
     while(1)
     {

      if(value>tempptr->info)
      {
	 tempptr = tempptr->next;
	 continue;
      }
      else
      {

	//prev_value = tempptr->info;
	//tempptr->info=value;

	tt = getnode();
	tt->info = value;
	tt->next = tempptr;
	tt->back = tempptr->back;
	tt->back->next = tt;
	tempptr->back=tt;
	break;
      }
     }
   }
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

insert(&q,30);
insert(&q,20);
insert(&q,15);
insert(&q,21);
insert(&q,25);
insert(&q,40);
insert(&q,22);
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
printf("\n poped %d ",removeele(&q));
getch();

}
