#include <iostream>
using namespace std;

int& fun(int a)
{   
    static int x = a;       // wont work if static is removed (tying to access stack address!)
	// cout << &x << endl;
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
