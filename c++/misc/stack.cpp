#include <iostream.h>
#include <conio.h>
#include <process.h>


#define MAX 2

class stack
{
	private:
		int data[MAX];
		int topofstack;

	public:
		stack()
		{
			topofstack=-1;
		}

		void showall();
		void push(int value);
		int pop();
		void valueattopofstack();

};

void stack::showall()
{
    if(topofstack == -1)
       cout<<"\n showall: The Stack is empty   ";
    else
    {
	cout<<"\n showall: STACK CONTENT  ---  Every element are listed below ";
	for(int i=0;i<=topofstack;i++)
	{
		cout<<"\n  "<<data[i];
	}
    }
}
void stack::push(int value)
{
	if( topofstack >= MAX-1 )
	{
		cout<<"\n push: Sorry .... Action cancalled because of STACK OVERFLOW \n       : EMPTY THE STACK FIRST THEN PUSH MORE   ";
		return;
	}
	else
	{
		topofstack++;
		data[topofstack] = value;
		cout<<"\n push:  "<<value<<" is pushed ";
	}
}
int stack::pop()
{
	if( topofstack <= -1 )
	{
		cout<<" \n pop: Sorry .... Action cancalled because of STACK UNDERFLOW \n     : PUSH SOME VALUE ON STACK "
		    <<" THEN ONLY POP CAN BE DONE ";
		return NULL;
	}
	else
	{
		return( data[topofstack--] );
	}
}

void stack::valueattopofstack()
{
    cout<<"\n valueattopofstack: The index  of topofstack is "<<topofstack;
    if(topofstack>-1)
	    cout<<"\n                  : Stack Value at that index is "<<data[topofstack];
    else
	    cout<<"\n valueattopofstack: Stack is empty ";
}




void main()
{
	clrscr();
	stack obj;

	obj.push(5);
	obj.push(4);

	obj.push(3);
	obj.valueattopofstack();
	obj.showall();

	cout<<"\n main: "<<obj.pop()<<" is poped ";
	cout<<"\n main: "<<obj.pop()<<" is poped ";

	obj.showall();

	cout<<"\n main: "<<obj.pop()<<" is poped ";

	obj.push(23);
	obj.showall();
	cout<<"\n main: "<<obj.pop()<<" is poped ";
	obj.valueattopofstack();

	cout<<"\n Good Bye - Have a nice day - Yes OOPs is the power of computer";


	getch();

}