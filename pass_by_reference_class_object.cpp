#include <iostream>

using namespace std;

class Pet {
public:
	virtual string getDescription() const
	{
		return "This is Pet class";
	}
};

class Dog : public Pet {
public:
	virtual string getDescription() const
	{
		return "This is Dog class";
	}
};

void describe(Pet p)                        // void describe(pet& p) [output: This is Dog class]
{ 
	cout << p.getDescription() << '\n';     // Slices the derived class object
}

int main()
{
	Dog d;
	describe(d);                            
	return 0;
}
