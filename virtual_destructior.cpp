#include <iostream>
using namespace std;

class A
{
public:
	virtual void print()
	{
		cout << "A called" << endl;
	}
    virtual ~A()
    {
		cout << "A destructor called" << endl;       
    } 
};

class B: public A
{
public:
	void print()
	{
		cout << "B called" << endl;
	}
    ~B()
    {
		cout << "B destructor called" << endl;       
    }  
};

class C: public B
{
public:
	void print()
	{
		cout << "C called" << endl;
	}
    ~C()
    {
		cout << "C destructor called" << endl;       
    }  
};

int main()
{
    // C obj;
    // obj.print();
	A* obj = new C();
	obj->print();
    delete obj;        
}


/* 

TEST CASES :

@ only A/B/C having virtual print function 
@ both AB/BC/AC having virtual print function
@ all ABC having virtual print function 

@ creating object : A* obj = new A / new B / new C 
@ creating object : B* obj = new B / new C [new A invalid] 
@ creating object : C* obj = new C [new A & new B invalid]

OBSERVATIONS:

@ Making virtual inside A will result into an ideal behaviour

@ If pointer type is A then, print function inside class A must be virtual (creating virtual inside B/C won't have any effect on output)

@ If any class is used as pointer type to create any object and having functions with same name in derived classes (overridden).
  must declare the function inside that class virtual. 
  
*/
