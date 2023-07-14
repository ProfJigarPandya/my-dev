/* program:
	     Predictive parser with type checker
	     for the language having customized grammer rules of C Language.
	     For Grammer Rules refer to documentation.
*/

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
#define NKEYWORDS 4

/***************************************************************************/
/*		           ERROR MESSAGES DISPLAY HANDLING                 */
   enum error_list
   {
	  Undefined_symbol,
	  statement_missing_SEMICOLON,
	  Declaration_terminated_incorrectly,
	  Missing_comma,
	  Duplicate_variable_declaration,
	  UNKNOWNERROR,
	  Missing_LP,
	  Missing_RP,
	  Missing_LB,
	  Missing_RB,
	  statement_missing_IDENTIFIER,
	  ASSIGNMENT_OPERATOR_NOT_PRESENT,
	  IDENTIFIER_ABSENT,
	  ASSIGNMENT_STATEMENT_MISSING,
	  Type_Mismatch
   };

 // Whenever syntax error detected ... gets assigned error code
 enum error_list c_error_no;

 //input line number... value assigned by LA
 int inlineno=1;

 int errcount=0;

 void print_error(char *lexeme)
 {
   errcount++;
   if(errcount>=15){
	cout<<"\n Too many errors......  will terminate ... press any key to continue ";
	getch(); exit(1);
   }
   cout<<"\nLine#"<<inlineno;
   switch(c_error_no)
   {
	 case Undefined_symbol:
	       cout<<"\t Undefined symbol "<<lexeme;
	       break;
	 case statement_missing_SEMICOLON:
	       cout<<"\t statement missing ; ";
	       break;
	 case Declaration_terminated_incorrectly:
	       cout<<"\t Declaration terminated incorrectly  "<<lexeme;
	       break;
	 case Missing_comma:
	       cout<<"\t Missing comma around"<<lexeme;
	       break;
	 case UNKNOWNERROR:
	       cout<<"\tUnknown error... error type can't be identified"<<lexeme;
	       break;
	 case Missing_LP:
	       cout<<"\t Missing left parenthesis around"<<lexeme;
	       break;
	 case Missing_RP:
	       cout<<"\t Missing right parenthesis around "<<lexeme;
	       break;
	 case Missing_LB:
	       cout<<"\t Missing '('  around "<<lexeme;
	       break;
	 case Missing_RB:
	       cout<<"\t Missing ')' around "<<lexeme;
	       break;
	 case ASSIGNMENT_STATEMENT_MISSING:
	       cout<<"\t The full Assignment statement missing  ";
	       break;
	 case statement_missing_IDENTIFIER:
	       cout<<"\t Missing identifier  "<<lexeme;
	       break;
	 case Duplicate_variable_declaration:
	       cout<<"\t Duplicate variable declaration   "<<lexeme;
	       break;
	 case ASSIGNMENT_OPERATOR_NOT_PRESENT:
	       cout<<"\t assignment operator missing   "<<lexeme;
	       break;
	 case IDENTIFIER_ABSENT:
	       cout<<"\t Within expression identifier absent "<<lexeme;
	       break;
	 case Type_Mismatch:
	       cout<<"\t Type Mismatch "<<lexeme;
	       break;
	 default:
		cout<<"\n sorry, i cant decide.. whats the error ";
      }
}//end of print_error
		      /*END OF ERROR MESSAGE HANDLING*/
/****************************************************************************/


/**************************************************************************/
/* 			     LEXICAL ANALYZER PART			  */

 enum token_type
 {
	 KEYWORD,
	 IDENTIFIER,  DUPLICATE_ID,  NOT_ALLOWED_ID,  UNDEFINED_ID,
	 LP,  RP,   LB,	 RB, END,
	 EQUAL,  PLUS,  MINUS,  MUL,  DIV,  MOD,
	 ASSIGNMENT,
	 COMMA, SEMICOLON, INVALID_TOKEN
 };

 struct node_symb_tbl /* Represents single entry of symbol table */
 {
	char nameofsymbol[20];//lexeme
	enum token_type token;
	struct node_symb_tbl *left,*right;
	char idtype[10]; //type of identifier... int, char, etc.
 };

 struct symb_tbl
 {
	struct node_symb_tbl *symb_tbl_fptr;
	struct node_symb_tbl *symb_tbl_rptr;
	int no_of_entries;
 };
 // Symbol table data structure...
 struct symb_tbl symb_tbl;

 int exec_flag=-1;

 //input file pointer assigned value by main
 FILE *infp;

 //Current token attributes by get_tokan while lookup
 struct node_symb_tbl pcToken;

 //Current declartion type up... i.e. --int-- x,y.... assigned value by specifirs()
 char cTypeDcl[10];

 //type checking while assignment statement...type of identifier on left of =
 char typeleft[10];


