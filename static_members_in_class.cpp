// C++ program to access static data member with explicit definition
#include <iostream>
using namespace std;

class A {
	int x;

public:
	A()
	{
	    cout << "A's constructor called " << endl;
	}
};

class B {
	static A a;

public:
	B()
	{
	    cout << "B's constructor called " << endl;
	}

	static A getA()
	{
	    return a;
	}
};

// Definition of a
A B::a;

// Driver code
int main()
{
    B b1,b2;
    A a = b1.getA();
// A a = B::getA();            // Accessing static member with out creating object of B

return 0;
}
