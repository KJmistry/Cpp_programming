#include <iostream>
using namespace std;

class A
{
public:
	void print()
	{
		cout << "A called" << endl;
	} 
};

class B: public A
{
public:
	void print()
	{
		cout << "B called" << endl;
	} 
};

class C: public B
{
public:
	void print()
	{
		cout << "C called" << endl;
	} 
};

int main()
{
    C obj;                                   
    obj.print();

    /*
      Since C is derived from B which is further derived from A
      C is having 3 copies of print() function
      How it is handling the function call even if function is not virtual
    */

	// A* obj = new C;
	// obj->print();        
}



