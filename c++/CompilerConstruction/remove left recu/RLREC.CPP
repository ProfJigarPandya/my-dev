/* program
   AIM: TO CHECK WHETHER LEFT RECURSION IS PRESENT IN INPUT GRAMMER.

   THE PROGRAM APPLIES THE ALGORITHM AND CHECKS FOR PRESENCE OF LEFT
   RECURSION,
      IF PRESENT IT GIVES STEP WISE OUTPUT
      OTHERWISE MESSAGE " THE INPUT GRAMMER IS NOT LEFT RECURSIVE AT ALL"

   IT WORKS FOR BOTH IMEDIATE AS WELL AS NON-IMEDIATE LEFT RECURSION.

   LIMITATION:
     * THE GRAMMER MUST HAVE TERMINALS AND NONTERMINALS OF SINGLE CHARACTER.
     * THE INPUT GRAMMER MUST BE IN SPECIFIC ORDER....
     * THE INPUT GRAMMER MUST BE VALID GRAMMER, IF NOT IT MAY GENERATE WRONG RESULT.

   REFERENCE:
	    TOPIC: ELIMINATION OF LEFT RECURSION
	    PG.176,177 OF
		  COMPILERS  .. PRINCIPLES,TECHNIQUES AND TOOLS
		    BY, ALFRED V. AHO
			RAVI SETHI
			JEFFREY D.ULLMAN
			FIFTH INDIAN REPRINT PEARSON EDUCATION.

   DEVELOPED BY:
		 JIGAR M PANDYA
		 MT-07 ( ME SEM II)
		 25/8/2006.
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
 char tnt_seq[MAX];
 struct node *next;
};

enum boolean islr=false; /// becomes true if the grammer is left recursive

struct node * getnode(char *pstr);
struct node* setnt_left(char *p_nt);
void settnt_right(struct node *ptrtoleftnt,char *p_tnt);
void disp_prods_4nt(struct node *stptr);
void disp_all_pro(struct node **pro_listptrs);
enum boolean IsAiAjGemaForm(char Aj,struct node *ptrtorights);
void remove_ind_leftr(struct node **pro_listptrs);
enum boolean GetDelta_k(struct node *pro_listptr,char *delta,int k);
struct node * insertinto(struct node *ptrtorights,char *delta);
enum boolean isleftrecursive(char Ai,struct node *pro_ptr);


void main()
{

 struct node *pro_listptrs[PROD_LIST]={NULL};
 // array of pointers .. which stores address of production left terminal .linked list
 clrscr();

 //// output file res0.txt for first two productions .........
 pro_listptrs[0] = setnt_left("S");
 settnt_right(pro_listptrs[0],"Aa");
 settnt_right(pro_listptrs[0],"b");

 pro_listptrs[1] = setnt_left("A");
 settnt_right(pro_listptrs[1],"Ac");
 settnt_right(pro_listptrs[1],"Sd");
 settnt_right(pro_listptrs[1],"^");

 pro_listptrs[2] = setnt_left("B");
 settnt_right(pro_listptrs[2],"Be");
 settnt_right(pro_listptrs[2],"Af");
 settnt_right(pro_listptrs[2],"Sf");

 //// output file res1.txt for all above three productions .........



/*
 ///  output file res2.txt
 pro_listptrs[0] = setnt_left("S");
 settnt_right(pro_listptrs[0],"(L)");
 settnt_right(pro_listptrs[0],"a");

 pro_listptrs[1] = setnt_left("L");
 settnt_right(pro_listptrs[1],"L,S");
 settnt_right(pro_listptrs[1],"S");

*/

/*
 //// output file res3.txt for first two productions .........
 pro_listptrs[0] = setnt_left("E");
 settnt_right(pro_listptrs[0],"EoT");
 settnt_right(pro_listptrs[0],"T");

 pro_listptrs[1] = setnt_left("T");
 settnt_right(pro_listptrs[1],"TaF");
 settnt_right(pro_listptrs[1],"F");

 pro_listptrs[2] = setnt_left("F");
 settnt_right(pro_listptrs[2],"nF");
 settnt_right(pro_listptrs[2],"(E)");
 settnt_right(pro_listptrs[2],"t");
 settnt_right(pro_listptrs[2],"f");
*/


 /*
 //// output file res4.txt for first two productions .........
 pro_listptrs[0] = setnt_left("A");
 settnt_right(pro_listptrs[0],"Ax");
 settnt_right(pro_listptrs[0],"b");
 */

