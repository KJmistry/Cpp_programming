#include <iostream>
using namespace std;

class B;

class A
{
	int private_var_a = 10;

public:
	
	// void print(B&);
	friend void B::print(A&);       				// print not defined !!!
};

class B
{
	int private_var_b = 20;

public:
	
	void print(A&);
	// friend void A::print(B&);
};


void B::print(A& ref)
{
	cout << ref.private_var_a << endl;
}

// void A::print(B& ref)
// {
// 	cout << ref.private_var_b << endl;
// }

int main()
{
	
A a;
B b;
// a.print(b);
b.print(a);
return 0;
}
