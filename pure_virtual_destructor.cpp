#include <iostream>

// Initialization of base class
class Base {
public:
	virtual ~Base() = 0;                                            // Pure virtual destructor
};
Base::~Base()                                                       // Explicit destructor call
{
	// std::cout << "Pure virtual destructor is called";
}

// Initialization of derived class
class Derived : public Base {
public:
	~Derived() 
    { std::cout << "~Derived() is executed\n"; }
};

int main()
{
	// Calling of derived member function
	Base* b = new Derived();
    // Base* b = new Base();                                           // will give an error (Base is an abstract class)
	delete b;
	return 0;
}
