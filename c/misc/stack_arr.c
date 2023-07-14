#include <conio.h>
#include <stdio.h>
#define MAXSTACKSIZE 100

typedef enum {true,false} BOOL;
// change char to float // double //int as per stack type required and in showcontent
typedef char STACKTYPE;
typedef struct { STACKTYPE data; } struct_ele;
typedef struct {
	int topofstack;
	struct_ele ele[MAXSTACKSIZE];
}STACK; //stack of integer

void initstack(STACK *st)
{
  st->topofstack = -1;
}

void push(STACK *st,STACKTYPE value)
{
  st->topofstack++;
  st->ele[st->topofstack].data = value;
  // printf("\n %d pushed ",value);
}

void pushandtest(STACK *st,STACKTYPE value)
{
  if(st->topofstack == MAXSTACKSIZE-1)  // 0 to MAX-1
  {
    printf("\n action cancelled due to STACK OVERFLOW ");
    return ;
  }
  else
  {
   st->topofstack++;
   st->ele[st->topofstack].data = value;
  // printf("\n %d pushed ",value);
  }
}


void showstackcontent(STACK *st)
{
  int i;
  printf("\n stack content from bottom to stack top ");
  for(i=0;i<=st->topofstack;i++)
       printf(" %c ",st->ele[i].data);
}  // change here %d %f %c appropriate of type of stack data

STACKTYPE pop(STACK *st)
{
 return ( st->ele[(st->topofstack)--].data );
}

STACKTYPE popandtest(STACK *st)
{
 if(st->topofstack == -1)
 {
    printf("\n action cancelled due to STACK UNDERFLOW ");
    return NULL;
 }
 else
    return ( st->ele[(st->topofstack)--].data );
}

BOOL empty(STACK *st)
{
 if(st->topofstack == -1)
     return (true);
 else
     return (false);
}
STACKTYPE stacktop(STACK *st)
{
  return st->ele[st->topofstack].data;
}


void main()
{
  STACK s1;

  clrscr();
  initstack(&s1);
   push(&s1,'a');
 push(&s1,'b');
 push(&s1,'c');
 push(&s1,'d');

  showstackcontent(&s1);

  printf("\n %c is poped",pop(&s1));

    printf("\n %c is poped",pop(&s1));
    printf("\n %c is poped",pop(&s1));

     push(&s1,'I');
       showstackcontent(&s1);
    printf("\n %c is poped",pop(&s1));
       showstackcontent(&s1);






 getch();
}