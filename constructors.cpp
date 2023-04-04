#include <iostream>

using namespace std;

class A 
{
	int x,y;
public:
	A() : x(10),y(20)                                                   // use of initilizer list [:x(value)]                
	{
		cout << "A called " << endl;
	}
	void print()
	{
		cout << "x , y = " << x << " " << y << endl;
	}
};

int main()
{
    A obj;
    obj.print();
    return 0;
}