/*
 //// output file res5.txt for first two productions .........
 pro_listptrs[0] = setnt_left("S");
 settnt_right(pro_listptrs[0],"S+S");
 settnt_right(pro_listptrs[0],"SS");
 settnt_right(pro_listptrs[0],"S*S");
 settnt_right(pro_listptrs[0],"a");
 settnt_right(pro_listptrs[0],"(S)");
*/


/*
 //// output file res6.txt for first two productions .........
 pro_listptrs[0] = setnt_left("A");
 settnt_right(pro_listptrs[0],"Ac");
 settnt_right(pro_listptrs[0],"Aad");
 settnt_right(pro_listptrs[0],"bd");
 settnt_right(pro_listptrs[0],"^");
*/


/*
 //// output file res7.txt for first two productions .........
 pro_listptrs[0] = setnt_left("S");
 settnt_right(pro_listptrs[0],"S(S)S");
 settnt_right(pro_listptrs[0],"^");
*/
/*
 //// output file res8.txt for first two productions .........
 pro_listptrs[0] = setnt_left("E");
 settnt_right(pro_listptrs[0],"EbEpE");
 settnt_right(pro_listptrs[0],"EbE");
 settnt_right(pro_listptrs[0],"EpE");
 settnt_right(pro_listptrs[0],"{E}");
 settnt_right(pro_listptrs[0],"c");
*/
 /*
 //// output file res9.txt for first two productions .........
 pro_listptrs[0] = setnt_left("E");   // E->TE' here E' is X
 settnt_right(pro_listptrs[0],"TX");

 pro_listptrs[1] = setnt_left("X");
 settnt_right(pro_listptrs[1],"+TX");
 settnt_right(pro_listptrs[1],"^");

 pro_listptrs[2] = setnt_left("T");     // T->FT' here T' is Y
 settnt_right(pro_listptrs[2],"FY");

 pro_listptrs[3] = setnt_left("Y");
 settnt_right(pro_listptrs[3],"*FY");
 settnt_right(pro_listptrs[3],"^");

 pro_listptrs[4] = setnt_left("F");
 settnt_right(pro_listptrs[4],"(E)");
 settnt_right(pro_listptrs[4],"i");
 */
 cout<<"\nOriginal productions .... ";
 disp_all_pro(pro_listptrs);

 //removes imediate as well as non-imediate left recursion from grammer ...
 remove_ind_leftr(pro_listptrs);


 cout<<"\n\n*********        After elimination of left recursions************** \n         *********** New productions ***********\n ";
 disp_all_pro(pro_listptrs);

 if(islr==false)
       cout<<"\n The input grammer is not left recursive at all";


 getch();
}

/*******/
struct node * getnode(char *pstr)
{
  struct node *tptr;
  tptr = new node;
  strcpy(tptr->tnt_seq,pstr);
  tptr->next = NULL;
  return tptr;
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
  while(tolast->next!=NULL)
	tolast = tolast->next;
  tolast->next = getnode(p_tnt);
}
/*********/

