// CPP Program as an exercise
#include <iostream>
using namespace std;

class Empty {
};

class Derived1 : public Empty {
};

class Derived2 : virtual public Empty {
};

class Derived3 : public Empty {
	char c;
};

class Derived4 : virtual public Empty {
	char c;
};

class Dummy {
	char c;
};

class Derived5 : virtual public Empty {
	double c;
	double a;
	double b;
	double d;
	double f;
};

int main()
{
	cout << "sizeof(Empty) " << sizeof(Empty) << endl;                      // 1
	cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;                // 1
	cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;                // 8   
	cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;                // 1
	cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;                // 16  due to char (member)
	cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;                      // 1
	cout << "sizeof(Derived5) " << sizeof(Derived5) << endl;

	return 0;
}
