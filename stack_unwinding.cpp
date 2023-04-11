// CPP Program to demonstrate Stack Unwinding
#include <iostream>
using namespace std;

// A sample function f1() that throws an int exception
void f1()
{
	cout << "\n f1() Start ";
	throw 100;
	cout << "\n f1() End ";
}

// Another sample function f2() that calls f1()
void f2()
{
	cout << "\n f2() Start ";
	f1();
	cout << "\n f2() End ";
}

// Another sample function f3() that calls f2() and handles exception thrown by f1()
void f3()
{
	cout << "\n f3() Start ";
	try {
		f2();
	}
	catch (int i) {
		cout << "\n Caught Exception: " << i;
	}
	cout << "\n f3() End";
}

// Driver Code
int main()
{
	f3();
	return 0;
}

/*  
    EXPLANATION:

    @ When f1() throws exception, its entry is removed from the function call stack, because f1() doesn’t contain exception handler for the thrown exception,
    then next entry in call stack is looked for exception handler.

    @ The next entry is f2(). Since f2() also doesn’t have a handler, its entry is also removed from the function call stack.

    @ The next entry in the function call stack is f3(). Since f3() contains an exception handler, 
      the catch block inside f3() is executed, and finally, the code after the catch block is executed.
*/