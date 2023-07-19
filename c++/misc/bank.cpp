#include <fstream.h>
#include <conio.h>
#include <process.h>

class BANK
{
 private:
	char name[15];
	int acc_no;
	long int balance;
 public:
	void showdata()
	{
	  cout<<"\n Hello "<<name;
	  cout<<"\t Current Balance "<<balance<<"\taccount NO: "<<acc_no;
	}
	void getdata(int acc)
	{
	 cout<<"\n enter name";
	 cin>>name;
	 cout<<"enter initial balance ";
	 cin>>balance;
	 cout<<"Thanks........ Your account no. is"<<acc;
	 acc_no =acc;
	}
	int ret_acc_no() {return acc_no;}
	long int ret_balance(){return balance;}
	int withdraw(long int amt);
	void deposit(long int amt);
};
int BANK::withdraw(long int amt)
	{
	  if(amt>balance)
	  {
		cout<<"\n Sorry, NO enough balance ";
		return 0;
	  }
	  balance -=amt;
	  cout<<"\n Transaction Successful ";
	  showdata();
	  return 1;
	}
 void BANK::deposit(long int amt)
	{
	  balance +=amt;
	  cout<<"\n Transaction Successful ";
	  showdata();
	}


void main()
{
 clrscr();
 int lastaccno;
 fstream file;

 file.open("Account",ios::ate|ios::in|ios::out|ios::nocreate);

 if(file.bad())
 {
  lastaccno = 0;
  file.open("Account",ios::ate|ios::in|ios::out);
 }
 else
 {
  file.seekg(0,ios::end);
  lastaccno = file.tellp()/sizeof(BANK);
 }

 do
 {
   cout<<"\n MENU :"
	<<"\n PRESS     1   for NEW ACCOUNT "
	<<"\n PRESS     2   for Operating on old account "
	<<"\n PRESS     3   for display all "
	<<"\n PRESS	999 to exit ";
   int choice;
   cin>>choice;
   switch(choice)
   {
   case 1: //new
	  {
	   BANK obj;
	   obj.getdata(lastaccno+1);
	   lastaccno++;
	   if(file.eof())
		file.clear();
	   file.seekp(0,ios::end);
	   file.write((char *) & obj,sizeof(obj));
	   file.flush();
	  break;
	  }
   case 2: //old
	 {
	 int choice;
	 int tempacc;
	 BANK tempobj;
	 if(file.eof())
		file.clear();
	 cout<<"\n Enter Old Account no. to operata on ";
	 cin>>tempacc;
	 if(tempacc>lastaccno)
	 {
		cout<<"\n Invalid acc. no ";
		break;
	 }

	 file.seekg((tempacc-1)*sizeof(BANK),ios::beg);
	 file.read((char *) & tempobj,sizeof(BANK));

	 cout<<"\n INNER MENU "
	       <<"\n press    1          for balance Inquiry "
	       <<"\n press    2		 for deposit money "
	       <<"\n press    3		 for withdraw "
	       <<"\n press    999 to Main Menu         ";
	 cin>>choice;
	 switch(choice)
	 {
	  case 1://balance inquiry
		tempobj.showdata();
		break;
	  case 2: // deposit
	       {
		int amt;
		cout<<"\n enter Amount to be deposit ";
		cin>>amt;
		tempobj.deposit(amt);
		file.seekp((tempacc-1)*sizeof(BANK),ios::beg);
		file.write((char *) &tempobj,sizeof(BANK));
		file.flush();
	       }
		break;
	  case 3:// withdraw
		{
		int amt;
		cout<<"\n enter Amount to be withdraw";
		cin>>amt;
		if(tempobj.withdraw(amt)==1)
		{
			file.seekp((tempacc-1)*sizeof(BANK),ios::beg);
			file.write((char *) &tempobj,sizeof(BANK));
			file.flush();
		}
		}
		break;
	  case 999: //back to main
		break;
	  default:
		cout<<"\n Miss pressed of keys ";
	 }
	 break;
	 }
   case 3: //display all
	  if(lastaccno == 0)
		break;
	  BANK tempobj;
	  if(file.eof())
		file.clear();
	  file.seekg(0);
	  do
	  {
		file.read((char *) & tempobj,sizeof(BANK));
		if(!file)
		     break;
		tempobj.showdata();
	 }while(1);


	 break;
   case 999://exit
	cout<<"\nHave a nice time ahead ";
	exit(0);
   default://miss pressed
	cout<<"\n Miss pressed of key Please try again";
   }
 }while(1);

}