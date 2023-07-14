// USING RECURSION tree creation which allows duplicate numbers ...
// a binary search tree ... with pre / in /post order traversal

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>

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

void insert(node**  root,int value)
{
 if(*root==NULL)
 {
   *root = getnode();//(node*) malloc(sizeof(node));
   (*root)->info = value;
//   (*root)->left = NULL;
 //  (*root)->right = NULL;

 }
 else
 {
  if(value<(*root)->info)  //left
  {
   if((*root)->left == NULL)
   {
    (*root)->left = getnode();//(node*)malloc (sizeof(node));//getnode();
    (*root)->left->info = value;
//    (*root)->left->left = NULL;
//    (*root)->left->right = NULL;
    return;
   }
   else
   {
    insert(&((*root)->left),value);
   }
  }
  else  //right insertion
  {
   if((*root)->right == NULL)
   {
    (*root)->right = getnode();
    (*root)->right->info = value;
    return;
   }
   else
   {
    insert(&((*root)->right),value);
   }
  }
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


void main()
{

node* t;
t = NULL;

clrscr();
insert(&t,12);

insert(&t,25);
insert(&t,2);
insert(&t,11);
insert(&t,29);

in_tra(t);

getch();
}