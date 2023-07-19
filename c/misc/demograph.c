#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node;
struct edge
{
 struct node* dnptr;
 int weight;
 struct edge* nextedge;
};

struct node
{
 struct edge *edgelist;
 char nodeno[10];
 struct node *nextnode;
};

void insertnode(struct node **ppgraph,char nodeno[]);
void createedge(struct node **ppgraph,char sno[],char dno[],int w);
int main()
{
	return(0);
}
void insertnode(struct node **ppgraph,char nodeno[])
{
 static struct node *first=NULL;
        if(*ppgraph == NULL)//first node
        {
          (*ppgraph) = (struct node *) malloc(sizeof(struct node));
          (*ppgraph)->edgelist = NULL;
          strcpy((*ppgraph)->nodeno,nodeno);
          if(first == NULL)
                first = *ppgraph;

          (*ppgraph)->nextnode = first; //circular
        }
        else if ((*ppgraph)->nextnode == first) //last node
        {
          	 (*ppgraph)->nextnode = (struct node *) malloc(sizeof(struct node));
                 (*ppgraph)->nextnode->edgelist = NULL;
                 strcpy((*ppgraph)->nextnode->nodeno,nodeno);
                 (*ppgraph)->nextnode->nextnode  = first;
        }
        else
        {
                insertnode(&((*ppgraph)->nextnode),nodeno);
        }
}


void createedge(struct node **ppgraph,char sno[],char dno[],int w)
{
 if(*ppgraph == NULL)
 {
	printf("Empty graph "); 
	return;
 }

 struct node *sptr=*ppgraph; // let sptr point to the node having no .. sno

 while(1) //  (sptr->position.x - 5)   sno && sptr!=NULL )
 {
    if( (strcmp(sptr->nodeno, sno) == 0) || (sptr==NULL))
                break;
   sptr = sptr->nextnode;
 }



 if(sptr==NULL)
 {
        printf("Invalide source node number");
        return;
 }

 struct node *dptr=*ppgraph; // let dptr point to the node having no.. dno
 while(1)
 {
    if( (strcmp(sptr->nodeno, dno)==0) || (dptr==NULL))
                break;
    dptr = dptr->nextnode;
 }

 if(dptr==NULL)
 {
        printf("Invalide destination node number ");
        return;
 }

 //create and attach actual edge..
 struct edge *neptr;
 neptr = (struct edge* ) malloc(sizeof(struct edge));

 neptr->dnptr = dptr;
 neptr->weight = w;
 neptr->nextedge = NULL;
 if(sptr->edgelist == NULL)
 {
	 sptr->edgelist = neptr;
 	return;
 }
 struct edge *eptr = sptr->edgelist;
 while(eptr->nextedge!=NULL)
 {
	 eptr = eptr->nextedge;
 }
 eptr->nextedge = neptr;

}
