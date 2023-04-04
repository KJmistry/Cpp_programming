// C++ program to demonstrate an explicit call
#include <iostream>
using namespace std;

class Test 
{
public:
	Test() { cout << "Constructor is executed\n"; }
	~Test() { cout << "Destructor is executed\n"; }
};

int main()
{
	Test();     // Explicit call to constructor
	Test t;     // Local object
	t.~Test();  // Explicit call to destructor
	return 0;
}

/*When the constructor is called explicitly the compiler creates a nameless temporary object and it is immediately destroyed.
That’s why 2nd line in the output is printing destructor call.*/