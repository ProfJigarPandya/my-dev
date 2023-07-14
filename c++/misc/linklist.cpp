#include <iostream.h>
#include <conio.h>

struct Link
{
 int data;
 Link *next;
};
class LinkList
{
 Link *first;
 public:
	LinkList()
	{ first = NULL; }
	void additem(int d)
	{

	  Link* newLink = new Link;
	  newLink->data = d;
	  newLink->next = first;
	  first = newLink;
	}
	void display()
	{
	Link* current=first;
	while(current != NULL)
	{
	  cout<<endl<<current->data;
	  current = current->next;
	}
	}

};
void main()
{
 clrscr();
 LinkList li;
 li.additem(25);
 li.additem(36);
 li.additem(49);
 li.additem(64);

 li.display();



 getch();
}