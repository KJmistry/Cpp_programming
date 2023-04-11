// CPP Program to demonstrate derived class redefines base class member method and generates compiler error
#include <iostream>
using namespace std;

class Base {
public:
	int fun() { cout << "Base::fun() called"; }
	int fun(int i) { cout << "Base::fun(int i) called"; }
};

class Derived : public Base {
public:
	int fun() { cout << "Derived::fun() called"; }
};

// Driver Code
int main()
{
	Derived d;
	d.fun(5);                   // Compiler Error [fun(int)] __ can be resolved using d.Base::fun(5);
    // d.Base::fun(5);
	return 0;
}
