
/*

  mathematical expression validation ...
  i.e no of open brackets are same as closing backets or not?
  & matching of closing brackets to opening bracket exist or not?

  limitation : the operator place mistake not varified
*/

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
BOOL matchbracket(char left,char right)
{
 if(left=='(' && right==')') return true;
 if(left=='{' && right=='}') return true;
 if(left=='[' && right==']') return true;

 return false;
}

void main()
{
  STACK s1;
  char expr[100],poped;
  int i;



  clrscr();
  initstack(&s1);
  printf("\n enter the expression u want to validate ");
  scanf("%s",expr);

  i=0;
  while(expr[i]!='\0')
  {
   switch(expr[i])
   {
    case '(':
    case '{':
    case '[':  pushandtest(&s1,expr[i]);
	       break;

    case ')':
    case '}':
    case ']':  poped = popandtest(&s1);
	       if( matchbracket(poped,expr[i]) == false || poped == NULL ) // if not matched of underflow
	       {
		 printf("\n The expression is invalid ");
		 exit(0);
	       }
	       break;
    default :  printf("\n operator / operand %c ",expr[i]);
   } //end of switch
   i++;
  } //end if while

  if(empty(&s1)==false)
     printf("\n The expression is invalid ");
  else
     printf("\n The statement is VALID ");


 getch();
}