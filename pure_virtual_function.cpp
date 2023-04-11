#include<iostream>
using namespace std;

class Base
{
int x;

public:
	virtual void fun() = 0;
};

class Derived: public Base
{
	int y;

public:
	void fun() { cout << "fun() called"; }
};

int main(void)
{
	// Base b;                  // Error (can not create object of abstract class)
    Derived d;  
	d.fun();

    Base* b = new Derived();    // can have pointers & ref of abstract class
	return 0;
}
