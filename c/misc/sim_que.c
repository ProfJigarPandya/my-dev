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
  q->front = 0;
  q->rear = -1;
}
void insert(QUEUE* q,QTYPE value)
{

 if(q->rear >= QMAXSIZE-1)
 {
  printf("\n the queue is overflow ... action is cancelled ");
  return;
 }
  q->rear = q->rear + 1;
  q->ele[q->rear] = value;
}

BOOL empty(QUEUE *q)
{
 if(q->rear < q->front)
	return true;
 else
	return false;
}

QTYPE removeele(QUEUE* q)
{
 QTYPE temp;
 if(empty(q)==true)
 {
  printf("\n Q underflow");
  return NULL;
 }
 temp = q->ele[q->front];
 q->front = q->front + 1;
 return (temp);
}


void main()
{
 QUEUE q1;

 clrscr();
 init(&q1);
 insert(&q1,4);
 insert(&q1,5);
 insert(&q1,6);
 insert(&q1,7);

 insert(&q1,7);
 while(empty(&q1)!=true)
 {
  printf("\n removed %d",removeele(&q1));
 }
getch();
}


