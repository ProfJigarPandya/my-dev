// USING RECURSION tree creation which forms equation ...
// i.e program of representing expression via tree

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

typedef enum {true,false} BOOL;
struct NODE{
  char info;
  struct NODE *left;
  struct NODE *right;
};

typedef struct NODE node;
node* t;
node* getnode()
{
 node* tempnode;
 tempnode = (node*) malloc(sizeof(node));
 if(tempnode==NULL)
 {
  printf("\n memory allocation failure ");
  exit(0);
 }
 tempnode->left = NULL;
 tempnode->right = NULL;
 return tempnode;
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


void formtree(node** root,char ex[]);
void setleft(node** root,char ex[],int len)
{
 if(len==1)
 {
  (*root)->left = getnode();
  (*root)->left->info = ex[0];
 }
 else
 {
  formtree(&((*root)->left),&(ex[0]));
 }
}

void setright(node** root,char ex[],int len)
{
 if(len==1)
 {
  (*root)->right = getnode();
  (*root)->right->info = ex[0];
 }
 else
 {
  formtree(&((*root)->right),&(ex[0]));
 }
}


void formtree(node** root,char ex[])
{

  int i=0;
  int len;
  char str[50];

   len = strlen(ex);

   *root = getnode();

   if(ex[i]=='(')
   {
     int j=i;
     while(ex[j]!=')')
       j++;
    setleft(root,&(ex[i+1]),j-1);
    i = i+j;
    setright(root,&(ex[i]),len-i);
   }
   else // it's a operand
   {
     setleft(root,&(ex[i]),1);
     i++;
     (*root)->info = ex[i++]; //operator as root
     setright(root,&ex[i],len-2); //remaining string as right
   }
}

void in_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 in_tra(tptr->left);
 printf(" %c ",(tptr)->info);
 in_tra(tptr->right);
}

void post_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 post_tra(tptr->left);
 post_tra(tptr->right);
 printf(" %c ",(tptr)->info);
}

void pre_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 printf(" %c ",(tptr)->info);
 pre_tra(tptr->left);
 pre_tra(tptr->right);
}


void main()
{

char expr[50];


t = NULL;

clrscr();
printf("\n enter any valid expression ");
scanf("%s",expr);

formtree(&t,expr);

printf("\n expr in postfix notation ");
post_tra(t);


printf("\n expr in prefix notation ");
pre_tra(t);



getch();
}