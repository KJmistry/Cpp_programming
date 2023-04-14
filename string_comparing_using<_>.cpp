#include <iostream>

using namespace std;

template<typename T>
string equal(T a,T b)
{
	if(a == b)
		return "equal";
	return "not equal";
}

template<typename T>
T _greater(T a,T b)
{
	if(a > b)
		return a;
	return b;
}

int main()
{
	cout << equal("string","string") << endl;	
	cout << equal("ooo","string") << endl;	

	cout << _greater("ooo","string") << endl;	
	cout << _greater("ooo","st") << endl;	

	string str1 = "def";
	string str2 = "defg";

 	cout << (str1 > str2) << endl;						// >/< compare first character if same check next one returns 1/0 based on first difference found!

	return 0;
}