/************/
/* displays all productions
  uses disp_prods_4nt function for individual nt...traversing a linked list
*/
void disp_prods_4nt(struct node *stptr)
{
 cout<<"\n";
 cout<<stptr->tnt_seq<<" --> "; //only nonterminal
 stptr=stptr->next;

 while(stptr->next != NULL)
 {
   cout<<stptr->tnt_seq<<" | ";
   stptr=stptr->next;
 }
 cout<<stptr->tnt_seq;
 cout<<"\n";

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
enum boolean IsAiAjGemaForm(char Aj,struct node *ptrtorights)
{
  if(ptrtorights->tnt_seq[0] == Aj) // and seq[1]!=NULL..unit production not allowed
    return true;
  else
    return false;
}
/**********/
/*******/
enum boolean GetDelta_k(struct node *pro_listptr,char *delta,int k)
{
 int i=0;
 for(i=0;i<k;i++)
 {
   pro_listptr = pro_listptr->next;
 }
 if(pro_listptr == NULL)
	return false;
 strcpy(delta,pro_listptr->tnt_seq);
 return true;
}
/********/
/******/
struct node * insertinto(struct node *ptrtorights,char *delta)
{
  struct node *temp = getnode(delta);
  ptrtorights->next = temp;
  return temp;
}
/*****/
/*******/
enum boolean isleftrecursive(char Ai,struct node *pro_ptr,struct node **pptrAAlpha,struct node **pptrBeta)
{
	boolean flag=false;
	struct node *temp1=pro_ptr,*temp2;

	while(temp1!=NULL)
	{
	  if(Ai==temp1->tnt_seq[0])
	  {
		  flag=true;
		  islr=true;
		  break;
	  }
	  temp1=temp1->next;
	}
	/// make order....... AAlpah1..... Beta1 Beta2.. right now assumed in order

	if(!flag)
	    return flag;

	////for ptr to AAlpha1 n Beta1
	*pptrAAlpha = pro_ptr;
	temp2=pro_ptr;
	while(1)
	{
		if(temp2->next->tnt_seq[0]!=Ai)
		{
			*pptrBeta = temp2->next;
			temp2->next = NULL; // separate two lists...
			break;
		}
		temp2=temp2->next;
	}
	return flag;
}
/******/
void remove_ind_leftr(struct node **pro_listptrs)
{
 int n,i=0,j;
 while(pro_listptrs[i]!=NULL) i++;
 n=i; // no of non-terminals...
 char Ai,Aj,Gema[MAX-1];
 for(i=0;i<n;i++)
 {
  Ai = pro_listptrs[i]->tnt_seq[0];
  for(j=0;j<i;j++)
  {
  /*
     replace each production of the form Ai->Aj Gema by productions
     Ai->Delta1 Gema | Delta2 Gema |...Deltak Gema
     Where Aj->Delta1 | Delta2 |.. |Deltak are all current Aj productions.
  */
  Aj = pro_listptrs[j]->tnt_seq[0];
  struct node *ptrtorightsi=pro_listptrs[i];//leftnt

     while(ptrtorightsi->next!=NULL)//??? next ???
     {
       struct node *rema_proptr;
       char delta[MAX];
       int flag=false;
       if(IsAiAjGemaForm(Aj,ptrtorightsi->next)) // then replace
       {
	 strcpy(Gema,&(ptrtorightsi->next->tnt_seq[1]));//remaining string
	 rema_proptr = ptrtorightsi->next->next;
	 //insert Aj->Delta1 Gema | Delta2 Geme ...
	 int k=1;
	 do
	 {
	   if( GetDelta_k(pro_listptrs[j],delta,k) == false ) break;
	   strcat(delta,Gema);//now delta is deltagema
	   ptrtorightsi = insertinto(ptrtorightsi,delta);
	   flag=true;
	   k++;
	 }while(1);
	 //attach rema_proptr
	 ptrtorightsi->next = rema_proptr;
       }
       if(flag==false)
	 ptrtorightsi=ptrtorightsi->next;
     }
  }//end of inner for jj
    cout<<"\nstep"<<i<<"before removing left recursion";
    disp_all_pro(pro_listptrs);

  // eliminate left recursion among Ai
   /* A->AAlpha1|AAlpha2|....|AAlpham|Beta1|Beta2|...|Betan
     where Betai doesnt begin with A
     then A productions are rewritten as
       A->Beta1A'|Beta2A'|...|BetanA'
       A'->Alpha1A'|Alpha2A'|...|AlphamA'|^ , where Alpha1... should not be null
   */
   struct node *ptrAAlpha=NULL,*ptrBeta=NULL;

   int knewstore=0;
   for(knewstore=0;pro_listptrs[knewstore]!=NULL;knewstore++);

   if(isleftrecursive(Ai,pro_listptrs[i]->next,&ptrAAlpha,&ptrBeta)==true)
   {
       //       creat  Ai'->....
       char str[MAX];//infact of 2
       str[0]=Ai;
       str[1]='\'';
       str[2]='\0';
       pro_listptrs[knewstore]=setnt_left(str);
       pro_listptrs[knewstore++]->next = ptrAAlpha;
       while(1)
       {
	 char temp[MAX];
	 strcpy(temp,ptrAAlpha->tnt_seq);
	 strcpy(ptrAAlpha->tnt_seq,strcat(&temp[1],str));
	 if(ptrAAlpha->next == NULL)
	 {
		ptrAAlpha->next = getnode("^");
		break;
	 }
	 ptrAAlpha=ptrAAlpha->next;
       }

       //       modify Ai-> ....
       pro_listptrs[i]->next = ptrBeta;
       while(ptrBeta!=NULL)
       {
	strcat(ptrBeta->tnt_seq,str);
	ptrBeta=ptrBeta->next;
       }
   }
    cout<<"\nstep"<<i<<"after removing left recursion...";
    disp_all_pro(pro_listptrs);

 }

}
/**********/