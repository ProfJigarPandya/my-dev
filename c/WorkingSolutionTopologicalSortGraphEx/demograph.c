#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myclibrary/include/dynamicgraph.h"
#include "myclibrary/include/linearslinkedlist.h"
#include "myclibrary/include/linearslinkedlist_gn.h"
#include "myclibrary/include/simplequeue_gn.h"


void insertnode(struct gnode **ppgraph,char nodeno[],struct gnode **pfirst);
void createedge(struct gnode *pgraph,char sno[],char dno[],int w);

void displaygraph(struct gnode *pgraph);

void initallnonvisited(struct gnode *pgraph);
struct gnode * locatenode(struct gnode *pgraph, char no[]);

void traversedfs(struct gnode *pgraph,char startno[],struct snode_gn **topolist);
void dfs(struct gnode *pgraph, struct gnode *startnode,struct snode_gn **topolist);

void traversebfs(struct gnode *pgraph,char startno[]);
void bfs(struct gnode *pgraph, struct gnode *startnode);


//int genTopologicalSortLL(struct gnode *pgraph, struct snode_gn **ptoplogicalLL);

int globaltime=0;

int main()
{
	struct gnode *pgraph=NULL;
	struct snode_gn *topolist=NULL;
	insertnode(&pgraph,"shirt",&pgraph);
	insertnode(&pgraph,"tie",&pgraph);
	insertnode(&pgraph,"jacket",&pgraph);
	insertnode(&pgraph,"belt",&pgraph);
	insertnode(&pgraph,"watch",&pgraph);

	insertnode(&pgraph,"undershorts",&pgraph);
	insertnode(&pgraph,"pants",&pgraph);
	insertnode(&pgraph,"shoes",&pgraph);
	insertnode(&pgraph,"socks",&pgraph);
	
	createedge(pgraph,"shirt","tie",0);
	createedge(pgraph,"tie","jacket",0);
	createedge(pgraph,"shirt","belt",0);
	createedge(pgraph,"socks","shoes",0);
	
	createedge(pgraph,"undershorts","pants",0);
	createedge(pgraph,"undershorts","shoes",0);
	createedge(pgraph,"pants","shoes",0);
	createedge(pgraph,"pants","belt",0);
	createedge(pgraph,"belt","jacket",0);
	//displaygraph(pgraph);
	
	
	initallnonvisited(pgraph);
	//temporarily manually traversing all nodes which can not be reached from source
	traversedfs(pgraph,"shirt",&topolist);
	traversedfs(pgraph,"watch",&topolist);
	traversedfs(pgraph,"undershorts",&topolist);
	traversedfs(pgraph,"socks",&topolist);

	displaygraph(pgraph);
	/*traversedfs(pgraph,"B");
	traversedfs(pgraph,"C");
	traversedfs(pgraph,"D");
	traversedfs(pgraph,"E");
	traversedfs(pgraph,"F");
	

	traversebfs(pgraph,"A");
	traversebfs(pgraph,"B");
	traversebfs(pgraph,"C");
	traversebfs(pgraph,"D");
	traversebfs(pgraph,"E");
	traversebfs(pgraph,"F");*/
	
	printf("\n ******** TOPOLOGICAL SORTING LIST ************ \n");
	traverseSLL_gn(topolist);
	printf("\n Have a nice day!");
	return(0);
}
void insertnode(struct gnode **ppgraph,char nodeno[],struct gnode **pfirst)
{
        if(*ppgraph == NULL)//first node
        {
          (*ppgraph) = (struct gnode *) malloc(sizeof(struct gnode));
          (*ppgraph)->edgelist = NULL;
          strcpy((*ppgraph)->nodeno,nodeno);
          if(*pfirst == NULL)
                *pfirst = *ppgraph;

          (*ppgraph)->nextnode = *pfirst; //circular
        }
        else if ((*ppgraph)->nextnode == *pfirst) //single node. first and last the same node.
        {
          	 (*ppgraph)->nextnode = (struct gnode *) malloc(sizeof(struct gnode));
                 (*ppgraph)->nextnode->edgelist = NULL;
                 strcpy((*ppgraph)->nextnode->nodeno,nodeno);
                 (*ppgraph)->nextnode->nextnode  = *pfirst;
        }
        else
        {
                insertnode(&((*ppgraph)->nextnode),nodeno,&(*pfirst));
        }
}


