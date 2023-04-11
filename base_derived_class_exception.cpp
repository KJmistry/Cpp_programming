// C++ Program to demonstrate a Catching Base Exception

#include <iostream>
using namespace std;

class Base 
{
};

class Derived : public Base 
{
};

int main()
{
	// Base d;
	Derived d;
	// Some other functionalities
	try {
		// Monitored code
		throw d;
	}


	catch (Derived d) {
		// This 'catch' block is NEVER executed if it is defined after base class catch block
        // Always base class catch block will be executed
		cout << "Caught Derived Exception";
	}
    
    catch (Base b) {
		cout << "Caught Base Exception";
	}

	return 0;
}
