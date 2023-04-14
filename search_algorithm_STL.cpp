#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	if (binary_search(a, a + 10, 2))
		cout << "Element found in the array" << endl;
	else
		cout << "Element not found in the array" << endl;

	if (binary_search(a, a + 10, 10))
		cout << "Element found in the array" << endl;
	else
		cout << "Element not found in the array" << endl;

	return 0;
}
