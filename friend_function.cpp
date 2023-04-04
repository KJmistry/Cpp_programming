#include <iostream>
using namespace std;

class base;

class A 
{
public:
   void print(base& ref);
};

class base {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	base()
	{
		private_variable = 10;
		protected_variable = 99;
	}
	
	// friend function declaration
	friend void friendFunction(base& obj);
    friend void A::print(base& ref);
};

void A::print(base& ref)                                                                               // need to define after base class defination
{
    cout << "Accessing private member of another class using friend: " << ref.private_variable << endl;
    return;
}
// friend function definition
void friendFunction(base& obj)
{
	cout << "Private Variable: " << obj.private_variable << endl;
	cout << "Protected Variable: " << obj.protected_variable << endl;
}

// driver code
int main()
{
	base object1;
	friendFunction(object1);
    A object2;
    object2.print(object1);

	return 0;
}
