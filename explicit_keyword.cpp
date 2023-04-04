// C++ program to illustrate default
// constructor without 'explicit'
// keyword
#include <iostream>
using namespace std;

class Complex {

private:
	double real;
	double imag;

public:

	// Parameterized constructor
	explicit Complex(double r = 0.0, double i = 0.0) : real(r),imag(i)       // works fine if explicit is not written (allows implicit type conversion to class type)
	{
        cout << "constructor called !" << endl;
	}

	// A method to compare two Complex numbers
	bool operator == (Complex rhs)
	{
		return (real == rhs.real && imag == rhs.imag);
	}
};

// Driver Code
int main()
{
	// a Complex object
	Complex com1(3.0, 0.0);
	if (com1 == Complex(3.0,0.0))                // com1.operator==(3.0) [ use : if (com1 == Complex(3.0)) to resolve error , assigning type explicitly ] 
		cout << "Same" << endl;
	else
		cout << "Not Same" << endl;
	return 0;
}
