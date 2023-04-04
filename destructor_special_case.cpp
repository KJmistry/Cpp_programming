#include <iostream>
using namespace std;

int i;

class A
{
public:
	~A()
	{
		i=10;
	}
};

int foo()               
{
	i=3;
	A ob;
	return i;           // destructor for the object “ob” is called after the value of i is copied to the return value of the function. 
}

int main()
{
	cout << "i = " << foo() << endl;
	return 0;
}

/* To get last modified value by destructor(i = 10 here), return reference to i or put the "A ob;" with in block { } */