/*--------------------------------------------------------------------------*/
/*
   Allocate memory for new node and assign it's left right to NULL
   return address of newly created node
*/
   struct node_symb_tbl* createnode();
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*
   insert new symbol entry orderly into symbol table...
   return pointer to location where inserted...
*/
struct node_symb_tbl* insert_into_sym_table(struct symb_tbl *pCurrentSymT,char *lexeme,enum token_type token,char *typeid);
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/* look for the entry of input lexeme
   if present return pointer to location into symbol table...
   else return null
 */
struct node_symb_tbl* lookup_sym_table(struct symb_tbl *pCurrentSymT,char *lexeme);
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*
   initialize symbol table with entries for all keywords.
*/
void init_sym_table();
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*
  Generates token from input file and returns to caller...parser
  Heart of LA
*/
enum token_type get_token();
/*---------------------------------------------------------------------------*/


struct node_symb_tbl* createnode()
{
 struct node_symb_tbl *newnodeptr;
 newnodeptr = new node_symb_tbl;
 newnodeptr->left = newnodeptr->right = NULL;
 return(newnodeptr);
} 		/* end of createnode */

struct node_symb_tbl* insert_into_sym_table(struct symb_tbl *pCurrentSymT,char *lexeme,enum token_type t,char *typeid)
{
 struct node_symb_tbl *nnptr;
 nnptr = createnode();

 strcpy(nnptr->nameofsymbol,lexeme);
 nnptr->token = t;

 strcpy(nnptr->idtype,typeid); // will be "" if non identifier

 //insert at end... ( ordered linked list helps? NO)
 if(pCurrentSymT->symb_tbl_fptr == NULL)//rptr==NULL first node ...
 {
   pCurrentSymT->symb_tbl_fptr = nnptr;
   pCurrentSymT->symb_tbl_rptr = nnptr;
   pCurrentSymT->no_of_entries = 1;
   return nnptr;
 }

 pCurrentSymT->symb_tbl_rptr->right = nnptr;
 nnptr->left = pCurrentSymT->symb_tbl_rptr;
 pCurrentSymT->symb_tbl_rptr = nnptr;
 pCurrentSymT->no_of_entries++;

 return nnptr;
} 	    /* end of insert_into_syb_tbl .... */
struct node_symb_tbl* lookup_sym_table(struct symb_tbl *pCurrentSymT,char *lexeme)
{
 struct node_symb_tbl *ppos;
 //start searching from end to start of symbol table
 ppos = pCurrentSymT->symb_tbl_rptr;

 while(ppos!=NULL)
 {

	if(strcmp(ppos->nameofsymbol,lexeme)!=0)
		ppos = ppos->left;
	else
		return ppos;
 }

 return ppos;
} 	/* end of lookup_sym_table  */

void init_sym_table()
{
/* Read keywords from file
  FILE *fkw;
  fkw = fopen("keywords.txt","r");
  if(fkw==NULL){
	printf("Can't open keywords file ");
	return;
  }
  char kw[10];
  while(1){
	fscanf(fkw,"%s",kw);
	insert_into_sym_table(&symb_tbl,kw,KEYWORD,"");
	if(feof(fkw))	 return;
  }*/
  char keywords[NKEYWORDS][8]={	"char", "int", "float", "if"};
  for(int i=0;i<NKEYWORDS;i++) //from local array of keywords
	insert_into_sym_table(&symb_tbl,keywords[i],KEYWORD,"");
}             /* End of init_sym_table */

enum token_type get_token()
{
 enum token_type nexttoken;
  //ignore comment  //remove blank spaces in input
  //make unique entry into symbol table  //maintain line number
  //determine token type and return token type
 char ch;  char lexeme[20]={0};  int klex=0;
 int flag=1;

