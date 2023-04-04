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
	Complex(int r = 0,
			int i = 0)
	{
		real = r;
		imag = i;
	}

	// This is automatically called when '+' is used with between two Complex objects

	Complex operator+(Complex const& obj)
	{
		Complex res;
		res.real = real + obj.real;

        // parameters of L obj (wrt +)
        cout << real << endl;
        cout << imag << endl;

        // parameters of R obj (wrt +)
        cout << obj.real << endl;
        cout << obj.imag << endl;

		res.imag = imag + obj.imag;
		return res;
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

	// An example call to "operator+" 
	Complex c3 = c1 + c2;                       //Internally translated as ComplexNumber "c3 = c1.operator+ (c2)";
	c3.print();
}
#endif

#ifdef _USING_FRIEND_FUNC

#include <iostream>
using namespace std;

class Complex 
{
private:
	int real, imag;

public:
	Complex(int r = 0,int i = 0)
	{
		real = r;
		imag = i;
	}

	// This is automatically called when '+' is used with between two Complex objects
    // The global operator function is made friend of this class so that it can access private members

	friend Complex operator+(Complex const& obj1,Complex const& obj2)  
	{
        return Complex(obj1.real + obj2.real, obj1.imag + obj2.imag);       // using constructor
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

	// An example call to "operator+" 
	Complex c3 = c1 + c2;
	c3.print();
}

#endif