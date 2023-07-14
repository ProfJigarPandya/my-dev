// USING RECURSION tree creation which allows duplicate numbers ...
// a binary search tree ... with pre / in /post order traversal

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <iostream.h>

struct NODE{
  int info;
  struct NODE *left;
  struct NODE *right;
};

typedef struct NODE node;
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
node* maketree(int data)
{
	node* temp = getnode();
	temp->info = data;
	return temp;
}
void setleft(node *parent,int data)
{
	if(parent->left != NULL)
	{
		cout<<"\n left subtree not empty";
		return;
	}
	else
	{
		parent->left = maketree(data);
	}
}
void setright(node *parent,int data)
{
	if(parent->right != NULL)
	{
		cout<<"\n right subtree is not empty ";
		return;
	}
	else
	{
		parent->right = maketree(data);
	}

}
void in_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 in_tra(tptr->left);
 printf(" %d ",(tptr)->info);
 in_tra(tptr->right);
}

void post_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 post_tra(tptr->left);
 post_tra(tptr->right);
 printf(" %d ",(tptr)->info);
}

void pre_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 printf(" %d ",(tptr)->info);
 pre_tra(tptr->left);
 pre_tra(tptr->right);
}

node* makebinarysearchtree()
{

node *t=NULL,*temp;
char ch;
int tdata;
while(1)
{

 cout<<"\n want to enter ( y/n )";
 cin>>ch;
 if(ch=='n')
	break;
 cout<<"\n enter data ";
 cin>>tdata;
 if(t!=NULL)
 {
   temp = t;
  while(1)
  {

   if(tdata<(temp->info)) // set left
   {
    if( (temp->left) == NULL)
    {
	setleft(temp,tdata);
	break;
    }
    else
	temp = temp->left;
   }
   else //set right
   {
    if( (temp->right) == NULL)
    {
	setright(temp,tdata);
	break;
    }
    else
	temp = temp->right;
   } //end of else
  }// end of inner while(1)
 } //EN D O F IF
 else
 {
	t=maketree(tdata);
 }
}   //END of outer while(1) .. entering data
return t;
}

void main()
{

node *t,*temp;
t = NULL;
clrscr();
t=makebinarysearchtree();

in_tra(t);

getch();
}