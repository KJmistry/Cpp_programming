#include <iostream>
using namespace std;
class Base
{
public:
	int f(int i)
	{
		cout << "f(int): ";
		return i+3;
	}
};
class Derived : public Base
{
public:
	// int f(int i)
	// {
	// 	cout << "f(int): ";
	// 	return i+3;
	// }
	double f(double d)
	{
		cout << "f(double): ";
		return d+3.3;
	}
};
int main()
{
	Derived* dp = new Derived;
	cout << dp->f(3) << '\n';                                   // if f() is not present in derived then only base f() will be called
	cout << dp->f(3.3) << '\n';                                 // overloading is possible only with in derived class scope
	delete dp;
	return 0;
}
