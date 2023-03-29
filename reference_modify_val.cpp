// C++ Program to demonstrate Passing of refernces as parameters
#include <iostream>
using namespace std;

// Function having parameters as references
void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

int main()
{
	int a = 2, b = 3;

	swap(a, b);

	//printing both variables
	cout << "a:" << a << " b:" << b;
	return 0;
}