 while(flag) //search a token and return
 {
	 ch=fgetc(infp);
	 if(feof(infp)) { //End of input
		flag = 0; ch=NULL;
	 }
	 switch(ch)
	 {
		case ' ':
		case '\t':
		case '\n': if(ch == '\n')
				   inlineno++;
			   if(klex==0) continue;
			   else{ //string is form, now validate it for token
			     lexeme[klex] = '\0';
			     flag = 0;
			     break;
			   }
		case ',': if(klex==0)
				  return COMMA;
			  else{
				ungetc(',',infp);  lexeme[klex]='\0';
				flag = 0;
				break;
			  }
		case ';': if(klex == 0){
				 exec_flag = 1;
				 return SEMICOLON;
			  }
			  else{
				ungetc(';',infp);
				lexeme[klex]='\0';
				flag = 0;
				break;
			  }
		case '=': if(klex==0)
			    return EQUAL;
			  else{
				ungetc('=',infp);
				lexeme[klex]='\0';
				flag = 0;
				break;
			  }
		case '/':  char nch = fgetc(infp);
			   if(nch == '*') {//starting of comment
			       while(1) { //skip comment
				 ch = fgetc(infp);
				 if(ch == '*') {
					nch = fgetc(infp);
					if(nch=='/')
						break;
				 }
			       }
			   }
			   else { //div
				 ungetc(nch,infp);
				 return DIV;
			   }
			   break;
		case '+': if(klex==0)
				 return PLUS;
			  else {
			      ungetc('+',infp);
			      lexeme[klex]='\0';
			      flag = 0;
			      break;
			  }
		case '(':  if(klex==0)
				  return LB;
			   else {
				ungetc('(',infp);
				lexeme[klex]='\0';
				flag = 0;
				break;
			   }
		case ')':if(klex==0)
				 return RB;
			 else {
				ungetc(')',infp);
				lexeme[klex]='\0';
				flag = 0;
				break;
			  }
		case '-': if(klex==0)
				 return MINUS;
			  else {
				ungetc('-',infp);
				lexeme[klex]='\0';
				flag = 0;
				break;
			  }
		case '*': if(klex==0)
				 return MUL;
			  else {
				ungetc('*',infp);
				lexeme[klex]='\0';
				flag = 0;
				break;
			  }
		case '{': if(klex==0) return LP;
			  else {
				 ungetc('{',infp);
				 lexeme[klex]='\0';
				 flag = 0;
				 break;
			   }
	       case '}':  if(klex==0) return RP;
			  else {
				 ungetc('}',infp);
				 lexeme[klex]='\0';
				 flag = 0;
				 break;
			   }
		default:
			if(isalpha(ch))
				lexeme[klex++] = ch;
	 }//end of switch
 }//end of while
 if(ch==NULL) //end of input
	return END;
 else//either keyword or identifier
 {
     struct node_symb_tbl *ctoken;
	if((ctoken = lookup_sym_table(&symb_tbl,lexeme))==NULL) //entry not found
	{
	      if(exec_flag==0) // parse is in declaration phase
	      {
		insert_into_sym_table(&symb_tbl,lexeme,IDENTIFIER,cTypeDcl);
		strcpy(pcToken.nameofsymbol,symb_tbl.symb_tbl_rptr->nameofsymbol);
		pcToken.token = IDENTIFIER;
		strcpy(pcToken.idtype,cTypeDcl);
		return IDENTIFIER;
	      }
	      else
	      {
	       strcpy(pcToken.nameofsymbol,lexeme);
	       pcToken.token = UNDEFINED_ID;
	       return UNDEFINED_ID;//UNDECLARED_IDENTIFIER; // CAN BE NOT_ALLOWED_HERE
	      }
	}
	else
	{
	   if(exec_flag==0 && ctoken->token==IDENTIFIER)
	   //entry found and an identifier in declaration phase...
	   {
	       strcpy(pcToken.nameofsymbol,lexeme);
	       pcToken.token = DUPLICATE_ID;
	       return DUPLICATE_ID;
	   }
	   else if(exec_flag ==1 && ctoken->token == IDENTIFIER)
	   //entry found , not in declaration phase, an ID
	   {
	    memcpy(&pcToken,ctoken,sizeof(node_symb_tbl));
	    return ctoken->token;
	   }
	   else
	   {
	    memcpy(&pcToken,ctoken,sizeof(node_symb_tbl));
	    exec_flag = 0;
	    return ctoken->token;
	   }
	}
  }
} 		/* End of get_token .. */

				/* END OF LEXICAL ANALYZER */
