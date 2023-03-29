#include <iostream>
#include<tuple>
using namespace std;

tuple<int, int, int> function(int k)           // using tuple 
{
    return make_tuple(k/4,k/2,k/1);
}

pair< int, int> function_pair(int k)           // using pair 
{
    return make_pair(k/4,k/2);
}

int main()
{   
    int a,b,c;
    tie(a,b,c) = function(8);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    pair(a,b) = function_pair(12);
    cout << a << endl;
    cout << b << endl;
    return 0;
}
