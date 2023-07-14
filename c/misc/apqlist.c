/*
  ASCENDING PRIORITY QUEUE using OREDRED linked list.. // MIN FIRST REMOVE
  front will be minimum no..
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
 else// after one node is there in Q
 {
   if( value<=(*q)->front->info ) //insert before front
   {
    node *tempptr;
    tempptr = getnode();//(node *)malloc(1*sizeof(node));
    tempptr->info = value;
    tempptr->next = (*q)->front;
    (*q)->front = tempptr;
   }
   else if(value >=(*q)->rear->info) //insert at last
   {
    node *tempptr;
    tempptr = getnode();//(node *)malloc(1*sizeof(node));
    tempptr->info = value;
    tempptr->next = NULL;
    (*q)->rear->next = tempptr;
    (*q)->rear = tempptr;
   }
   else  // value is inbetween min and max
   // 10 20 30 then want to enter 15 so... add new node of 20 after the 20original value node
   // replace in original 20 by 15.
   // update rear if need to insert just before the last node
   //this has to done because in ll pre-successor address finding is difficult;
   // and we can decide that 15 has to add before 20 after only we reach to 20.
   // so back node address finding is tedious. So the temp solution is replace & add.
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
	prev_value = tempptr->info;
	tempptr->info=value;
	tt = getnode();
	tt->info = prev_value;
	tt->next = tempptr->next;
	if(tempptr->next == NULL) //insertion just before last node
	{
	  (*q)->rear = tt;
	}
	tempptr->next = tt;
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