/***************************************************************************/
/**************************************************************************/
/*			PREDICTIVE PARSER AND TYPE CHECKER                */

/*------------------------prototypes---------------------------------------*/
	int match(enum token_type t); int def_list();
	int stmt_list();  int ndef_list();
	int expr();     int term();  int factor();  int statement();
	int stmt_list();  int nstmt_list(); int assignment(); int def();
	int decl_list();  int specifiers(); int stmt_list(); int decl();
	int ndecl_list(); int if_statement();
/*--------------------------------------------------------------------------*/
	enum token_type lookahead;
/*-------------------------------------------------------------------------*/

int main(int argc,char **argv)
{
  clrscr();
  textcolor(LIGHTGRAY);
  printf("\*******************************************************************************");
  textcolor(CYAN+BLINK);
  cprintf("                          Compiled by         ...  JCompiler                     ");
  textcolor(CYAN);
  printf("\*******************************************************************************");

  cout<<"\n\n";
  enum token_type token;
  if(argc!=2)  {
	cout<<"\n Usage: cc1.exe ifilename.c";
	return 1;
  }
  if ((infp = fopen(argv[1],"r")) == NULL){
	  fprintf(stderr, "Cannot open input file.\n");
	  return 1;
  }
  cout<<" Input file: "<<argv[1];
  init_sym_table();

  //take tokens from la and parse...
  lookahead = get_token(); //the first token

  if(!match(LP)){
       c_error_no =  Missing_LP;
       print_error(pcToken.nameofsymbol);
  }
 while(1){
	if(def_list())
	     if(!match(SEMICOLON)) {
		    c_error_no = statement_missing_SEMICOLON;
		    print_error("");
	     }
	     if(stmt_list())
	       if(!match(SEMICOLON)) {
		    c_error_no = statement_missing_SEMICOLON;
		    print_error("");
	       }
	   if(lookahead == RP){ //end of program
		 if(errcount==0) {
			cout<<" \n COMPILED SUCCESSFULLY ";
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n                     Press any key to continue...";
			getch();
		 }
	    return 1;
	   }
	   if(lookahead == END){
		    cout<<"\n Solve error and then proceed... ";
		    c_error_no = Missing_RP;
		    print_error(pcToken.nameofsymbol);
		    return 1;
	   }
	   while(1) { //panic mode recovery
		     lookahead = get_token() ;
		     if(lookahead == SEMICOLON){
			      lookahead = get_token();
			      break;
		     }
		     if(lookahead == RP || lookahead==END){
			    c_error_no = statement_missing_SEMICOLON;
			    print_error("");
				break;
		     }
	   } //end of panic mode ...recovery ..
  }
}//end of main

int match(enum token_type t)
{
    if(t == lookahead){
       lookahead = get_token();
       return 1;
    }
    else
       return 0;
}

int def_list()
{
  if(!def())        return 0;
  if(!ndef_list())  return 0;
  exec_flag = 1;
  return 1;
}
int def()
{
 if(!specifiers())  return 0;
 if(!decl_list())   return 0;
 return 1;
}
int ndef_list()
{
  switch(lookahead)
  {
    case SEMICOLON:
		  if(!match(SEMICOLON)) {
		    c_error_no = statement_missing_SEMICOLON;
		    print_error(pcToken.nameofsymbol);
		  }
		  break;
    default:
		  return 0;
  }
  if(!def_list())    return 0;
  if(!ndef_list())   return 0;
  return 1;
}

int decl_list()
{
 if(!decl()) 		return 0;
 if(!ndecl_list()) 	return 0;
 return 1;
}
int decl()
{
	   if(!match(IDENTIFIER) && lookahead!=DUPLICATE_ID) {
		    c_error_no = statement_missing_IDENTIFIER;
		    print_error(pcToken.nameofsymbol);
	   }
	   if(lookahead == DUPLICATE_ID) {
	     c_error_no = Duplicate_variable_declaration;
	     print_error(pcToken.nameofsymbol);
	     lookahead=get_token();
	     return 1;
	   }
	   return 1;
}

int ndecl_list()
{
 switch(lookahead)
 {
   case COMMA:
	    if(!match(COMMA)){
		c_error_no = Missing_comma;
		print_error(pcToken.nameofsymbol);
		return 0;
	    }
	    if(!decl())     	return 0;
	    if(!ndecl_list())	return 0;
	    break;
   case SEMICOLON:      return 1;
   case UNDEFINED_ID:
		c_error_no = Undefined_symbol;
		print_error(pcToken.nameofsymbol);
		return 0;
  }
  return 1;
}

