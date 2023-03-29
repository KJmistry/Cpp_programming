// C++ code to demonstrate NaN exception
#include <cmath>
#include <iostream>
using namespace std;

// Driver Code
int main()
{
	float a = 2, b = -2;

	// Prints the number (1.41421)
	cout << 2/0 << endl;

	// Prints "nan" exception
	// sqrt(-2) is complex number
	// cout << sqrt(b) << endl;

	return 0;
}
