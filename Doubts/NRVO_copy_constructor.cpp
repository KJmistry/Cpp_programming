// C++ program to demonstrate the working of copy elision
// via NRVO
#include <iostream>
using namespace std;

class GFG {
public:
    void display()
    {
        cout << "hello" << endl;
    }
	GFG() { cout << "GeeksforGeeks"; }
	GFG(const GFG&) // Copy Construcctor
	{
		cout << " GeeksforGeeks Copy Constructor";
	}
};

GFG func()
{
GFG G;
return G; // NRVO example
}

int main()
{
	GFG G = func();
    // G.display();
	return 0;
}
