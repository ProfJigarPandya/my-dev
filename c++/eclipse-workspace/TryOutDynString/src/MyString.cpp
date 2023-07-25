//============================================================================
// Name        : MyString.cpp
// Author      : Jigar Pandya
// Version     :
// Copyright   : Your copyright notice
// Description : String like library on my own way.
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;


class MyString
{
	private:
		char *name;
		int length;
	public:
		MyString()
		{
			cout<<"Default constructor/no-arg constructor/do-nothing constructor invoked ...\n";
			length=0;
			name=new char[length+1];
			*(name+0)=NULL;
		}
		MyString(const char *s)
		{
			cout<<"Parameterized constructor (const char *s) invoked ...\n";
			length=strlen(s);
			name=new char[length+1];
			strcpy(name,s);
		}
		MyString(MyString &str)
		{
			cout<<"Copy constructor invoked \n";
			this->length = str.length;
			//this->name = str.name; This will only do shallow copy

			//To allocate memory and copy over deep way
			this->name = new char[str.length+1];
			strcpy(this->name,str.name);
		}
		MyString(int length, char *name)//Shallow copy constructor. Be cautious about using this.
		{
			cout<<"Parameterized constructor (int length, char*name) invoked \n";
			this->length = length;
			this->name = name;
		}

	int getLength() const {
		return length;
	}

	void setLength(int length) {
		this->length = length;
	}

	char* getName() const {
		return name;
	}

	void setName(char *name) {
		//this->name = name; This will only do shallow copy

		//To allocate memory and copy over deep way
		this->name = new char[length+1];
		strcpy(this->name,name);
	}
	friend ostream& operator<< (ostream &dout, MyString &mstr);
	friend istream & operator >> (istream &din, MyString &mstr);
};
