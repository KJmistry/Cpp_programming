// C++ program to demonstrate Operator Overloading or Compile-Time Polymorphism
#define _OPERATOR_OVERLOADING
// #define _USING_FRIEND_FUNC

#ifdef _OPERATOR_OVERLOADING

#include <iostream>
using namespace std;

class Complex 
{
private:
	int real, imag;

public:
	Complex(int r = 0, int i = 0)
	{
		real = r;
		imag = i;
	}

	// This is automatically called when '+' is used with between two Complex objects

	Complex operator ++ (int)
	{	
		real++;
		imag++;
		return;
	}

	void operator ++ ()
	{
		real++;
		imag++;
		return;
	}

	void print()
	{
	    cout << real << " + i" << imag << endl;
	}
};

// Driver code
int main()
{
	Complex c1(10, 5), c2(2, 4);
	++c1;
	c1.print();                  
}
#endif