int specifiers()
{
 if( (strcmp(pcToken.nameofsymbol,"int")==0) ||
     (strcmp(pcToken.nameofsymbol,"char")==0) ||
     (strcmp(pcToken.nameofsymbol,"float")==0))
 {
    strcpy(cTypeDcl,pcToken.nameofsymbol);
    match(KEYWORD);  exec_flag = 0;
    return 1;
 }
 else {  exec_flag = 1;  return 0;  }
}
int stmt_list()
{
 switch(lookahead){
    case IDENTIFIER:   if(!statement())  return 0;
		       else{
			if(!match(SEMICOLON)){
				    c_error_no = statement_missing_SEMICOLON;
				    print_error("");
			}
			if(!nstmt_list())    return 0;
		       }
		       break;
     case KEYWORD:     if(strcmp(pcToken.nameofsymbol,"if")==0)
		       if(!if_statement()) return 0;
		       break;
     case RP:
     case END:	       return 0;
     case UNDEFINED_ID:
			c_error_no = Undefined_symbol;
			print_error(pcToken.nameofsymbol);
			return 0;
 }
 return 1;
}

//-----------------------if statement-------------------------------------
int if_statement()
{
	lookahead = get_token();
	if(!match(LB)){
		    c_error_no =Missing_LB ;
		    print_error("");
	}
	if(!expr()) 	return 0;
	if(!match(RB)){
		    c_error_no =Missing_RB ;
		    print_error("");
	}
	if(!statement())  return  0;
 return 1;
	 //-------------- end of if part----------------------
/*	get_token();
	if(token==ELSE)
	{
		statement();
	}
*/
}//end of if_stat
int statement()
{
 if(!assignment() && lookahead!=SEMICOLON)   return 0;
 return 1;
}

int nstmt_list()
{
 if(lookahead == RP || lookahead == END || lookahead==SEMICOLON ) return 1;
 if(lookahead == UNDEFINED_ID){
		c_error_no = Undefined_symbol;
		print_error(pcToken.nameofsymbol);
		return 0;
 }
 if(!statement())	return 0;
 if(!nstmt_list())      return 0;
 return 1;
}

int assignment()
{
  strcpy(typeleft,pcToken.idtype);
  if(!match(IDENTIFIER)) {
	c_error_no = ASSIGNMENT_STATEMENT_MISSING;
	print_error(pcToken.nameofsymbol);
	return 0;
  }

 if(!match(EQUAL)) {
	c_error_no = ASSIGNMENT_OPERATOR_NOT_PRESENT;
	print_error(pcToken.nameofsymbol);
	return 0;
 }
 if(!expr())   return 0;
 return 1;
}
int expr()
{
 if(!term()) 	return 0;
 while(1){
	switch(lookahead){
		case PLUS:
		case MINUS:
			  match(lookahead);
			  if(!term())	return 0;
			  continue;
		case UNDEFINED_ID:      c_error_no = Undefined_symbol;
					print_error(pcToken.nameofsymbol);
					return 0;
		default:
					return 1;
	}
 }
}
int term()
{
 if(!factor()) 	return 0;
 while(1) {
	switch(lookahead)
	{
	 case '*':
	 case '/':	match(lookahead);
			if(!factor())
				return 0;
			continue;
	case UNDEFINED_ID:	return 0;
	default:
			return 1;
	}
 }
}
int factor()
{
 switch(lookahead){
  case '(': match(LB); 	expr(); match(RB);
	    break;
  case IDENTIFIER:
		if(strcmp(typeleft,pcToken.idtype)!=0){
			c_error_no = Type_Mismatch;
			char temp[50];
			strcpy(temp,"cant convert from");
			strcat(temp,pcToken.idtype);strcat(temp," to ");
			strcat(temp,typeleft);
			print_error(temp);
			return 0;
		}
		match(IDENTIFIER);
		break;
  case UNDEFINED_ID:	c_error_no = Undefined_symbol;
			print_error(pcToken.nameofsymbol);
			return 1;
  // case PLUS:  case MINUS:  case MUL:  case DIV:  case MOD:
  default:
		c_error_no = IDENTIFIER_ABSENT;
		print_error("");
		return 0;
 }
 return 1;
}

