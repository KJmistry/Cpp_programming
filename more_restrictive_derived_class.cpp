#include<iostream>
using namespace std;

class Base 
{
public:
	virtual void fun() 
    {
        cout << "From base" << endl;
    }
};

class Derived: public Base 
{
private:
	void fun() 
    {
        cout << "From derived" << endl;
    }
};

int main()
{
    Derived obj;
    // obj.fun();                // Error : fun() is private in Derived class
    
    Derived *dPtr = new Derived;
    // dPtr->fun();              // Error : fun() is private in Derived class [pointer type is Derived]

    Base *bPtr = new Derived;       // Works fine since fun() is public in base and object is created using base class pointer
    bPtr->fun();

    /*
        In the above program, private function “Derived::fun()” is being called through a base class pointer, 
        the program works fine because fun() is public in base class. Access specifiers are checked at compile time and 
        fun() is public in base class. At run time, only the function corresponding to the pointed object is called and 
        access specifier is not checked. So a private function of derived class is being called through a pointer of base class. 
    */

    return 0;
}
