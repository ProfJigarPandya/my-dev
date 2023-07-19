/* Left factoring a grammar */
/*

  Left factoring is a grammar transformation that is useful for producing a
  grammar suitable for producing a grammar suitable for predictive parsing.

 INPUT GRAMMAR:

( 1 )

     stmt -> if expr then stmt else stmt
	     if expr then stmt

     LEFT FACTORED GRAMMAR:

     stmt -> if expr then stmt   A'
	     A' -> else stmt |  NULL

( 2 )

  INPUT GRAMMAR:
	  A -> Alpha Beta1  | Alpha Beta2

  LEFT FACTORED GRAMMAR:

	  A -> Alpha A'
	  A' -> Beta1 | Beta2

*/

#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#define PROD_LIST 10
#define MAX 10

enum boolean {false,true};
struct node
{
 union
 {
   char list_name[MAX];
   char name;
 }tnt_seq[MAX];

 int count;  //if 0 ... left NT ....else no of right terminals
 struct node *next;
};

struct node* getnode(char *pstr);
struct node* setnt_left(char *p_nt);
void settnt_right(struct node *ptrtoleftnt,char *p_tnt);
void disp_prods_4nt(struct node *stptr);
void disp_all_pro(struct node **pro_listptrs);
void left_factor_grammar(struct node **pro_listptrs,int n);



void main()
{

 struct node *pro_listptrs[PROD_LIST]={NULL};
 int n;
 // array of pointers .. which stores address of production left terminal .linked list

 clrscr();

 pro_listptrs[0] = setnt_left("Stmt");
 settnt_right(pro_listptrs[0],"if Expr then Stmt else Stmt");
 settnt_right(pro_listptrs[0],"if Expr then Stmt");
 settnt_right(pro_listptrs[0],"a");

 pro_listptrs[1] = setnt_left("Expr");
 settnt_right(pro_listptrs[1],"b");

 n = 2;

 cout<<"\nOriginal productions .... ";
 disp_all_pro(pro_listptrs);


 left_factor_grammar(pro_listptrs,n);


 cout<<"\n\n*********        After left factoring ************** \n         *********** New productions ***********\n ";
 disp_all_pro(pro_listptrs);


 getch();
}

/*******/
struct node * getnode(char *pstr)
{
 if(pstr != NULL)
 {
  struct node *tptr;
  tptr = new node;
  strcpy((char *)tptr->tnt_seq,pstr);
  tptr->count = 0;
  tptr->next = NULL;
  return tptr;
 }
 else
   return new node;
}

/* create linked list with nt of left side */
struct node* setnt_left(char *p_nt)
{
  return getnode(p_nt);
}
/********/


/***********/
/*for a left non-terminal linked list function attaches production at end of
 linked list */
void settnt_right(struct node *ptrtoleftnt,char *p_tnt)
{
  struct node *tolast=ptrtoleftnt;
  struct node *root=ptrtoleftnt;
  while(tolast->next!=NULL)
	tolast = tolast->next;

  tolast->next = getnode(NULL);

  int i=0,j=-1;
	 while(1)
	 {
		if(*p_tnt == ' ')
		{
			tolast->next->tnt_seq[i].list_name[++j] =  NULL;
			p_tnt++;
			i++;
			j=-1;
			continue;
		}

		tolast->next->tnt_seq[i].list_name[++j] =  *p_tnt;
		p_tnt++;

		if(*p_tnt == NULL)
		{
			tolast->next->tnt_seq[i].list_name[++j] =  NULL;
			tolast->next->count = i+1;
			tolast->next->next = NULL;
			root->count--;
			return;
		}
	 }
}
/*********/

/************/
/* displays all productions
  uses disp_prods_4nt function for individual nt...traversing a linked list
*/
void disp_prods_4nt(struct node *stptr)
{
 cout<<"\n";
 cout<<(char *)stptr->tnt_seq<<" --> "; //only nonterminal
 stptr=stptr->next;
 int i=0;

 while(1)
 {
   i=0;
  while(i < stptr->count)
   {
    cout<<"\t"<<(char *)(stptr->tnt_seq[i].list_name);
    i++;
    if(stptr->next == NULL)
	return;
   }
   cout<<"\n\t | ";
   stptr=stptr->next;
 }

}
void disp_all_pro(struct node **pro_listptrs)
{
 int i=0;
 while(1)
 {
   if(pro_listptrs[i] == NULL) //end of all productions
	return;
   disp_prods_4nt(pro_listptrs[i]);
   i++;
 }
}
/**********/
void left_factor_grammar(struct node **pro_listptrs,int noofNTS)
{
 int iNTS=0,j=0;
int nextnt=0;
 for(iNTS=0;iNTS<noofNTS;iNTS++)
 {
       //find common string index (ALPHA)....csi ...
       //                 in csin    nodes of linkedlist
       // A-> Alpha Beta1 > Alpha Beta2 ....> Alpha Betacsin > Gema1 | Gema2...

       int csi = 0;
       int csin =(-1) * (pro_listptrs[iNTS]->count); //initially max
       int maxstring  = pro_listptrs[iNTS]->next->count;

       char **oarrptr = new char*[csin];
       char **narrptr = new char*[csin];

       node **aptr = new node*[csin];

       struct node *listptr = pro_listptrs[iNTS]->next;
       struct node *lptr = pro_listptrs[iNTS]->next;

	       for(int u=0;u<csin;u++)
	       {
			strcpy(oarrptr[u],lptr->tnt_seq[0].list_name);
			strcpy(narrptr[u],lptr->tnt_seq[0].list_name);
			lptr = lptr->next;
	       }
	       lptr = pro_listptrs[iNTS]->next;
	       for(u=0;u<csin;u++)
	       {
			aptr[u] = lptr;
			lptr = lptr->next;
	       }

	       oarrptr[u]=NULL;
	       narrptr[u]=NULL;

	       while(1)// till we find matching
	       {


		       for(int o=0;o<csin;o++)
		       {
			 if(narrptr[o] == NULL)
			 {
				nextnt = 1;
			 }
			 if( strcmp(narrptr[o],narrptr[o+1]) !=0 )
			 {
				break;
			 }

		       }

		      if(o+1==csin) //from 0 to csin matched
		      {
			int kk=0;

			       for(u=0;u<csin;u++)
			       {
				strcpy(oarrptr[u],narrptr[u]);
				strcpy(narrptr[u],aptr[u]->tnt_seq[csi+1].list_name);
			       }
			 csi++;
		      }
		      else
		      {

			       if(csi>0 && csin>1) //process
			       {
				 csi++;
				      //process
				//       A  ->               Alpha A' > Gema1 > Gema2....
				//       A' ->              Beta1 > Beta2....  /// csin nodes

				int tt=0;
				struct node* temp = pro_listptrs[iNTS]->next;
				while(tt!=csi)
				{
					cout<<temp->tnt_seq[tt].list_name;
					tt++;
				}
					if(nextnt==1) break;
			       }

			       for(u=0;u<o+1;u++)
			       {
				strcpy(oarrptr[u],narrptr[u]);
				strcpy(narrptr[u],aptr[u]->tnt_seq[csi+1].list_name);
			       }
				csi++;
			       int y=o+1;
			       while(y<csin)
				    narrptr[y++] = NULL;
			       csin=csin - (csin-(o+1));
		      }
	       }//end of while


  }//end for all iNTS
}