#include <iostream>
using namespace std;

class base 
{
	int a = 10;
public:
	void display()
	{
		cout << a << endl;
	}
};

class derived : public base
{
	int b = 20;
public:
	void fun()
	{
		cout << b << endl;
	}	
};

int main()
{
base* bptr = new derived();
//base* bptr = new base(); 				// generate error !
/*Base class do not have members of derived but derived has*/
bptr->display();
}