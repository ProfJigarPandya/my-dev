#include <iostream>
#include "MyString.cpp"
#include <string>
#include<cstring>

using namespace std;

ostream & operator << (ostream &dout, MyString &mstr)
{
		dout<<"Length:"<<to_string(mstr.getLength())<<" ";
		dout<<"Name:"<<mstr.getName()<<endl;
		return dout;
}

istream & operator >> (istream &din, MyString &mstr)
{
		//How do I get to know incoming data size?
		//mstr.name=new char(??)
		din>>mstr.name;
		mstr.length = strlen(mstr.name);
		return din;
}


int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

//	//Commonly used string constructors
//	string s1;//Using constructor with no argument, is also called default constructor. If no such constructor is defined, compiler supplies a default constructor.
//	//If we define atleast any one parameterized constructor, we must provide "do-nothing" constructor.
//	cout<<"S1"<<s1<<endl;
//	getchar();friend istream & operator >> (istream &din, MyString &mstr)
//	string s2("xyz");//Using one argument constructor, implicit call
//	//string s2=string("xyz");//Using one argument constructor, explicit call
//	cout<<"S2"<<s2<<endl;
//	getchar();
//	//string s3(s2);//Using copy constructor
//	//string s3=s2;//Using copy constructor
//	string s3=string(s2);//Is there any difference?
//	cout<<"S3"<<s3<<endl;
//	getchar();
//	s1=s2;//Internally supported by C++. Deep copy. like memcopy.
//	cout<<"S1"<<s1<<endl;
//
//	getchar();
//	s3="abc"+s2;
//	cout<<"S3"<<s3<<endl;
//	getchar();
//	cin>>s1;
//	cout<<"S1"<<s1<<endl;
//	getchar();
//	getline(cin,s1);
//	cout<<"S1"<<s1<<endl;
//	getchar();
//	//s3+=s1;
//	//s3+="abc";
//	//cin>>s2;
//	//cout<<s2;
//	//getline(cin,s2);

	//Creating MyString objects
	MyString ms1;
	MyString ms2("New");//Parameterized constructor Implicit call
	MyString ms3=MyString("Delhi");//Parameterized constructor Explicit call

	cout<<ms1<<endl;
	cout<<ms2<<endl;
	cout<<ms3<<endl;

	//Assigning value to string objects
	cout<<"Assigning using assignment operator equal to ...\n";
	ms1=ms2;//mem copy using equal to operator overload c++ parent classes.
	cout<<ms1<<endl;

	cout<<"Assigning using conversion by parameterized constructor.\n";
	ms1="Standard C++";//mem copy using equal to operator overload c++ parent classes.
	cout<<ms1<<endl;

	//Using another object
	MyString ms4(ms1);//copy constructor
	cout<<ms4;

	MyString ms5=ms3;//copy constructor
	cout<<ms5;

	//Reading through keyboard
	MyString ms6;
	cout<<"\n Enter a string \n";
	cin>>ms6;
	cout<<ms6;
	//ms1.setLength(5);
	//ms1.setName("Hello");
	//MyString ms2=MyString("New");
	//MyString ms3=MyString("Delhi");
	cout<<"Finishing now.";
	return 0;
}
