// C++ program for function overriding with data members

#include <iostream>
using namespace std;

class Animal {								 // base class declaration.
	public:
	string color = "Black";	
};	

class Dog: public Animal					 // inheriting Animal class.
{	
public:
	string color = "Grey";	
};
//Driver code

int main(void) {
	Animal d= Dog(); //accessing the field by reference variable which refers to derived
	cout<<d.color;	
}
