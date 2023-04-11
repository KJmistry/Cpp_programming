// C++ program to demonstrate Run Time Type Identification(RTTI) 

#include <iostream>
using namespace std;

// initialization of base class
class B {
public:
    virtual void fun()						
    {
        cout << "Function Called" << endl;
    }
};

// initialization of derived class
class D : public B {};

// Driver Code
int main()
{
	B* b = new D;                           // Base class pointer
	D* d = dynamic_cast<D*>(b);             // Derived class pointer (will generate an error if we remove virtual function from the base class)
	if (d != NULL)							// to perform safe casting (in cases like blindly casting without knowing object type, this can be 
											// useful by checking NULL pointer.)
		cout << "works" << endl;
	else
		cout << "cannot cast B* to D*" << endl;

    b->fun();
	B* ptr;
	
	// ptr = (D*)d;							// casting without any check [DANGEROUS: wont give error even if object is of diff class]
	
	return 0;
}
