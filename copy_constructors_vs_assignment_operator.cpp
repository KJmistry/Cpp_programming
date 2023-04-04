#include<iostream>
using namespace std;

class Test
{
/* Class data members */
public:
int a = 10;
int b = 20;

Test(Test &t) {
	cout << "copy const Called\n";
	}
Test()	 { 	
	cout << "const Called\n";
 }
};

Test fun()
{
	cout << "fun() Called\n";
	Test t;
	return t;
}

int main()
{
	Test t1;
	Test t3 = t1;									// copy constructor is called (also true __ Test t3(t1);__)							
	t1 = t3;										// assignment operator overloaded
	Test t2 = fun();								// Test t; Test t2 = t; [assignment operator is overloaded]
	t1.a = 90;
	cout << t1.a << endl;
	cout << t2.a << endl;
	return 0;
}
