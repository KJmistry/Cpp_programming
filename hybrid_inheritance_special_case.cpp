// C++ program demonstrating ambiguity in Multipath Inheritance.

// #define _USING_SCOPE_RESOLUTION
#define _USING_VIRTUAL_BASECLASS

#ifdef _USING_SCOPE_RESOLUTION
#include <iostream>
using namespace std;

class ClassA {
public:
	int a;
};

class ClassB : public ClassA 
{
public:
	int b;
};

class ClassC : public ClassA 
{
public:
	int c;
};

class ClassD : public ClassB, public ClassC 
{
public:
	int d;
};

int main()
{
	ClassD obj;

	// obj.a = 10;				 // Statement 1, Error
	// obj.a = 100;				 // Statement 2, Error

	obj.ClassB::a = 10;         // Statement 3
	obj.ClassC::a = 100;        // Statement 4

	obj.b = 20;
	obj.c = 30;
	obj.d = 40;

	cout << " a from ClassB : " << obj.ClassB::a;
	cout << "\n a from ClassC : " << obj.ClassC::a;

	cout << "\n b : " << obj.b;
	cout << "\n c : " << obj.c;
	cout << "\n d : " << obj.d << '\n';
}

#endif
#ifdef _USING_VIRTUAL_BASECLASS

#include<iostream>
using namespace std;

class ClassA
{
public:
	int a;
};

class ClassB : virtual public ClassA
{
public:
	int b;
};

class ClassC : virtual public ClassA
{
public:
	int c;
};

class ClassD : public ClassB, public ClassC
{
public:
	int d;
};

int main()
{
	ClassD obj;

	obj.a = 10;	                // Statement 3
	// obj.ClassB::a = 100;	    
	// obj.ClassC::a = 900;	    
	obj.a = 100;	            // Statement 4

/* Class-D has only one copy of ClassA, therefore, statement 4 will overwrite the value of a, given in statement 3 */

	obj.b = 20;
	obj.c = 30;
	obj.d = 40;

	cout << "\n a : " << obj.a;
	cout << "\n b : " << obj.b;
	cout << "\n c : " << obj.c;
	cout << "\n d : " << obj.d << '\n';
}

#endif
