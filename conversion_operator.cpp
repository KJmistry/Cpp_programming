// C++ Program to Demonstrate the working of conversion operator
/*
@ To compile CODE 1 - use -D__CODE_1 option with g++
@ To compile CODE 2 - use -D__CODE_2 option with g++
*/

// #define 

#ifdef __CODE_1
#include <iostream>
using namespace std;

class Fraction 
{
private:
	int num, den;

public:
	Fraction(int n, int d)
	{
		num = n;
		den = d;
	}

	// Conversion operator: return float value of fraction
	operator float() const
	{
		return float(num) / float(den);
	}
};

int main()
{
	Fraction f(2, 5);
	float val = f;                          //f.operator float()
	cout << val << '\n';
	return 0;
}

#endif

#ifdef __CODE_2
// CPP Program to demonstrate Conversion Operators
#include <cmath>
#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	// Default constructor
	Complex(double r = 0.0, double i = 0.0) : real(r) ,imag(i)
	{

	}

	// magnitude : usual function style
	double mag() { return getMag(); }

	// magnitude : conversion operator
	operator double() { return getMag(); }

private:
	// class helper to get magnitude
	double getMag()
	{
		return sqrt(real * real + imag * imag);
	}
};

int main()
{
	// a Complex object
	Complex com(3.0, 4.0);

	// print magnitude
	cout << com.mag() << endl;
	// same can be done like this
	cout << com << endl;
}

#endif
