/*
 threaded binary tree ....
  suppose instead of to use recursion , instead of containig a NULL pointer
  in it's right field,
   this type of node ( i,e, a node with an empty right subtree)
   contains in right field address of the immediate inorder successor node.

   this is known as tread ( right in-order tree )
   so if this is the case then no need of stacking/recursion in traversal.

   the right most has still right field as null.

*/


#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <iostream.h>

typedef enum { true,false} boolean;
struct NODE{
  int info;
  struct NODE *left;
  struct NODE *right;
  boolean thread; //true if right is null or a non-null thread
  //i.e. if thread is true and right is not null then right is a thread
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
	temp->thread = false;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void setleft(node *parent,int data)
{
/*	if(parent->left != NULL)
	{
		cout<<"\n left subtree not empty";
		return
	}
	else*/
		node *temp=getnode();
		temp->info = data;
		temp->left=NULL;
		temp->right = parent;
		temp->thread = true;
		parent->left = temp;

}
void setright(node *parent,int data)
{
	node *temp;
	temp = getnode();
	temp->info = data;
	temp->left = NULL;
	if(parent->thread == true)
	{
		temp->right = parent->right;
		temp->thread = true;
	}
	parent->right = temp;
	parent->thread = false;
}
void in_tra(node* tptr)
{
 node *temp;
 temp = tptr;
	while(1)
	{
	  if(temp->left == NULL)
		break;
	  else
		temp = temp->left;
	}
	do
	{
	cout<<temp->info<<" ";
	temp = temp->right;
	}while(temp->thread == true);


}

/*void post_tra(node* tptr)
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
  */
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
    if( temp->right != NULL  && (temp->thread) == true)
    {
	setright(temp,tdata);
	break;
    }
    else if(temp->right != NULL && (temp->thread)==false)
    {
	temp = temp->right;
    }
    else
    {
      temp->right = getnode();
      temp->thread = false;
    }
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