void createedge(struct gnode *pgraph,char sno[],char dno[],int w)
{
 if(pgraph == NULL)
 {
	printf("\nEmpty graph "); 
	return;
 }

 
 struct gnode *sptr; // let sptr point to the node having no .. sno
 sptr = locatenode(pgraph,sno);


 if(sptr==NULL)
 {
        printf("\nInvalide source node number");
        return;
 }

 struct gnode *dptr; // let dptr point to the node having no.. dno
 dptr = locatenode(pgraph,dno);

 if(dptr==NULL)
 {
        printf("\nInvalide destination node number ");
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
struct gnode * locatenode(struct gnode *pgraph, char no[])
{
 struct gnode *ptr=pgraph; // let ptr point to the node having no .. sno

 while(1)
 {  
    if( (strcmp(ptr->nodeno, no) == 0) || (ptr==NULL))
                break;
   ptr = ptr->nextnode;
 }

 if(ptr==NULL)
 {      
        printf("\nInvalide node number %s",no);
        return NULL;
 }
 else
 {
	//printf("\nfound %s",no);
	return ptr;
 }
}

void traversedfs(struct gnode *pgraph,char startno[],struct snode_gn **topolist)
{
	printf("\n DFS Traversal ");
	if(pgraph==NULL)
		return;
	struct gnode *ptr = locatenode(pgraph,startno);
	
	printf("\n *********** DFS Traversal from node %s ************** ",startno);
	dfs(pgraph, ptr, topolist);	

	
}


void initallnonvisited(struct gnode *pgraph)
{
	struct gnode *travnode=pgraph;
	if(pgraph==NULL)
		return;
	
	do
	{
		travnode->visited=0;
		travnode=travnode->nextnode;
	}while(travnode!=pgraph);

}
void dfs(struct gnode *pgraph, struct gnode *startnode, struct snode_gn **topolist)
{
	struct edge *travedges;
	if(pgraph==NULL || startnode==NULL)
		return;

	if(!(startnode->visited))
	{
		printf("\nNode Visited:  %s",startnode->nodeno);
		startnode->visited=1;
		startnode->discovered=++globaltime;
		
		travedges=startnode->edgelist;
		//display outgoing edges from a node
		while(travedges)
		{
			//printf("\n\t\t(DestinationNode %s, Weight %d )",travedges->dnptr->nodeno,travedges->weight);
			//printf("\n Press key to traverse further ");
			//getchar();
			dfs(pgraph,travedges->dnptr,topolist);
			travedges =travedges->nextedge;
		}
		startnode->finished=++globaltime;
		insertLinearSLLFront_gn(topolist,startnode);
	}
	else
		return;
	
}
void displaygraph(struct gnode *pgraph)
{
	struct gnode *travnodes=pgraph;
	struct edge  *travedges;
	if(pgraph==NULL)
	{
		printf("\n Empty graph");
		return;
	}
	
	do
	{
		printf("\nNode Source %s -> ",travnodes->nodeno);
		printf("\t discovered at %d -> ",travnodes->discovered);
		printf("\t finished at %d -> ",travnodes->finished);
		travedges=travnodes->edgelist;
		//display outgoing edges from a node
		while(travedges)
		{
			printf("\n\t\t(DestinationNode %s, Weight %d )",travedges->dnptr->nodeno,travedges->weight);
			travedges =travedges->nextedge;

		}

		travnodes = travnodes->nextnode;
	}while(travnodes!=pgraph);
}

void traversebfs(struct gnode *pgraph,char startno[])
{
        printf("\n BFS Traversal ");
        if(pgraph==NULL)
                return;
        struct gnode *ptr = locatenode(pgraph,startno);
        
        initallnonvisited(pgraph);
        printf("\n *********** BFS Traversal from node %s ************** ",startno);
        bfs(pgraph, ptr);
  
}

void bfs(struct gnode *pgraph, struct gnode *startnode)
{
 	struct edge *travedges;
	struct squeue_gn q;
    struct gnode* data=NULL;

	initSQueue_gn(&q);


        if(pgraph==NULL || startnode==NULL)
                return;
        
	insertSQueue_gn(&q,startnode);
	
	
	
	do
	{
		if(deleteSQueue_gn(&q,&data))
			printf("");
                	//printf("\n Removed %s",data->nodeno);
        	else
			printf("");
                	//printf("\n Can't delete as the queue is empty currently. ");

		if(!(data->visited))
        	{       

                	printf("\nNode Visited:  %s",data->nodeno);
                	data->visited=1;
                
               	 	travedges=data->edgelist;
                	//display outgoing edges from a node
                	while(travedges)
                	{       
				
				insertSQueue_gn(&q,travedges->dnptr);
                	        travedges =travedges->nextedge;
                	}
		}

	}while(!isEmptySQueue_gn(&q));
}

/*int genTopologicalSortLL(struct gnode *pgraph, struct snode_gn **pToplogicalLL)
{
	return 0;
}*/