/*// C++ program to convert string
// to char array using c_str()
#include <cstring>
#include <string>
#include <iostream>

// driver code
int main()
{
	// assigning value to string s
	std::string s = "kshitij";

	const int length = s.length();

	// declaring character array (+1 for null terminator)
	char* char_array = new char[length + 1];

	// copying the contents of the
	// string to char array
	strcpy(char_array, s.c_str());

	for (int i = 0; i < length; i++)
	{
		std::cout << char_array[i] << ", ";
	}

	delete[] char_array;

	return 0;
}*/

// C++ program to convert string
// to char array Using c_str()
// without strcpy()
#include <cstring>
#include <string>
#include <iostream>

// driver code
int main()
{
	// assigning value to string s
	std::string s = "KSHITIJ";

	// the c_str() function returns a const pointer to null terminated contents.
	const char* str = s.c_str();
	// printing the char array
	for (size_t i = 0; i < s.length(); i++)
	{
		std::cout << str[i] << ", ";
	}
	return 0;
}

