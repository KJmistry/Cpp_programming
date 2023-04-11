#include <iostream>
// using namespace std;

int main()
{
	try {
	throw 20;
	}
	catch (int x) {
		std::cout << "Caught ";
	}
	return 0;
}
