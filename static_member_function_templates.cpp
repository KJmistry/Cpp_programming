#include <iostream>

using namespace std;

template <typename T>
void fun(const T& x)
{
    static int i = 10;
    cout << ++i;
    return;
}

int main()
{	
    fun<int>(1);            // prints 11 (int call) 
    cout << endl;
    fun<int>(2);            // prints 12 (int call)
    cout << endl;
    fun<double>(1.1);       // prints 11 (double call)
    cout << endl;
    fun<int>(1);            // prints 13 (int call)
    cout << endl;
    fun<double>(1.1);       // prints 12 (double call)
    cout << endl;
    return 0;
}

/* 
    Different copy of i for different datatype arguments,
    in above case there are 2 different copies of i exists
*/

