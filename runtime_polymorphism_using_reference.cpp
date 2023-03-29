#include <iostream>
using namespace std;

class base {
public:
	virtual void show()
	{ // Note the virtual keyword here
		cout << "In base\n";
	}
};

class derived : public base {
public:
	void show() { cout << "In derived\n"; }
};

// Since we pass b as reference, we achieve run time polymorphism here.
void print(base& b) { b.show(); }

int main(void)
{
	base b;
	derived d;
	print(b);
	print(d);
	return 0;
}
