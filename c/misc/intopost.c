
/*
  conversion from infix to postfix notation of a expression...
  i.e
  input 'A+B*C'  infix can be converted to 'ABC*+' postfix

  limitation : the input string must be a valid infix notaion expression
*/

#include <conio.h>
#include <stdio.h>
#include <math.h>
#define MAXSTACKSIZE 100

typedef enum {true,false} BOOL;// change char to float // double //int as per stack type required and in showcontent
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


BOOL isoperator(char op)
{
 if(op=='+'||op=='-'||op=='*'||op=='/'||op=='$')
	return true;
 else
	return false;
}
BOOL precedence(char op1,char op2) // returns true if op1 precedence is greater than op2 otherwise fasle
{
 switch(op1)
 {
  case '$':
	    if(op2=='$' || op2=='*' || op2=='/' || op2=='+' || op2=='-' || op2==')')
		return true;
	    break;
  case '*':
  case '/':
	    if(op2=='*' || op2=='/' || op2=='+' || op2=='-' || op2==')')
		return true;
	    break;
  case '+':
  case '-':
	    if(op2=='+' || op2=='-' || op2==')')
		return true;
	    break;
 }
 return false;
}


void main()
{
  STACK s1;
  char infix[100],postfix[100],symb;
  int i,j,left,right;
  clrscr();
  initstack(&s1);
  printf("\n enter a valid infix expression to convert it to postfix notation. \n");
  scanf("%s",infix);


  i=0;j=0;
  while(infix[i]!='\0')
  {
   if(isoperator(infix[i]) == false && infix[i]!='(' && infix[i]!=')') // operand then send it to output string
   {
    postfix[j++] = infix[i];
    i++;
    continue;
   }
   else // operator
   {
     while(precedence(stacktop(&s1),infix[i])==true && empty(&s1)!=true)
     {
       postfix[j++] = popandtest(&s1);
     };
      if(empty(&s1)==true || infix[i]!=')') pushandtest(&s1,infix[i]);
      else
      {
       popandtest(&s1); //discard '('
      }
   }

   i++;
  } //end if while
  while(empty(&s1)!=true)
	postfix[j++]=popandtest(&s1);

	postfix[j]='\0';
	printf("\n the postfix expr :  %s",postfix);
//  printf("\n The value of the expr is %d ",popandtest(&s1));
  getch();
}