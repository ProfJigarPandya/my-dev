/* circular queue ...

 front is the array index immediately preceding the first element of the
 queue rather than the index of the first element itself. And rear implies to
 index of the last element of the queue.

 initially front = rear = MAXQUEUE - 1

 thus when front == rear than the q is empty.
 At the same time after all elements inserted  front will same as rear
 than the overflow condition.

 Thus it is difficult to differenciate empty & overflow condition

 So the solution is to sacrifice one element of the array and to
 allow a queue to grow only as large as one less than the size of the array.

 Thus , an attempt to insert a hundreadth element into the Q causes an overflow.
 if array size if 0 to 99.

 */


#include <stdio.h>
#include <conio.h>
typedef int QTYPE;
typedef enum {true,false} BOOL;

#define QMAXSIZE 4
typedef struct
{
  int front,rear;
  QTYPE ele[QMAXSIZE];
}QUEUE;
void init(QUEUE* q)
{
  q->front = QMAXSIZE-1;
  q->rear =  QMAXSIZE-1;
}
void insert(QUEUE* q,QTYPE value)
{

 if(q->rear == QMAXSIZE-1) //make room for new element
    q->rear = 0;
 else
  q->rear = q->rear + 1;

 if(q->rear == q->front)
 {
  printf("\n the queue is overflow ... action is cancelled ");
  if(q->rear == 0)
	q->rear = QMAXSIZE-1;
  else
	q->rear = q->rear - 1;

  return;
  //exit(0);
 }
  q->ele[q->rear] = value;
}

BOOL empty(QUEUE *q)
{
 if(q->rear == q->front)
      return true;
 else
	return false;
}

QTYPE removeele(QUEUE* q)
{
 QTYPE temp;
 if(empty(q)==true)
 {
  printf("\n Q underflow ");
  return NULL;
 }

 if(q->front == QMAXSIZE-1)
   q->front = 0;
 else
   q->front = q->front + 1;

 temp = q->ele[q->front];
 q->ele[q->front] = 0;
 return (temp);
}


void main()
{
 QUEUE q1;

 clrscr();
 init(&q1);
 insert(&q1,4);
 insert(&q1,5);
 printf("\n %d ",removeele(&q1));
 insert(&q1,6);
 insert(&q1,7);
 printf("\nddd");
 insert(&q1,8);
 printf("\n %d ",removeele(&q1));
// insert(&q1,9);
// insert(&q1,10);
 while(empty(&q1)!=true)
 {
  printf("\n removed %d",removeele(&q1));
 }
 insert(&q1,4);
 insert(&q1,5);
 printf("\n %d ",removeele(&q1));
 insert(&q1,6);
 insert(&q1,7);
 printf("\nddd");
 insert(&q1,8);
 printf("\n %d ",removeele(&q1));

getch();
}


