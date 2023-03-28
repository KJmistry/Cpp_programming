// Tokenizing a string using stringstream
#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	string line = "aaaakaaaaakoooooklllll";
	
	// Vector of string to save tokens
	vector <string> tokens;
	
	// stringstream class check1
	stringstream check1(line);
	
	string intermediate;
	
	// Tokenizing w.r.t. space ' '
	while(getline(check1, intermediate, 'k'))
	{
		tokens.push_back(intermediate);
	}
	
	// Printing the token vector
	for(size_t i = 0; i < tokens.size(); i++)
		cout << tokens[i] << '\n';
}
