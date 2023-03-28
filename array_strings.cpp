// C++ program to demonstrate array of strings using string class

#include <iostream>
#include <string>

// Driver code
int main()
{
// Initialize String Array
std::string colour[1];
	//= { "Blue", "Red", "Orange", "Yellow" };
// char a[] = "aaaa";
colour[0]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
colour[1]="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
// for (int i = 0; i < 4; i++)
	std::cout << colour[0] << "\n";
	std::cout << colour[1] << "\n";
	std::cout << sizeof(colour) << "\n";
}       
