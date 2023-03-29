#include <iostream>
using namespace std;

int& fun(int a)
{   
    static int x = a;
	return x;
}

// int fun(int a)
// {   
//     int x = a;
// 	return x;
// }

int main()
{   
    int k;
    int& var = k;
	var = fun(5) = 30;  // prints value 30
	// var = fun(5);       // prints value 5
	cout << var;
	return 0;
}
