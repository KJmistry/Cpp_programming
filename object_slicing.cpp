#include <iostream>

using namespace std;

class base 
{
public:
    
    int a,b;
    
};

class derived : public base 
{
public:
    int a,b;
};

int main()
{   
    derived objA;
    objA.a = 90;
    objA.base::a = 9;
    objA.b = 80;
    objA.base::b = 8;

    base objB =objA;
    cout << objB.a << endl;
    cout << objB.b << endl;

    return 0;
}

#ifdef _EXAMPLE_2

#include <iostream>
using namespace std;

// Base class
class Base {
protected:
	int i;

public:
	Base(int a) { i = a; }
	virtual void
	display()       // virtual function which is declared in base
			        // class and re-declared in derived class
	{
		cout << "I am Base class object, i = " << i << endl;
	}
};

// Derived class
class Derived : public Base {
	int j;

public:
	Derived(int a, int b)
		: Base(a)
	{
		// assigning the value to the data members of derived class
		j = b;
	}
	virtual void display()
	{
		cout << "I am Derived class object, i = " << i
			<< ", j = " << j << endl;
	}
};

// Global method, Base class object is passed by value
void somefunc(Base obj) { obj.display(); }

int main()
{
	Base b(33);
	Derived d(45, 54);
	somefunc(b);

	// Object Slicing, the member j of d is sliced off
	somefunc(d);
	return 0;
}

#endif