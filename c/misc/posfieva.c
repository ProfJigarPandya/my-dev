
/*
  postfix expression value evaluation...
  i.e
  623+-382/+*2$3+  is equal to 52

  limitation : the input string must be a valid postfix notaion expression
*/

#include <conio.h>
#include <stdio.h>
#include <math.h>
#define MAXSTACKSIZE 100

typedef enum {true,false} BOOL;// change char to float // double //int as per stack type required and in showcontent
typedef int STACKTYPE;
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

BOOL isoperator(char op)
{
 if(op=='+'||op=='-'||op=='*'||op=='/'||op=='$')
	return true;
 else
	return false;
}

void main()
{
  STACK s1;
  char expr[100],symb;
  int i,left,right;



  clrscr();
  initstack(&s1);
  printf("\n enter a valid expression which must be a valid postfix notation expr. \n");
  scanf("%s",expr);


  i=0;
  while(expr[i]!='\0')
  {
   symb = expr[i];
   if(isoperator(symb)==false) // means is operand like 4 5 etc.
   {
     int value;
     value = symb - '0'; // char to int conversion
     pushandtest(&s1,value);
   }
   else // symb is operator
   {
     right = popandtest(&s1) ;
     left = popandtest(&s1);
     switch(symb)
     {
      case '+': pushandtest(&s1,left+right);
		break;
      case '-': pushandtest(&s1,left-right);
		break;
      case '*': pushandtest(&s1,left*right);
		break;
      case '/': pushandtest(&s1,left/right);
		break;
      case '$': pushandtest(&s1,(int)pow(left,right));
		break;
      default : printf("\n invalid operator");
     }
   }
   i++;
  } //end if while

  printf("\n The value of the expr is %d ",popandtest(&s1));
  getch();
}