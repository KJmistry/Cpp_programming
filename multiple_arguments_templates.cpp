// C++ Program to implement Use of template
#include <iostream>

using namespace std;

template <typename T, typename U> class A {
	T x;
	U y;

public:
	A(T x,U y) : x(x), y(y) 
    {   
        cout << "Constructor Called" << endl; 
        cout << "X = " << x << "Y = " << y << endl; 
    }
};

int main()
{
	A a(10,'A');
	A b(2.0,"String");
	return 0;
}
