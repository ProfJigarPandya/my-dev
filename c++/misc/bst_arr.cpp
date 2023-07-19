
// a binary search tree ... usint implicit array representation
// i.e each node is given a no.
// then if a node is of number p ,stored at arr[p] ...
//then it's left son is stored
// at arr[2*p + 1 ] while right son is stored at arr[2 * p +2 ]


#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <iostream.h>

#define NUMNODES 500
int  node[NUMNODES]={0};
//array

void maketree(int data)
{
  node[0] = data;
}
void setleft(int parent,int data)
{
  if(parent>=NUMNODES ||  ( (2*parent)+1 ) >= NUMNODES )
  {
   cout<<"overflow";
   return;
  }
  else if(   node[ (2*parent)+1 ] != 0 )
  {
	cout<<" invalid allocation ";
	return;
  }
  else
  {
   node[2*parent+1] = data;
  }
}
void setright(int parent,int data)
{
  if(parent>=NUMNODES ||  ( (2*parent)+2 ) >= NUMNODES )
  {
   cout<<"overflow";
   return;
  }
  else if( node[ (2 * parent) +2]!=0)
  {
	cout<<" invalid insertion ";
	return;
  }
  else
  {
   node[2*parent+2] = data;
  }
}
void in_tra(int index)
{
 if(node[index]==0)
   return;
 in_tra(index*2+1);
 printf(" %d ",node[index]);
 in_tra(index*2+2);
}
/*
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
} */

void makebinarysearchtree()
{

char ch;
int tdata;
int index=-1,temp;
while(1)
{

 cout<<"\n want to enter ( y/n )";
 cin>>ch;
 if(ch=='n')
	break;
 cout<<"\n enter data ";
 cin>>tdata;

 if(index!=-1)
 {
  temp = index;
  while(1)
  {

   if(tdata< node[temp]) // set left
   {
    if( (node[2*temp+1]) == 0)
    {
	setleft(temp,tdata);
	break;
    }
    else
	temp = 2*temp+1;
   }
   else //set right
   {
    if( (node[2*temp +2]) == 0)
    {
	setright(temp,tdata);
	break;
    }
    else
	temp = 2*temp+2;
   } //end of else
  }// end of inner while(1)
 } //EN D O F IF
 else
 {
	maketree(tdata);
	index++;
 }
}   //END of outer while(1) .. entering data

}

void main()
{
clrscr();
makebinarysearchtree();
in_tra(0);
getch();
}