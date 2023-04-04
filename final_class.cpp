// Final class cannot be inherited

#include <iostream>
using namespace std;

// The class to be made final
class Final;

// used to make the Final class final
class MakeFinal {
private:
	MakeFinal() { cout << "MakFinal constructor" << endl; }
	friend class Final;
};

class Final : virtual MakeFinal {
public:
	Final() { cout << "Final constructor" << endl; }
};

/* Compiler error : Derived‘s constructor directly invokes MakeFinal’s constructor, and the constructor of MakeFinal is private
class Derived : public Final {
public:
	Derived() { cout << "Derived constructor" << endl; }
};*/

int main(int argc, char* argv[])
{
	Final obj;
	return 0;
}

/* Also we can make class non inheritable by using final specifier (C++ 11), Ex. class A final { }; */