#include <iostream>
using namespace std;

class B;

class A
{
	int private_var_a = 10;

public:
	
	void printB(B&);
	// friend void B::printA(A&);       				// print not defined !!!
};

class B
{
	int private_var_b = 20;

public:
	
	// void printA(A&);
	friend void A::printB(B&);
};


// void B::printA(A& ref)
// {
// 	cout << ref.private_var_a << endl;
// }

void A::printB(B& ref)
{
	cout << ref.private_var_b << endl;
}

int main()
{
	
	A a;
	B b;
	a.printB(b);
	// b.printA(a);
	return 0;
}
